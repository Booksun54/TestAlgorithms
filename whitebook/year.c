#include<stdio.h>
#include<stdlib.h>

int IsLeapYear(int year)
{
    return (year%100!=0&&year%4==0)||(year%400==0);
}

int main()
{
    int year = 0;
    printf("��������Ҫ��ѯ�����:");
    scanf("%d",&year);
    int check = IsLeapYear(year);
    if(check==0)
        printf("%d��������\n",year);
    else
        printf("%d������\n",year);
    system("pause");
    return 0;
}