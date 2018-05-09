#include<stdio.h>
void main() 
{ 
	int i,j,k,n; 
	printf("水仙花数是:"); 
	for(n=100;n<1000;n++) 
	{ 
		i=n/100;	/*百位上的数字*/ 
		j=n/10%10;	/*十位上的数字*/ 
		k=n%10;		/*个位上的数字*/ 
		if(i*100+j*10+k==i*i*i+j*j*j+k*k*k) 
			printf("%5d",n); 
	} 
	printf("\n"); 
} 
