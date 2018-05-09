#include<stdio.h>
void SelectSort(int a[],int n);
void DispArray(int a[],int n);
void main()
{
	int a[]={65,32,71,28,83,7,53,49};
	int n=sizeof(a)/sizeof(a[0]);
	printf("排序前:\n");
	DispArray(a,n);
	SelectSort(a,n);
	printf("最终排序结果:");
	DispArray(a,n);
}
void SelectSort(int a[],int n)
/*简单选择排序*/
{
	int i,j,k,t;
	/*将第i个元素与第i+1...n个元素比较，将最小的的元素放在第i个位置*/
	for(i=0;i<n-1;i++)
	{
		j=i;
		for(k=i+1;k<n;k++)	/*最小的元素的序号为j*/
			if(a[k]<a[j])
				j=k;
			if(j!=i)			/*如果序号i不等于j，则需要将序号i和序号j的元素交换*/
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
			printf("第%d趟排序结果:",i+1);
			DispArray(a,n);
	}
}
void DispArray(int a[],int n)
/*输出数组中的元素*/
{
	int i;
	for(i=0;i<n;i++)
		printf("%4d",a[i]);
	printf("\n");
}
