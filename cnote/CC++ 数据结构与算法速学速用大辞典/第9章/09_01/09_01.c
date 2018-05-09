#include<stdio.h>
void PrintArray(int a[],int n);
void main()
{
	int a[]={17,46,32,87,58,9,50,38};
	int t,i,j,n;
	n=sizeof(a)/sizeof(a[0]);
	printf("直接插入排序前:\n");
	PrintArray(a,n);
	printf("直接插入排序:\n");
	for(i=1;i<n;i++)
	{
		t=a[i];
		for(j=i-1;j>=0&&t<a[j];j--)
			a[j+1]=a[j];
		a[j+1]=t;
		PrintArray(a,n);
	}	
}
void PrintArray(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%4d",a[i]);
	printf("\n");
	}