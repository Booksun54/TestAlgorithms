#include<stdio.h>
#define MaxSize 100
typedef struct
{
    int list[MaxSize];
    int length;
}Table;
int SeqSearch(Table S,int x)
/*在顺序表中查找元素x，如果找到返回该元素在表中的位置，否则返回0*/
{
	int i=0;
	while(i<S.length&&S.list[i]!=x)	/*从表的第1个元素开始查找x*/
		i++;
	if(S.list[i]==x)				/*如果找到x，返回元素的位置*/
		return i+1;
	else							/*否则返回0*/
		return 0;
}
void main()
{
	Table T={{73,12,67,32,21,39,55,48},8};
	int i,position,x;
	printf("表中的元素:\n");
	for(i=0;i<T.length;i++)
		printf("%4d",T.list[i]);
	printf("\n请输入要查找的元素:");
	scanf("%d",&x);
	position=SeqSearch(T,x);
	if(position)
		printf("%d是表的第%d个元素.\n",x,position);	
	else
		printf("没有找到%d.",x);	
}