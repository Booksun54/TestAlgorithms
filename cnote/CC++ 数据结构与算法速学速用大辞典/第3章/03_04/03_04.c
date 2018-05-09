#include<stdio.h>
#include<malloc.h>
typedef int DataType;			
#define MaxSize 100
#include "LinkQueue.h"
void PrintArray(int a[],int n,int N);
void YangHuiTriangle(int N);
void main()
{
	int n;
	printf("请输入要打印的行数：n=:");
	scanf("%d",&n);	
	YangHuiTriangle(n);	
}
void YangHuiTriangle(int N)
/*链式队列实现打印杨辉三角*/
{ 
	int i,k,n;
	DataType e,t;
	int temp[MaxSize];				/*定义一个临时数组，用于存放每一行的元素*/
	LinkQueue Q;
	k=0;
	InitQueue(&Q);					/*初始化链队列*/
	EnQueue(&Q,1);				/*第一行元素入队*/
	for(n=2;n<=N;n++)				/*产生第n行元素并入队，同时将第n-1行的元素保存在临时数组中*/
	{
		k=0;
		EnQueue(&Q,1);			/*第n行的第一个元素入队*/
		for(i=1;i<=n-2;i++)			/*利用队列中第n-1行元素产生第i行的中间n-2个元素并入队列*/
		{
			DeQueue(&Q,&t);
			temp[k++]=t;			/*将第n-1行的元素存入临时数组*/
			GetHead(Q,&e);		/*取队头元素*/
			t=t+e;				/*利用队中第n-1行元素产生第i行元素*/
			EnQueue(&Q,t);  
		}
		DeQueue (&Q,&t);
		temp[k++]=t;				/*将第n-1行的最后一个元素存入临时数组*/
		PrintArray(temp,k,N);	
		EnQueue(&Q,1);			/*第n行的最后一个元素入队*/
	}
	k=0;							/*将最后一行元素存入数组之前，要将下标k置为0*/
	while(!QueueEmpty(Q))			/*将最后一行元素存入临时数组*/
	{
		DeQueue(&Q,&t);
		temp[k++]=t;
		if(QueueEmpty(Q))
			PrintArray(temp,k,N);
	}	
}
void PrintArray(int a[],int n,int N)
/*打印数组中的元素，使能够呈正确的形式输出*/
{
	int i;
	static count=0;					/*记录输出的行*/
	for(i=0;i<N-count;i++)			/*打印空格*/
		printf("   ");
	count++;
	for(i=0;i<n;i++)					/*打印数组中的元素*/
		printf("%6d",a[i]);
	printf("\n");
}