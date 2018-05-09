#include<stdio.h>
void main()
{
	int day,x,y;
	day=10;
	y=1;
	while(day>1)
	{
		x=(y+1)*2;
		y=x;
		day--;
	}
	printf("第一天摘到的桃子总数是%d.\n",x);
}