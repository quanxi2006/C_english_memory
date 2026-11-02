#include<stdio.h>
#include<string.h>
struct Word
{
        char english[32];
        char chinese[64];
};
struct Word list[100];//全局变量
int count=0;
//打开文件读取数据
void load_from_file()
{
	
   	FILE *fp=fopen("word.txt","r");
	if(fp==NULL)
	{
		printf("文件未打开\n");
		return;
	}
	char buf[128];
	while(fgets(buf,sizeof(buf),fp)!=NULL)
	{
		int len=strlen(buf);
		if(len>0&&buf[len-1]=='\n')
		{
			buf[len-1]='\0';
		}
		char *p=strchr(buf,'|');
		if(p)
		{
			*p='\0';
		
		

			//把文件单词存入List
			strcpy(list[count].english,buf);
			strcpy(list[count].chinese,p+1);
			count++;
		}


	}
	printf("已读取%d个单词\n",count);
	//关闭文件
	fclose(fp);
	return;


}
//把输入数据存入文件
void save_to_file()
{
	FILE *fp=fopen("word.txt","w");
	if(fp==NULL)
	{
		printf("保存失败\n");
		return;
	}
	
	for(int i=0;i<count;i++)
	{
		fprintf(fp,"%s|%s\n",list[i].english,list[i].chinese);
	}
	fclose(fp);
	printf("数据已经安全保存到word.txt\n");
	return;
}

int main()
{
    //printf("Hello World\n");
    //struct Word list[100];    
    //int count =0;
    printf("欢迎使用纯内存单词本! \n");
    load_from_file();
    while(1)
    {
        char buf[64];
        printf("\n请输入英文单词 (直接回车退出):");
        //如果直接输入回车这时候buf长度是1
        fgets(buf,sizeof(buf),stdin);
        int len=strlen(buf);
        if(len>0&&buf[len-1]=='\n')
        {
            buf[len-1]='\0';//直接回车进入这里后buf长度变成0,因为strlen(buf)是计算'\0'之前的长度,所以buf长度变成0
        }
        if(strlen(buf)==0)
        {
            break;//所以这里是退出循环的条件,也就是直接回车退出
        }
        strcpy(list[count].english,buf);
        printf("请输入中文释义: ");
        fgets(buf,sizeof(buf),stdin);
        len=strlen(buf);
        if(len>0&&buf[len-1]=='\n')
        {

            buf[len-1]='\0';

        }
        strcpy(list[count].chinese,buf);
        count++;        

    }
    printf("\n======已经输入的单词======\n");
    for(int i=0;i<count;i++)
    {
        printf("%d.%s--%s\n",i+1,list[i].english,list[i].chinese);

    }
    save_to_file();
    return 0;
}
