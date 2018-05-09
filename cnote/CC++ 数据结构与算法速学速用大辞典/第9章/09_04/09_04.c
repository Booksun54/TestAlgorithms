#include<stdio.h>
void PrintArray(int a[],int n);
void BubbleSort(int a[],int n);
void BubbleSort2(int a[],int n);
void main()
{
	int a[]={56,22,67,32,59,12,89,26,48,37};
	int n=sizeof(a)/sizeof(a[0]);
	printf("冒泡排序前:\n");
	PrintArray(a,n);
	printf("冒泡排序:\n");
	BubbleSort2(a,n);
	PrintArray(a,n);
}
void BubbleSort(int a[],int n)
{
	int i,j,t;
	for(i=1;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
		printf("第%d趟排序结果:",i);
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
void BubbleSort2(int a[],int n)
/*双向冒泡排序，从前后两个方向进行冒泡排序*/
{
	int i,t,flag=1;/*一趟排序后元素是否有交换*/
	int low=0,high=n-1;
	while(low<high && flag)/*当flag为0说明已没有逆序元素*/
	{
		flag=0;/*每趟开始将flag置为0*/
		for(i=low;i<high;i++)/*从前到后进行冒泡排序*/
		{
			if(a[i]>a[i+1])
			{
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
				flag=1;/*有交换*/
			}
		}
		high--;/*更新上界*/
		for(i=high;i>low;i--)/*从后到前进行冒泡排序*/
		{
			if(a[i]<a[i-1])
			{
				t=a[i];
				a[i]=a[i-1];
				a[i-1]=t;
				flag=1;/*有交换*/
			}
		}
		low++;/*更新下界*/
		printf("第%d趟排序结果:",i);
		PrintArray(a,n);
	}
}