#include<stdio.h>
long int Fact(int n);
void main()
{
	int n;
	printf("请输入一个整数:");
	scanf("%d",&n);
	printf("%d!=%d\n",n,Fact(n));
}
long int Fact(int n)
{	
	int x;
	long int y;	
	if(n < 0)                  	/*n<0时阶乘无定义*/
	{
		printf("参数错!");
		return -1;	    
	}
	if(n == 0)					/*n==0时阶乘为1*/
		return 1;
	else  
	{
		return n*Fact(n - 1);		/*递归求n的阶乘*/
	}
}
