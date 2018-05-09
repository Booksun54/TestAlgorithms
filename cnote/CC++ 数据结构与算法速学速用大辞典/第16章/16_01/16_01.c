#include<stdio.h>
#define MAX 100 
int a[MAX]; 
void comb(int n,int r) 
{ 
	int i,j; 
	i=0;
	a[i]=1;
	do 
	{ 
		if(a[i]-i<=n-r+1) 			/*还可以向前试探*/
		{
			if (i==r-1)				/*找到一个组合*/
			{
				for(j=0;j<r;j++)		/*输出一个组合*/
					printf("%4d",a[j]);
				printf("\n");
				a[i]++;
				continue;
			}
			i++;					/*向前试探*/
			a[i]=a[i-1]+1;
		}
		else						/*回溯*/
		{
			if(i==0)				/*找完全部解*/
				return;
			a[--i]++;
		}
	}while(1);
}
void main() 
{ 
	printf("正整数1~5中的3个数的任意组合:\n");
	comb(5,3); 
}
