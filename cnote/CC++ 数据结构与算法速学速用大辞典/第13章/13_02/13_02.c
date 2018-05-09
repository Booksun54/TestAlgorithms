#include<stdio.h>
int fib(int n);
void main()
{
	int n;
	printf("请输入项数:");
	scanf("%d",&n);
	printf("第%d项的值:%d\n",n,fib(n));
}
int fib(int n)
{ 
	if (n==0) 
		return 0;
	if (n==1) 
		return 1; 
	if (n>1) 
		return fib(n-1)+fib(n-2);
}
