#include<stdio.h>
#define N 50
void rd(int a[],int i,int k);
void main()
{
	int n,a[N];
	printf("请输入一个正整数n(0<=n<50):");
	scanf("%d",&n);
	a[0]=n;
	printf("和式分解结果:\n");
	rd(a,n,1);
}
void rd(int a[],int i,int k)
{
	int j,p;
	for(j=i;j>=1;j--)
	{
		if(j<=a[k-1])
		{
			a[k]=j;
			if(j==i)
			{
				printf("%d=%d",a[0],a[1]);
				for(p=2;p<=k;p++)
					printf("+%d",a[p]);
				printf("\n");
			}
			else
				rd(a,i-j,k+1);
		}
	}
}