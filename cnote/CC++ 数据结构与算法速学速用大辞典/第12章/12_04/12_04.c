#include<stdio.h>
void main()
{
	int n;
	printf("请输入一个正整数:");
	scanf("%d",&n);
	printf("角谷猜想过程中的每一个数:\n%d",n);
	while(n!=1)
	{
		if(n%2==0)
		{
			n/=2;
			printf("->%d",n);
		}
		else
		{
			n=n*3+1;
			printf("->%d",n);
		}
	}
	printf("\n");
}
