#include<stdio.h>
#define TableSize 100
#define IndexSize 20
typedef struct	/*顺序表类型*/
{
    int list[TableSize];
    int length;
}Table;
typedef struct	/*索引表类型*/
{
    int maxvalue;
    int index;
}IndexTable[IndexSize];
int SeqIndexSearch(Table S,IndexTable T,int m,int x);
void main()
{
	Table S={{8,13,25,19,22,29,46,38,30,35,50,60,49,57,55,65,70,89,92,70},20};
	IndexTable T={{25,0},{46,5},{60,10},{92,15}};
	int x=49,pos,i;
	printf("索引表T:\n");
	printf("\t最大元素值:");
	for(i=0;i<4;i++)
		printf("%3d",T[i].maxvalue);
	printf("\n\t起始下标  :");
	for(i=0;i<4;i++)
		printf("%3d",T[i].index);
	printf("\n顺序表S中的元素:\n");
	for(i=0;i<S.length;i++)
		printf("%3d",S.list[i]);
	if((pos=SeqIndexSearch(S,T,4,x))!=0)
		printf("\n元素%d在主表中的位置是:%2d\n",x,pos);
	else
		printf("\n查找失败!\n");
}
int SeqIndexSearch(Table S,IndexTable T,int m,int x)
/*在主表S中查找元素x，T为索引表。
如果找到返回该元素在表中的位置，否则返回0*/
{
	int i,j,bl;	
	for(i=0;i<m;i++)	/*通过索引表确定要查找元素在主表中的单元*/
		if(T[i].maxvalue>=x)
			break;
		if(i>=m)			/*如果要查找的元素不在表S中，则返回0*/
			return 0;
		j=T[i].index;		/*从第i个单元序号j开始查找元素x*/
		if(i<m-1)			/*bl为第j单元的长度*/
			bl=T[i+1].index-T[i].index;
		else
			bl=S.length-T[i].index;
		while(j<T[i].index+bl)
			if(S.list[j]==x)/*如果找到元素x，则返回x在主表中所在的位置*/
				return j+1;
			else
				j++;
			return 0;
}
