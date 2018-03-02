#include<stdio.h>
#include<stdlib.h>

int IsLeapYear(int year)
{
    return (year%100!=0&&year%4==0)||(year%400==0);
}

int main()
{
    int year = 0;
    printf("请输入需要查询的年份:");
    scanf("%d",&year);
    int check = IsLeapYear(year);
    if(check==0)
        printf("%d不是润年\n",year);
    else
        printf("%d是闰年\n",year);
    system("pause");
    return 0;
}