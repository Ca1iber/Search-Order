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
    printf("��������Ҫ����ĸ���:\n");
    scanf("%d",&S.Size);
    S.NonSorted=S.Size;
    S.data=(int*)malloc(S.Size*sizeof(int));
    printf("��������Ҫ���������:\n");
    for(int i=0;i<S.Size;i++)
    {
        scanf("%d",&S.data[i]);
    }

    printf("�����Ǽ�������������:\n");
    EasySort(S);
    printf("\n");

/*
    printf("������ֱ�Ӳ���������������:\n");
    DirectInsert(S);
    printf("\n");
*/
/*
    printf("������ð��������������:\n");
    BubbleSort(S);
    printf("\n");
*/
/*
    printf("���Ǿ�����������֮�������:\n");
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
    while(S.NonSorted!=0)//��������δ���
    {
        for(int i=S.Sorted;i<S.Size;i++)//����δ����ı�
        {
            for(int j=S.Sorted;j<S.Size;j++)//�ҳ�δ�����ӱ�����С��Ԫ��
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
            printf("�Ѿ��ź����ˣ�����Ҫ������");
            break;
        }
        else
        {
            printf("��%d������\n",S.Sorted+1);
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
            printf("���ǵ�%d������֮�������:\n",i+1);
             for(int i=0;i<S.Size;i++)
                printf("%d  ",S.data[i]);
                printf("\n");
                swap=0;
        }
        else
        {
           printf("�Ѿ��ź����ˣ�����Ҫ������");
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
