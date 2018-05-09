#include<stdio.h>
#define S 100							/*S:全程长度*/
void main()
{
	int i,j,n,k=0,total,dist;
	int x[]={10,20,35,40,50,65,75,85,100};	/*数组x:加油站位置(距离起点的位置)*/
	int a[10];								/*数组a:选择加油点的位置*/
	n=sizeof(x)/sizeof(x[0]);				/*n:沿途加油站的个数*/
	printf("请输入最远行车距离(15<=n<100):");
	scanf("%d",&dist);				
	total=dist;							/*total:总共行使的公里数*/
	j=1;								/*j:选择的加油站个数*/
	while(total<S)						/*如果汽车未走完全程*/
	{
		for(i=k;i<n;i++)
		{
			if(x[i]>total)				/*如果距离下一个加油站太远*/
			{
				a[j]=x[i-1];			/*则在当前加油点加油*/
				j++;
				total=x[i-1]+dist;		/*计算加完油后能行使的最远距离*/
				k=i;					/*k:记录下一次加油的开始位置*/
				break;					/*退出for循环*/
			}
		}
	}
	printf("行驶%d公里应该选择的加油点:\n",S);
	for(i=1;i<j;i++)					/*输出选择的加油点*/
		printf("%4d",a[i]);
	printf("\n");
}
