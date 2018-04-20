#define DataType int
#define ListSize 100
#include<stdio.h>
typedef struct
{
    DataType list[ListSize];
    int length;
} SeqList;

//初始化线性表
void InitList(SeqList *L)
{
    L->length = 0;
}

//判断线性表是否为空
int ListEmpty(SeqList L)
{
    if (L.length == 0)
        return 1;
    else
        0;
}

//按照序号查找
int GetElem(SeqList L, int i, DataType *e)
{
    if (i<1||i>L.length)
    return -1;

    *e = L.list[i-1];
    return 1;
}

int LocateElem(SeqList L,DataType e)
{
    int i;
    for(i=0;i<L.length;i++)
    {
        if(L.list[i]==e)
        {
            return i+1;
        }
    }
    return 0;
}

int InsertList(SeqList *L,int i , DataType *e)
{
    int j;
     if (i<1||i>L->length+1)
     {
        printf("插入位置i不合法!\n");
        return -1;
     }

     else if(L->length>=ListSize)
     {
         printf("顺序表已满");
         return 0;
     }

     else{
         for(j=L->length;j>=i;j--)
         {
            L->list[j]=L->list[j-1];
         }
         L->list[i-1] = *e;
         L->length++;
         return 1;
     }
   
}

//删除线性表元素
int DeleteList(SeqList *L , int i , DataType *e)
{
    int j;
    if(L->length<=0)
    {
        printf("顺序表已空不能删除!");
        return 0;
    }
    else if(i<1||i>L->length)
    {
         printf("删除位置不合适!");
        return -1;
    }
    else{
        *e=L->list[i-1];
        for(j=i;j<=L->length-1;j++)
        {
            L->list[j-1]=L->list[j];
        }
        L->length--;
        return 1;
    }
}

//求线性表长度
int ListLength(SeqList L)
{
    return L.length;
}

//清空顺序表

void ClearList(SeqList *L)
{
    L->length = 0;
}