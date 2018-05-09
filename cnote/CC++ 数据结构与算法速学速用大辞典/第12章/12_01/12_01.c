#include<stdio.h>
void main()
{
	int m,n,m1,n1,r;
	printf("请输入两个正整数:");
	scanf("%d,%d",&m,&n);
	m1=m;
	n1=n;
	r=m%n;
	while(r!=0)
	{
		m=n;
		n=r;
		r=m%n;
	}
	printf("%d和%d的最大公约数是%d.\n",m1,n1,n);
	printf("%d和%d的最小公倍数是%d.\n",m1,n1,m1*n1/n);
}