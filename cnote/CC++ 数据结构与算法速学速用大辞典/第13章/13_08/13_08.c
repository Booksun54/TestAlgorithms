#include<stdio.h>
void output();
void step();
#define STAIR_NUM 4
int queue[STAIR_NUM];
int total=0;
int index;
main()
{
	printf("  %d 级台阶\n",STAIR_NUM);
	printf("--------------------------------------\n");
	printf("             上台阶的方法               \n");    
	printf("--------------------------------------\n");
	step(STAIR_NUM);
	printf("\n 共有 %d 种方法 \n",total);
} 
void step(int n)
{
	if (n==0) 
	{
		total++;
		printf("---------第%d种方法 ----------\n",total);
		output();
		return ;  
	}
	queue[index++]=1;
	step(n-1);
	--index;
	if (n>1)
	{
		queue[index++]=2;
		step(n-2); 
		--index;
	}
	if(n>2)
	{
		queue[index++]=3; 
		step(n-3); 
		--index;
	}
}
void output()
{
	int i;
	for(i=0;i<index;i++)
		printf("-%d",queue[i]);
	printf("-\n");
}
