#include <stdio.h>
#define ListSize 200
typedef int DataType;
#include ".\head\SeqList.h"

/*
将数组分成两部分 左边全部小于零 右边全部大于零
*/
void SpliteSeqList(SeqList *L);

int main()
{
    int i, flag, n;
    DataType e;
    SeqList L;
    int a[] = {88, -9, -28, 19, -31, 22, -50, 62, -76};
    InitList(&L);
    n = sizeof(a) / sizeof(a[0]);
    for (i = 1; i <= n; i++) //将数组元素插入到顺序表L中
    {
        if (InsertList(&L, i, &a[i - 1]) == 0)
        {
            printf("位置不合法!");
            return -1;
        }
    }

    printf("顺序表L中的元素:\n");
    for (i = 1; i <= L.length; i++)
    {

        flag = GetElem(L, i, &e);
        if (flag == 1)
            printf("%4d", e);
    }
    printf("\n");

    SpliteSeqList(&L);

    printf("顺序表L调整后(左边元素小于等于0，右边元素大于等于0):\n");

    for (i = 1; i <= L.length; i++)
    {

        flag = GetElem(L, i, &e);
        if (flag == 1)
            printf("%4d", e);
    }
    printf("\n");
    return 0;
}

void SpliteSeqList(SeqList *L)
{
    int i ,j;
    i=0;
    j=L->length-1;
    while(i<j)
    {
        while(L->list[i]<=0)
        {
            i++;
        }
        while(L->list[j]>=0)
        {
            j--;
        }
        if(i<j)
        {
            int temp = L->list[i];
            L->list[i] = L->list[j];
            L->list[j] = temp;
        }
    }
}