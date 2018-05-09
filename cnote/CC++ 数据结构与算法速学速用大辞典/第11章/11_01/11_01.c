#include<stdio.h>
#define N 12
void main()
{
	int f[N+1],i;
	f[0]=1;
	f[1]=1;
	for(i=2;i<=N;i++)
		f[i]=f[i-1]+f[i-2];
	for(i=0;i<=N;i++)
		printf("第%d个月的兔子总数为:%d\n",i,f[i]);
}
