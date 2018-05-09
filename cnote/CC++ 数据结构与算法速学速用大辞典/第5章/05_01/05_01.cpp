#include<iostream.h>
#include<iomanip.h>
#define MAX 200
void CreateArray(int a[][MAX],int n);
void PrintArray(int a[MAX][MAX],int n);
void Trans(int b[],int c[],int n);
int PriorRow(int a[][MAX],int n,int b[]);
void main()
{
	int a[MAX][MAX],b[MAX],c[MAX],n,m,i;
	cout<<"请输入一个整数（<100）:"<<endl;
	cin>>n;
	CreateArray(a,n);
	cout<<"二维数组为:"<<endl;
	PrintArray(a,n);	
	m=PriorRow(a,n,b);
	cout<<"数组b中的元素:"<<endl;
	for(i=0;i<m;i++)
		cout<<setw(4)<<b[i];
	cout<<endl;
	Trans(b,c,n);
	cout<<"数组c中的元素:"<<endl;
	for(i=0;i<m;i++)
		cout<<setw(4)<<c[i];
	cout<<endl;
}
int PriorRow(int a[MAX][MAX],int n,int b[])
//行优先存储上三角矩阵到b中
{
	int i,j,k=0;
	for(i=0;i<n;i++)
		for(j=i;j<n;j++)
			b[k++]=a[i][j];
	return k;
}
void CreateArray(int a[][MAX],int n)
//创建一个上三角1-n的二维数组（矩阵）
{
	int i,j,m;
	m=1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<i;j++)
			a[i][j]=0;
		for(j=i;j<n;j++)
			a[i][j]=m++;
	}
}
void PrintArray(int a[MAX][MAX],int n)
//打印矩阵
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<setw(4)<<a[i][j];
		cout<<endl;
	}
}
void Trans(int b[],int c[],int n)
/*将b中元素按列为主序连续存放到数组c中*/
{
	int step=n,count=0,i=0,j=0,k;
	for(k=0;k<n*(n+1)/2;k++)
	{
		count++;			/*记录一行是否读完*/
		c[j*(j+1)/2+i]=b[k];/*把以行为主序的数存放到对应以列为主序的数组中*/
		if(count==step)/*一行读完后*/
		{
			step--;
			count=0;/*下一行重新开始计数*/
			i++;/*下一行的开始行*/
			j=n-step;/*一行读完后，下一轮的开始列*/
		}
		else
			j++;/*一行还没有读完，继续下一列的数*/
	}
}