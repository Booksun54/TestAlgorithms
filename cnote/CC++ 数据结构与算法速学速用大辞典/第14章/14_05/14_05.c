#include<stdio.h>
void main()
{
	int i1,i2,i3,i4,i5;
	long mult,r;
	for(i1=0;i1<=9;i1++)
	{
		for(i2=0;i2<=9;i2++)
		{
			for(i3=0;i3<=9;i3++)
			{
				for(i4=0;i4<=9;i4++)
				{
					for(i5=1;i5<=9;i5++)
					{
						mult=i1*10000+i2*1000+i3*100+i4*10+i5;
						r=i5*100000+i5*10000+i5*1000+i5*100+i5*10+i5;
						if(mult*i1==r&&i1!=i2&&i1!=i3&&i1!=i4&&i1!=i5&&
							i2!=i3&&i2!=i4&&i2!=i5&&i3!=i4&&i3!=i5&&i4!=i5)
						{
							printf("%4d%4d%4d%4d%4d\n",i1,i2,i3,i4,i5);
							printf("¡Á%18d\n",i1);
							printf("_____________________\n",i1);
							printf("%5d%3d%3d%3d%3d%3d\n",i5,i5,i5,i5,i5,i5);
						}
					}
				}
			}
		}
	}
}