#include<stdio.h>
#include<malloc.h>
void CopyArray(int source[], int dest[],int len,int first);
void MergeSort(int a[],int left,int right);
void Merge(int a[],int left,int right);
void DispArray(int a[],int n);
void main()   
{   
    int a[] = {49,23,66,52,34,75,99,18};   
    int len = sizeof(a)/sizeof(int);  
	printf("排序前数组中的元素:\n");
    DispArray(a,len);   
    MergeSort(a,0,len-1); 
	printf("排序后数组中的元素:\n");
    DispArray(a,len);     
} 
void MergeSort(int a[],int left,int right)  
/*归并排序*/ 
{   
    int i;     
    if(left < right)   
    {   
        i = (left+right)/2;   
        MergeSort(a,left,i);   
        MergeSort(a,i+1,right);   
        Merge(a,left,right);   
    }   
}    
void Merge(int a[],int left,int right) 
/*合并两个子序列中的元素*/   
{   
    int begin1,begin2,mid,k=0,len,*b;
	begin1= left;   
    mid = (left+right)/2 ;   
    begin2 = mid+1;   
    len = right-left+1;   
    b = (int*)malloc(len*sizeof(int));   
    while(begin1<=mid && begin2<=right)   
    {   
        if(a[begin1]<=a[begin2])   
            b[k++] = a[begin1++];   
        else  
            b[k++] = a[begin2++];   
    }   
    while(begin1<=mid)   
        b[k++] = a[begin1++];   
    while(begin2<=right)   
        b[k++] = a[begin2++];   
    CopyArray(b,a,len,left);   
    free(b);   
}   
void CopyArray(int source[], int dest[],int len,int start)  
/*将source数组中的元素复制到dest数组中.
其中,len是源数组长度,start是目标数组起始位置*/   
{   
    int i,j=start;   
    for(i=0;i<len;i++)   
    {   
        dest[j] = source[i];   
        j++;   
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

