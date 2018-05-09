#include<stdio.h> 
void main() 
{ 
	int i; 
	float total=0.0; 
	for(i=0;i<3;i++) 
		total=(total+1000)/(1+0.0031*12); 
	printf("第一次必须向银行存入%.2f元\n",total); 
}
