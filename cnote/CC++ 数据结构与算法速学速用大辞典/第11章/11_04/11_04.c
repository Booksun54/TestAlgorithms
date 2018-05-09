#include<stdio.h>
#define N 8
void main()
{
	int a[N+1][N+1],i,j;
	for(i=0;i<=N;i++)
		a[i][i]=a[i][0]=1;
	for(i=2;i<=N;i++)
		for(j=1;j<i;j++)
			a[i][j]=a[i-1][j]+a[i-1][j-1];
		printf("%d½×Ñî»ÔÈý½ÇÈçÏÂ:\n",N+1);
		for(i=0;i<=N;i++)
		{
			for(j=0;j<=i;j++)
				printf("%3d",a[i][j]);
			printf("\n");
		}
}