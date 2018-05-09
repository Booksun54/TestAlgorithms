#include<iostream.h>
#include<iomanip.h>
#define MAX 100
void PrintSnakeMatrix();
void main()
{
	PrintSnakeMatrix();


}
void PrintSnakeMatrix()
{
	int i,j,n,k,p,q,m;
	int a[MAX][MAX];
	cin>>n;
	m=1;
	for(k=1;k<=2*n-1;k++)
	{
		if(k<n)
			q=k;
		else
			q=2*n-k;
		for(p=1;p<=q;p++)
		{
			if(k%2==0)
			{
				i=q-p+1;
				j=p;
			}
			else
			{
				i=p;
				j=q-p+1;
			}
			if(k>=n)
			{
				i=i+n-q;
				j=j+n-q;
			}
			a[i][j]=m;
			m++;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				cout<<setw(4)<<a[i][j];
			cout<<endl;
		}
	}
}