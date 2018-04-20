#include<stdio.h>
#define Listsize 200
typedef int DataType;
#include ".\head\SeqList.h"

/*
将LB中不在LA中的元素插入到LA中
*/
void UnionAB(SeqList *LA,SeqList LB);

int main()
{
    int i , flag;
    DataType e;
    DataType a[] = {81,32,61,12,39,25};
    DataType b[] = {12,44,39,16,28,6,61,76};
    SeqList LA,LB;
    InitList(&LA);
    InitList(&LB);
    for(i=0;i<sizeof(a)/sizeof(a[0]);i++)
    {
        if(InsertList(&LA,i+1,&a[i])==0)
        {
            printf("位置不合法！");
            return -1;
        }
    }
      for(i=0;i<sizeof(b)/sizeof(b[0]);i++)
    {
        if(InsertList(&LB,i+1,&b[i])==0)
        {
            printf("位置不合法！");
            return -1;
        }
    }
    printf("顺序表中LA中的元素:\n");
    for(i=1;i<LA.length;i++)
    {
        flag=GetElem(LA,i,&e);
        if(flag==1)
        {
            printf("%4d",e);
        }
    }
    printf("\n");
   
     printf("顺序表中LB中的元素:\n");
     for(i=1;i<=LB.length;i++)
     {
          flag=GetElem(LB,i,&e);
        if(flag==1)
        {
            printf("%4d",e);
        }
     }
      printf("\n");

      printf("将LB中但不在LA中的元素插入到LA中：\n");
      UnionAB(&LA,LB);

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

void UnionAB(SeqList *LA,SeqList LB)
{
    int i ,flag,pos;
    DataType e;
    for(i=1;i<=LB.length;i++)
    {
        flag = GetElem(LB,i,&e);
        if(flag==1)
        {
            pos = LocateElem(*LA,e);
            if(!pos)
            {
                InsertList(LA,LA->length+1,&e);
            }
        }
    }
}
