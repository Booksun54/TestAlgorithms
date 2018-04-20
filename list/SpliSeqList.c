#include <stdio.h>
#define ListSize 200
typedef int DataType;
#include ".\head\SeqList.h"

/*
������ֳ������� ���ȫ��С���� �ұ�ȫ��������
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
    for (i = 1; i <= n; i++) //������Ԫ�ز��뵽˳���L��
    {
        if (InsertList(&L, i, &a[i - 1]) == 0)
        {
            printf("λ�ò��Ϸ�!");
            return -1;
        }
    }

    printf("˳���L�е�Ԫ��:\n");
    for (i = 1; i <= L.length; i++)
    {

        flag = GetElem(L, i, &e);
        if (flag == 1)
            printf("%4d", e);
    }
    printf("\n");

    SpliteSeqList(&L);

    printf("˳���L������(���Ԫ��С�ڵ���0���ұ�Ԫ�ش��ڵ���0):\n");

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