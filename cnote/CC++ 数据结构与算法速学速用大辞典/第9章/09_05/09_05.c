#include<stdio.h>
void DispArray(int a[],int n);
void DispArray2(int a[],int n,int pivot,int count);
void QSort(int a[],int n,int low,int high);
void QuickSort(int a[],int n);
int Partition(int a[],int low,int high);
void QSort(int a[],int n,int low,int high)
/*利用快速排序算法对数组a中的元素排序*/
{ 
	int pivot;
	static count=1;
	if(low<high)	  /*如果元素序列的长度大于1*/
	{ 
		pivot=Partition(a,low,high);/*将待排序序列a[low..high]划分为两部分*/
		DispArray2(a,n,pivot,count);	/*输出每次划分的结果*/
		count++;
		QSort(a,n,low,pivot-1); /*对左边的子表进行递归排序，pivot是枢轴位置*/
		QSort(a,n,pivot+1,high);	/*对右边的子表进行递归排序 */
	}
}
void QuickSort(int a[],int n)
/*对数组a进行快速排序*/
{ 
	QSort(a,n,0,n-1);
}
int Partition(int a[],int low,int high)
/*对数组a[low..high]的元素进行一趟排序，使枢轴前面的元素小于枢轴元素，枢轴后面的元素大于等于枢轴元素，并返回枢轴位置*/
{ 
	int t,pivot;
	pivot=a[low];	/*将表的第一个元素作为枢轴元素*/
	t=a[low];
	while(low<high)	/*从表的两端交替地向中间扫描*/
	{ 
		while(low<high&&a[high]>=pivot)/*从表的末端向前扫描*/
			high--;
		if(low<high)	/*将当前high指向的元素保存在low位置*/
		{
			a[low]=a[high];
			low++;
		}
		while(low<high&&a[low]<=pivot)/*从表的始端向后扫描*/
			low++;
		if(low<high)	/*将当前low指向的元素保存在high位置*/
		{
			a[high]=a[low];
			high--;
		}
		a[low]=t;		/*将枢轴元素保存在low的位置*/
	}
	return low;			/*返回枢轴所在位置*/
}
void DispArray2(int a[],int n,int pivot,int count)
/*输出每次划分的结果*/
{
	int i;
	printf("第%d次划分结果:[",count);
	for(i=0;i<pivot;i++)
		printf("%-4d",a[i]);
	printf("]");
	printf("%3d ",a[pivot]);
	printf("[");
	for(i=pivot+1;i<n;i++)
		printf("%-4d",a[i]);
	printf("]");
	printf("\n");
}
void main()
{
	int a[]={37,19,43,22,22,89,26,92};
	int n=sizeof(a)/sizeof(a[0]);
	printf("快速排序前:");
	DispArray(a,n);
	QuickSort(a,n);
	printf("快速排序结果:");
	DispArray(a,n);
}
void DispArray(int a[],int n)
/*输出数组中的元素*/
{
	int i;
	for(i=0;i<n;i++)
		printf("%4d",a[i]);
	printf("\n");
}
