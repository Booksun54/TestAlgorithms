#include<stdio.h>
#include<malloc.h>
int *w;		/*存放每个集装箱的重量*/
int n;		/*集装箱的数目*/
int c;		/*第一艘船的承载量*/
int cw=0;	/*当前载重量*/
int remain;	/*剩余载重量*/
int	*x;		/*存放搜索时每个集装箱是否选取*/
int bestw;	/*存放最优的放在第一艘船的重量*/
int	*bestx;	/*存放最优的集装箱选取方案*/
void Backtrace(int k)
{	
	int i;
	if(k>n)	 /*递归的出口，如果找到一个解*/
	{	
		for(i=1;i<=n;i++)	/*则将装入的方法存入bestx中*/
			bestx[i]=x[i];	
		bestw=cw;			/*记下当前的最优装载量*/
		return;
	}
	else	
	{	
		remain-=w[k];
		if (cw+w[k]<=c) /*如果装入w[k]，还小于c*/         	
		{	
			x[k]=1;		/*则装入w[k]*/
			cw+=w[k];
			Backtrace(k+1);
			cw-=w[k];	/*不装入w[k]*/
		}
		if (remain+cw > bestw)	/*如果剩余的集装箱不能完全装入*/
		{	
			x[k]=0;	
			Backtrace(k+1);		/*继续从剩余的集装箱中检查是否能装入*/
		}
		remain+=w[k];		/*w[k]重新成为待装入的集装箱*/
	}
}
int BestSoution(int *w,int n,int c)
/*搜索最优的装载方案:w存放每个集装箱的重量,
n表示集装箱数目,c表示第一艘船的装载量*/
{	
	int i;
	remain=0;/*第一艘船剩下的装载量*/
	for(i=1;i<=n;i++)	
	{	
		remain+=w[i];	
	}
	bestw=0;/*初始化第一艘船最优装载量*/
	Backtrace(1);
	return bestw;	
}
void main()
{
	int i;
	printf("请输入集装箱的数目=");
	scanf("%d",&n);
	w=(int*)malloc(sizeof(int)*(n+1));
	x=(int*)malloc(sizeof(int)*(n+1));
	bestx=(int*)malloc(sizeof(int)*(n+1));
	printf("请输入第一艘船的装载量=");
	scanf("%d",&c);
	printf("请输入每个集装箱的重量:\n");
	for (i=1;i<=n;i++)	
	{	
		printf("第%d的重量=",i);
		scanf("%d",&w[i]);	
	}
	bestw=BestSoution(w,n,c);
	for (i=1;i<=n;i++)	
	{	
		printf("%4d",bestx[i]);	
	}
	printf("\n");
	printf("存放在第一艘船上的重量:%d\n",bestw); 
	free(w);
	free(x);
	free(bestx);
}

