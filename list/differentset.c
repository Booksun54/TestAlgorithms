#include <stdio.h>
#define Listsize 200
typedef int DataType;
#include ".\head\SeqList.h"

/*
删除A中出现的B中的元素
*/
void DelElem(SeqList *A, SeqList B);

int main()
{
    int i, j, flag;
    DataType e;
    SeqList LA, LB;
    InitList(&LA);
    InitList(&LB);
    for (i = 1; i <= 10; i++)
    {
        int a = 10 + i * 2;
        if (InsertList(&LA, i, &a) == 0)
        {
            printf("位置不合法！");
            return -1;
        }
    }
    for (i = 1,j=10; i <= 8;j=j+2,i++)
    {
        int a = j+i*2;
        if (InsertList(&LB,i, &a) == 0)
        {
            printf("位置不合法！");
            return -1;
        }
    }
    printf("顺序表中LA中的元素:\n");
    for (i = 1; i < LA.length; i++)
    {
        flag = GetElem(LA, i, &e);
        if (flag == 1)
        {
            printf("%4d", e);
        }
    }
    printf("\n");

    printf("顺序表中LB中的元素:\n");
    for (i = 1; i <= LB.length; i++)
    {
        flag = GetElem(LB, i, &e);
        if (flag == 1)
        {
            printf("%4d", e);
        }
    }
    printf("\n");

    printf("将在A中出现的B的元素删除后，A中的元素(A-B)：\n");
    DelElem(&LA,LB);
       for(i=1;i<=LA.length;i++)
     {
          flag=GetElem(LA,i,&e);
        if(flag==1)
        {
            printf("%4d",e);
        }
     }
      printf("\n");
}

void DelElem(SeqList *A, SeqList B)
{
    int i,pos,flag;
    DataType e;
    for(i=1;i<=B.length;i++)
    {
        flag = GetElem(B,i,&e);
        if(flag = 1)
        {
            pos = LocateElem(*A,e);
            if(pos > 0)
                DeleteList(A,pos,&e);
        }
    }
}
