#include<stdio.h>
#include<stdlib.h>
#define N 20
void Latin_Square(int n,int a[][N]);
void main()
{
	int i,j,n;
	int latin[N][N];
	printf("ÇëÊäÈë¾ØÕóµÄ½×n=");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			latin[i][j]=0;
		Latin_Square(n,latin);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				printf("%4d",latin[i][j]);
			printf("\n");
		}
}
void Latin_Square(int n,int a[][N])
{
	int i,j,sub,index;
	for(i=1;i<=n;i++)
	{
		do
		{
			index=rand()%n;
		}while(a[0][index]!=0);
		a[0][index]=i;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			if(a[0][j]==i+1)
				break;
			sub=j+1;
			for(j=1;j<n;j++)
				a[j][a[0][(sub++)%n]-1]=a[0][i];
	}
}