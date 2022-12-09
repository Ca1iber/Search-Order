#include <stdio.h>
#include <stdlib.h>
#include<string.h>


#define OK          1
typedef struct sort
{
    int Sorted;
    int NonSorted;
    int *data;
    int Size;

}EZSort;
void EasySort(EZSort S);
void DirectInsert(EZSort S);
void BubbleSort(EZSort S);
void QuickSort(int arr[],int lowFlag,int highFlag);
int Partition(int arr[],int lowf, int highf);
void Swap(int *a,int *b);

int main(void)
{
    EZSort S;
    S.Sorted=0;
    printf("请输入你要排序的个数:\n");
    scanf("%d",&S.Size);
    S.NonSorted=S.Size;
    S.data=(int*)malloc(S.Size*sizeof(int));
    printf("请输入你要排序的数据:\n");
    for(int i=0;i<S.Size;i++)
    {
        scanf("%d",&S.data[i]);
    }

    printf("以下是简单排序的排序过程:\n");
    EasySort(S);
    printf("\n");

/*
    printf("以下是直接插入排序的排序过程:\n");
    DirectInsert(S);
    printf("\n");
*/
/*
    printf("以下是冒泡排序的排序过程:\n");
    BubbleSort(S);
    printf("\n");
*/
/*
    printf("这是经过快速排序之后的数据:\n");
    int arr[S.Size];
    for(int i=0;i<S.Size;i++)
    {
        arr[i]=S.data[i];
    }
    QuickSort(arr,0,S.Size-1);
    int x=S.Size;
    for(int i=0;i<x;i++)
    {
        printf("%d  ",arr[i]);
    }
*/
}


void EasySort(EZSort S)
{
    int swaped=0;
    int ar[S.Size];
    while(S.NonSorted!=0)//当排序尚未完成
    {
        for(int i=S.Sorted;i<S.Size;i++)//遍历未排序的表
        {
            for(int j=S.Sorted;j<S.Size;j++)//找出未排序子表中最小的元素
            {
                if(S.data[j]<S.data[S.Sorted])
                {
                    int temp;
                    temp=S.data[j];
                    S.data[j]=S.data[S.Sorted];
                    S.data[S.Sorted]=temp;
                    swaped=1;
                }
            }
        }
        if(swaped==0)
        {
            printf("已经排好序了，不需要继续了");
            break;
        }
        else
        {
            printf("第%d轮排序\n",S.Sorted+1);
            {
                for(int i=0;i<S.Size;i++)
                    printf("%d  ",S.data[i]);
                    printf("\n");
            }
        }
        swaped=0;
        S.Sorted++;
        S.NonSorted--;
    }
}

void DirectInsert(EZSort S)
{
    for(int i=0;i<S.Size-1;i++)
    {
        int x=S.data[i+1];
        int j=i;
        while((j>-1)&&(x<S.data[i]))
        {
            S.data[j+1]=S.data[j];
            j--;
        }
        S.data[j+1]=x;
    }
    for(int i=0;i<S.Size;i++)
        printf("%d  ",S.data[i]);
}

void BubbleSort(EZSort S)
{
    int swap=0;
    for(int i=0;i<S.Size;i++)
    {
        for(int j=i+1;j<S.Size;j++)
        {
            if(S.data[i]>S.data[j])
            {
                int temp=S.data[i];
                S.data[i]=S.data[j];
                S.data[j]=temp;
                swap=1;
            }
        }
        if(swap==1)
        {
            printf("这是第%d轮排序之后的数据:\n",i+1);
             for(int i=0;i<S.Size;i++)
                printf("%d  ",S.data[i]);
                printf("\n");
                swap=0;
        }
        else
        {
           printf("已经排好序了，不需要继续了");
            break;
        }
    }
}

int Partition(int arr[],int lowf, int highf)
{
    int Key=arr[lowf];
    while(lowf<highf)
    {
        while(lowf<highf&&arr[highf]>=Key)
            highf--;
        Swap(&(arr[lowf]),&arr[highf]);
        while(lowf<highf&&arr[lowf]<=Key)
            lowf++;
        Swap(&(arr[lowf]),&(arr[highf]));
    }
    return lowf;
}

void QuickSort(int arr[],int lowFlag,int highFlag)
{
    int Keynumber;
    if(lowFlag<highFlag)
    {
        Keynumber=Partition(arr,lowFlag,highFlag);
        QuickSort(arr,lowFlag,Keynumber-1);
        QuickSort(arr,Keynumber+1,highFlag);
    }
}

void Swap(int *a,int *b)
{
    int c;
    c=*a;
    *a=*b;
    *b=c;
}
