#include<stdio.h>
#include<math.h>
#define EPS 1e-6
double f(double x);
double f1(double x);
int Newton(double *x,int iteration);
void main() 
{ 
	double x; 
	int iteration;
	printf("输入初始迭代值x0:"); 
	scanf("%lf",&x);
	printf("输入迭代的最大次数:"); 
	scanf("%d",&iteration);
	if(1==Newton(&x,iteration))
		printf("该值附近的根为:%lf\n",x);
	else
		printf("迭代失败!\n");
}
double f(double x) 
/*函数*/ 
{ 
	return x*x*x*x-3*x*x*x+1.5*x*x-4.0; 
} 
double f1(double x) 
/*导函数*/ 
{ 
	return 4*x*x*x-9*x*x+3*x; 
} 
int Newton(double *x,int iteration) 
/*迭代次数*/ 
{ 
	double x1,x0; 
	int i; 
	x0=*x; /*初始方程的近似根*/
	for(i=0;i<iteration;i++) /*iteration是迭代次数*/
	{ 
		if(f1(x0)==0.0)/*如果倒数为0，则返回0(该方法失效)*/
		{ 
			printf("迭代过程中导数为0!\n"); 
			return 0; 
		} 
		x1=x0-f(x0)/f1(x0);/*开始牛顿迭代计算*/
		if(fabs(x1-x0)<EPS || fabs(f(x1))<EPS) /*达到结束条件*/
		{ 
			*x=x1; /*返回结果*/ 
			return 1; 
		} 
		else /*未达到结束条件*/ 
			x0=x1; /*准备下一次迭代*/ 
	} 
	printf("超过最大的迭代次数!\n"); /*迭代次数达到规定的最大值，仍没有达到精度*/ 
	return 0; 
} 


