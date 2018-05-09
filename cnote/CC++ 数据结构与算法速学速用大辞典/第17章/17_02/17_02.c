#include<stdio.h>
void main()
{ 
	static int a[34];
	int i,j,k,c=0;
	a[0]=1;
	k=0;
	printf("7的34次方是: ");
	for(i=1;i<=34;i++)
    { 
		for (j=0;j<=k;j++)
		{ 
			a[j]=a[j]*7+c;
			c=a[j]/10;
			a[j]%=10;
		}
		if (c) 
		{
			k++;
			a[k]=c;
			c=0;
		}
    }
	for (;k>=0;k--)
		printf("%d",a[k]);
	printf("\n");
	getch();
}
