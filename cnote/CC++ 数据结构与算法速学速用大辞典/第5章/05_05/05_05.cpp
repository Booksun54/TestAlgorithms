#include <stdio.h>
#define N 20
void main()
{
	int i,j,n,k=1,a[N][N];
	printf("请输入一个正整数(1≤N≤20):");
	scanf("%d",&n);
	printf("********螺旋矩阵********\n");
	for(i=0;i<=n/2;i++)			/*控制圈数*/
	{
		for(j=i;j<n-i;j++)		/*上方元素*/
			a[i][j]=k++;
		for(j=i+1;j<n-i;j++)	/*右方元素*/
			a[j][n-i-1]=k++;
		for(j=n-i-2;j>i;j--)	/*下方元素*/
			a[n-i-1][j]=k++;
		for(j=n-i-1;j>i;j--)	/*左方元素*/
			a[j][i]=k++;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%5d",a[i][j]);
		printf("\n");
	}
}