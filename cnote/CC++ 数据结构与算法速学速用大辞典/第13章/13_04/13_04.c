#include<stdio.h>
void DectoBin(int num);
void main()
{
	int n;
	printf("请输入一个十进制整数:");
	scanf("%d",&n);
	printf("二进制数是:");
	DectoBin(n);
	printf("\n");
}
void DectoBin(int num)
{
	if(num==0)
		return;
	else
	{
		DectoBin(num/2);
		printf("%d",num%2);
	}
}