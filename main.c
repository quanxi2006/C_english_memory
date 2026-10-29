#include<stdio.h>
#include<string.h>
struct Word
{
        char english[32];
        char chinese[64];
};


int main()
{
    //printf("Hello World\n");
    struct Word list[100];    
    int count =0;
    printf("欢迎使用纯内存单词本! \n");

    while(1)
    {
        char buf[64];
        printf("\n请输入英文单词 (直接回车退出):");
        fgets(buf,sizeof(buf),stdin);
        int len=strlen(buf);
        if(len>0&&buf[len-1]=='\n')
        {
            buf[len-1]='\0';
        }
        if(strlen(buf)==0)
        {
            break;
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

    return 0;
}