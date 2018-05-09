#include<stdio.h>
#define N 60
int exchage(float n,float *a,int c,float *r);
void main()
{
	float rmb[]={100,50,20,10,5,2,1,0.5,0.2,0.1};
	int n=sizeof(rmb)/sizeof(rmb[0]),k,i;
	float change,r[N];;
	printf("请输入要找的零钱数:");
	scanf("%f",&change);
	for(i=0;i<n;i++)
		if(change>=rmb[i])
			break;
		k=exchage(change,&rmb[i],n-i,r);
		if(k<=0)
			printf("找不开!\n");
		else
		{
			printf("找零钱的方案:%.2f=",change);
			if(r[0]>=1.0)
				printf("%.0f",r[0]);
			else
				printf("%.2f",r[0]);
			for(i=1;i<k;i++)
			{
				if(r[i]>=1.0)
					printf("+%.0f",r[i]);
				else
					printf("+%.2f",r[i]);
			}
			printf("\n");
		}
}
int exchage(float n,float *a,int c,float *r)
{
	int m;
	if(n==0.0)				/*能分解，分解完成*/
		return 0;
	if(c==0)				/*不能分解*/
		return -1;
	if(n<*a)
		return exchage(n,a+1,c-1,r);	/*继续寻找合适的面值*/
	else
	{
		*r=*a;					/*将零钱保存到r中*/
		m=exchage(n-*a,a,c,r+1);		/*继续分解剩下的零钱*/
		if(m>=0)
			return m+1;			/*返回找零的零钱张数*/
		return -1;
	}
}
