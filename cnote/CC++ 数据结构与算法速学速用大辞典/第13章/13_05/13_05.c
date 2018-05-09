#include<stdio.h>
int gcd(int m,int n);
void main()
{
	int m,n;
	printf("请输入两个正整数:");
	scanf("%d,%d",&m,&n);
	printf("最大公约数是:%d\n",gcd(m,n));
}
int gcd(int m,int n)
{
	if(m>n)
		return gcd(m-n,n);
	else if(m<n)
		return gcd(m,n-m);
	else
		return m;
}