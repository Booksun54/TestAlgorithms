#include<stdio.h>
int findmax(int a[],int n);
void main()
{
	int a[]={55,33,22,77,99,88,11,44},n,i;
	n=sizeof(a)/sizeof(a[0]);
	printf("数组中的元素:");
	for(i=0;i<n;i++)
		printf("%4d",a[i]);
	printf("\n最大的元素:%d\n",findmax(a,n));
}
int findmax(int a[],int n)
{
	int m;
	if(n<=1)
		return a[0];
	else
	{
		m=findmax(a,n-1);
		return a[n-1]>=m?a[n-1]:m;
	}
}