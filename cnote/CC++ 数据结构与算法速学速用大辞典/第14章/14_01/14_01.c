#include<stdio.h>
void main()
{  
	int n,c1,c2,c3;
	printf("请输入一个整数:");
	scanf("%d",&n);
	c1 = n%3 ==0;
	c2 = n%5 ==0;
	c3 = n%7 ==0;
	switch((c1<<2)+(c2<<1)+c3)
	{
	case 0:
		printf("不能被3,5,7整除.\n"); 
		break;
	case 1: 
		printf("只能被7整除.\n"); 
		break;
	case 2:
		printf("只能被5整除.\n");
		break;
	case 3:
		printf("可以被5,7整除.\n");
		break;
	case 4: 
		printf("只能被3整除.\n");
		break;
	case 5:
		printf("可以被3,7整除.\n");
		break;
	case 6: 
		printf("可以被3,5整除.\n");
		break;
	case 7: 
		printf("可以被3,5,7整除.\n");
		break;
	}
} 
