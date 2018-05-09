#include<stdio.h>
#include<math.h>
#define N 8
void main()
{
	int a[N+1],b[N+1],i,k=0,value;
	float x;
	double ipart;
	for(i=0;i<=N;i++)
		b[i]=0;
	printf("请输入一个十进制小数:");
	scanf("%f",&x);
	x=modf(x,&ipart);
	value=(int)ipart;
	while(value)
	{
		b[k++]=value%2;
		value/=2;
	}
	for(i=1;i<=N;i++)
	{
		x*=2;
		if(x>=1.0)
		{
			x-=1;
			a[i]=1;
		}
		else
			a[i]=0;
	}
	printf("二进制数:");
	for(i=k;i>=0;i--)
		printf("%d",b[i]);
	printf(".");
	for(i=1;i<=N;i++)
	{
		if(a[i]==0)
			printf("0");
		else
			printf("1");
	}
	printf("\n");
}