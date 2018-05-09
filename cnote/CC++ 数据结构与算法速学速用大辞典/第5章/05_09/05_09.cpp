#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
#include<iostream.h>
#include<iomanip.h>
typedef int DataType;
#include"TriSeqMatrix.h"
int AddMatrix(TriSeqMatrix A,TriSeqMatrix B,TriSeqMatrix *C);
void PrintMatrix(TriSeqMatrix M);
void PrintMatrix2(TriSeqMatrix M);
int CreateMatrix(TriSeqMatrix *M); 
int CompareElement(int a,int b);
void main()
{
	TriSeqMatrix M,N,Q;
	CreateMatrix(&M);
	PrintMatrix2(M);
	CreateMatrix(&N);
	PrintMatrix2(N);
	AddMatrix(M,N,&Q);
	PrintMatrix(Q);
	PrintMatrix2(Q);	
}
void PrintMatrix(TriSeqMatrix M)
/*输出稀疏矩阵*/
{ 
	int i;
	cout<<"稀疏矩阵是"<<M.m<<"行×"<<M.n<<"列，共"<<M.len<<"个非零元素"<<endl;
	cout<<"行    列    元素值"<<endl;
	for(i=0;i<M.len;i++)
		cout<<setw(2)<<M.data[i].i<<setw(6)<<M.data[i].j<<setw(8)<<M.data[i].e<<endl;
}
void PrintMatrix2(TriSeqMatrix M)
/*按矩阵样式输出稀疏矩阵*/
{ 
	int k,i,j;
	DataType a[MaxSize][MaxSize];
	for(i=0;i<M.m;i++)//初始化数组a，全部元素置为0
		for(j=0;j<M.n;j++)
			a[i][j]=0;
	for(k=0;k<M.len;k++)//将非0元素存入数组a
	{
		if(M.data[k].e!=0)
		{
			i=M.data[k].i;
			j=M.data[k].j;
			a[i][j]=M.data[k].e;
		}
	}
	cout<<"稀疏矩阵(按矩阵形式输出):"<<endl;
	for(i=0;i<M.m;i++)//按矩阵形式输出数组a中的元素
	{
		for(j=0;j<M.n;j++)
			cout<<setw(4)<<a[i][j];
		cout<<endl;
	}
}
int AddMatrix(TriSeqMatrix A,TriSeqMatrix B,TriSeqMatrix *C)
/*将两个矩阵A和B对应的元素值相加，得到另一个稀疏矩阵C*/
{
	int m=0,n=0,k=-1;
	if(A.m!=B.m||A.n!=B.n) /*如果两个矩阵的行数与列数不相等，则不能够进行相加运算*/
		return 0;
	C->m=A.m;
	C->n=A.n;
	while(m<A.len&&n<B.len) 
	{
		switch(CompareElement(A.data[m].i,B.data[n].i))/*比较两个矩阵对应元素的行号*/
		{
		case -1: 
			C->data[++k]=A.data[m++];	/*将矩阵A，即行号小的元素赋值给C*/
			break;
		case  0:
			/*如果矩阵A和B的行号相等，则比较列号*/
			switch(CompareElement(A.data[m].j,B.data[n].j)) 
			{
			case -1:					/*如果A的列号小于B的列号，则将矩阵A的元素赋值给C*/
				C->data[++k]=A.data[m++];
				break;
			case  0:					/*如果A和B的行号、列号均相等，则将两元素相加，存入C*/
				C->data[++k]=A.data[m++]; 
				C->data[k].e+=B.data[n++].e; 
				if(C->data[k].e==0)		/*如果两个元素的和为0，则不保存*/
					k--;
				break;
			case  1:					/*如果A的列号大于B的列号，则将矩阵B的元素赋值给C*/
				C->data[++k]=B.data[n++];
			}
			break;
			case  1:						/*如果A的行号大于B的行号，则将矩阵B的元素赋值给C*/
				C->data[++k]=B.data[n++]; 
		}
	}
	while(m<A.len)						/*如果矩阵A的元素还没处理完毕，则将A中的元素赋值给C*/
		C->data[++k]=A.data[m++];
	while(n<B.len)						/*如果矩阵B的元素还没处理完毕，则将B中的元素赋值给C*/
		C->data[++k]=B.data[n++];
	C->len=k+1;							/*修改非零元素的个数*/
	if(k>MaxSize)						
		return 0;
	return 1;
}
int CompareElement(int a,int b)
/*比较两个矩阵的元素值大小。前者小于后者，返回-1；相等，返回0；大于，返回1*/
{ 
	if(a<b)
		return -1;
	if(a==b)
		return 0;
	return 1;
}