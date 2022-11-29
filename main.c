#include <stdio.h>
#include <stdlib.h>
#include<string.h>


#define OK          1
typedef struct list
{
    int *data;
    int length;
}SSTable;
typedef struct name
{
    char Name[20];
    int empty;//0为空，1为满
}Namearr;

void SQSearch(const SSTable T,int Key);
void BinSearch(const SSTable T,int Key);
int Addname(char S[]);

int main(void)
{
    char s[20];
    Namearr arr[30];//存放名字的hash表
    for(int i=0;i<30;i++)
    {
        arr[i].empty=0;
        for(int j=0;j<20;j++)
            arr[i].Name[j]='\0';
    }
    printf("请输入你要输入的名字个数:\n");
    int num;
    scanf("%d",&num);
    printf("请输入你要输入的名字:\n");
    for(int i=0;i<num;i++)
    {
        scanf("%s",s);
        int n=Addname(s);
        int m=n;
        while(arr[m].empty==1)
        {
            m++;
            m=m%30;
        }
        //arr[m].empty==0
        arr[m].empty=1;//将这格占住
        strcpy(arr[m].Name,s);//将名字赋给该格
    }
    printf("请输入你要查找的名字:\n");
    char Search[20];
    scanf("%s",Search);
    int i;
    for( i=0;i<30;i++)
    {
        int val=strcmp(arr[i].Name,Search);
        if(val==0)
            {
                printf("你要找的名字在第%d位\n",i+1);
                break;
            }

    }
    if(i==30)
        printf("你要找的名字不在这里面哦......\n");

    return 0;
}


void SQSearch(const SSTable T,int Key)
{
    for(int i;i<T.length;i++)
    {
        if(T.data[i]==Key)
        {
            printf("找到了!\n你要找的数据%d在第%d个\n",Key,i+1);
            return OK;
        }
    }
    printf("里面好像没有你要找的%d哦!\n",Key);
    return OK;
}

void BinSearch(const SSTable T,int Key)
{
        int Low=0;int High=T.length-1;
        while(Low<=High)
        {
            int Mid=(Low+High)/2;
            if(T.data[Mid]==Key)
            {
                printf("找到了,你要找的数据%d在第%d个\n",Key,Mid+1);
                return OK;
            }
            else if(Key>T.data[Mid])
            {
                Low=Mid+1;
            }
            else if(Key<T.data[Mid])
            {
                High=Mid-1;
            }
        }
        printf("你要找的%d好像不在这里面哦！\n",Key);
        return OK;
}

int Addname(char S[])
{
    int sum=0;
    int n=strlen(S);
    for(int i=0;i<n;i++)
    {
        sum+=(int)S[i];
    }
    sum=sum%30;
    return sum;
}


    /*
    SSTable L;
    L.length=8;
    for(int i=0;i<L.length;i++)
    {
        L.data=(int*)malloc(L.length*sizeof(int));
    }
    printf("请输入你的数据：\n");
    for(int i=0;i<L.length;i++)
    {
        scanf("%d",&L.data[i]);
    }
    printf("请输入你要查找的数据:\n");
    int Key1,Key2;
    scanf("%d %d",&Key1,&Key2);
    printf("以下是查找%d的顺序查找和二分查找:\n",Key1);
    SQSearch(L,Key1);
    BinSearch(L,Key1);
    printf("以下是查找%d的顺序查找和二分查找:\n",Key2);
    SQSearch(L,Key2);
    BinSearch(L,Key2);
    */
