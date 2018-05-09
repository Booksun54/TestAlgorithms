#include<stdio.h> 
#include<math.h> 
#define EPS 1e-6
void main() 
{ 
	double a,x0,x1; 
	printf("请输入一个实数:"); 
	scanf("%lf",&a);
	if(a<0) 
		printf("输入错误，请重新输入!\n"); 
	else 
	{ 
		x0=a/2; 
		x1=(x0+a/x0)/2; 
		do 
		{ 
			x0=x1; 
			x1=(x0+a/x0)/2; 
		}while(fabs(x0-x1)>=EPS); 
	} 
	printf("%g的平方根是:%g\n",a,x1); 
}