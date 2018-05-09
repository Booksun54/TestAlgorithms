#include<stdio.h>
void ShellSort(int a[],int length,int delta[],int m);
void ShellInsert(int a[],int length,int c);
void DispArray(int a[],int length);
void main()
{
	int a[]={55,72,31,24,86,16,37,8};
	int delta[]={4,2,1},m=3,n;
	n=sizeof(a)/sizeof(a[0]);
	printf("希尔排序前:\n");
	DispArray(a,n);
	ShellSort(a,n,delta,m);
	printf("希尔排序结果:");
	DispArray(a,n);
}
void ShellInsert(int a[],int length,int c)
/*对数组中的元素进行一趟希尔排序，c是增量*/
{
	int i,j,t;
	for(i=c;i<length;i++)				/*将距离为c的元素作为一个子序列进行排序*/
	{
		if(a[i]<a[i-c])				/*如果后者小于前者，则需要移动元素*/
		{
			t=a[i];
			for(j=i-c;j>=0&&t<a[j];j=j-c)
				a[j+c]=a[j];
			a[j+c]=t;				/*依次将元素插入到正确的位置*/
		}
	}
}
void ShellSort(int a[],int length,int delta[],int m)
/*希尔排序，每次调用算法ShellInsert,delta是存放增量的数组*/
{
	int i;
	for(i=0;i<m;i++)			/*进行m次希尔插入排序*/
	{
		ShellInsert(a,length,delta[i]);
		printf("第%d趟排序结果:",i+1);
		DispArray(a,length);
	}
}
void DispArray(int a[],int length)
/*输出数组a中的元素*/
{
	int i;
	for(i=0;i<length;i++)
		printf("%4d",a[i]);
	printf("\n");
}
