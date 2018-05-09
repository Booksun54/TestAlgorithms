#include<stdio.h>
void DispArray(int a[],int n);
void AdjustHeap(int a[],int s,int m);
void CreateHeap(int a[],int n);
void HeapSort(int a[],int n);
void main()
{
	int a[]={67,48,23,81,38,19,52,40};
	int n=sizeof(a)/sizeof(a[0]);
	printf("排序前:");
	DispArray(a,n);
	HeapSort(a,n);
	printf("堆排序结果:");
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
void CreateHeap(int a[],int n)
/*建立大顶堆*/
{
	int i;
	for(i=n/2-1;i>=0;i--)	/*从序号n/2-1开始建立大顶堆*/
		AdjustHeap(a,i,n-1);
}
void AdjustHeap(int a[],int s,int m)
/*调整a[s...m]，使其成为一个大顶堆*/
{ 
	int t,j;
	t=a[s];								/*将根结点暂时保存在t中*/
	for(j=2*s+1;j<=m;j*=2+1)
	{ 
		if(j<m&&a[j]<a[j+1])			/*沿关键字较大的孩子结点向下筛选*/
			j++;						/*j为关键字较大的结点的下标*/
		if(t>a[j])						/*如果孩子结点的值小于根结点的值，则不进行交换*/
			break;
		a[s]=a[j];
		s=j;
	}
	a[s]=t;								/*将根结点插入到正确位置*/
}
void HeapSort(int a[],int n)
/*利用堆排序算法对数组a中的元素进行排序*/
{ 
	int t,i;
	CreateHeap(a,n);		/*创建堆*/
	for(i=n-1;i>0;i--)		/*将堆顶元素与最后一个元素交换，重新调整堆*/
	{ 
		t=a[0];
		a[0]=a[i];
		a[i]=t;
		printf("第%d趟排序结果:",n-i);
		DispArray(a,n);
		AdjustHeap(a,0,i-1);		/*将a[0..i-1]调整为大顶堆*/
	}
}

