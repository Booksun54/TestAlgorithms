	#include<stdio.h>
	#define N 20
	void main()
	{
		int i,j,a[N][N],n,k;
		printf("请输入矩阵的阶n= ");
		scanf("%d",&n);
		k=1;
	    /*输出上三角（前n个斜行）*/
		for(i=1;i<=n;i++)
			for(j=1;j<=i;j++) 
			{
				if(i%2==0)  
					a[i+1-j][j]=k; 
				else        
					a[j][i+1-j]=k;           
				k++;
			}
			/*输出下三角（后n-1个斜行）*/
			for(i=n+1;i<2*n;i++)
				for(j=1;j<=2*n-i;j++)
				{
					if(i%2==0)  
						a[n+1-j][i-n+j]=k;  
					else       
						a[i-n+j][n+1-j]=k;        
					k++;
				}
				printf("********蛇形方阵********\n");
				for(i=1;i<=n;i++)
				{
					for(j=1;j<=n;j++) 
						printf("%4d",a[i][j]);
					printf("\n");
				}
	}