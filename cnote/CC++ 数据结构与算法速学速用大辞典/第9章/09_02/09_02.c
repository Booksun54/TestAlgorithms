#include<stdio.h>
void PrintArray(int a[],int n);
void main()
{
	int a[]={75,61,82,36,99,26,41};
	int t,i,j,low,high,mid,n;
	n=sizeof(a)/sizeof(a[0]);
	printf("’€∞Î≤Â»Î≈≈–Ú«∞:\n");
	PrintArray(a,n);
	printf("’€∞Î≤Â»Î≈≈–Ú:\n");
	for(i=1;i<n;i++)
	{
		t=a[i];
		for(low=0,high=i-1;high>=low;)
		{
			mid=(low+high)/2;
			if(t<a[mid])
				high=mid-1;
			else
				low=mid+1;
		}
		for(j=i-1;j>=low;j--)
			a[j+1]=a[j];
		a[low]=t;
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