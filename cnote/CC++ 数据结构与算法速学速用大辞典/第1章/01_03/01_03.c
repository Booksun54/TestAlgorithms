#include<stdio.h>				
#define ListSize 200
typedef int DataType;
#include"SeqList.h"					/*包含顺序表的基本运算*/
void DelElem(SeqList *A,SeqList B);		/*删除A中出现B的元素的函数声明*/
void main()
{
	int i,j,flag;
	DataType e;
	SeqList A,B;					/*声明顺序表A和B*/
	InitList(&A);					/*初始化顺序表A*/
	InitList(&B);					/*初始化顺序表B*/
	for(i=1;i<=10;i++)				/*插入到顺序表A中10个数*/
	{
		if(InsertList(&A,i,i*2+10)==0)
		{
			printf("位置不合法");
			return;
		}
	}
	for(i=1,j=10;i<=8;j=j+2,i++)		/*插入顺序表B中8个数*/
	{
		if(InsertList(&B,i,j+i*2)==0)
		{
			printf("位置不合法");
			return;
		}
	}
	printf("顺序表A中的元素：\n");
	for(i=1;i<=A.length;i++)		/*输出顺序表A中的每个元素*/
	{
		flag=GetElem(A,i,&e);		/*返回顺序表A中的每个元素到e中*/
		if(flag==1)
			printf("%4d",e);
	}
	printf("\n");
	printf("顺序表B中的元素：\n");
	for(i=1;i<=B.length;i++)		/*输出顺序表B中的每个元素*/
	{
		flag=GetElem(B,i,&e);		/*返回顺序表B中的每个元素到e中*/
		if(flag==1)
			printf("%4d",e);	
	}
	printf("\n");
	printf("将在A中出现B的元素删除后,A中的元素(即A-B)：\n");
	DelElem(&A,B);					/*将在顺序表A中出现的B的元素删除*/
	for(i=1;i<=A.length;i++)		/*显示输出删除后A中所有元素*/
	{
		flag=GetElem(A,i,&e);
		if(flag==1)
			printf("%4d",e);	
	}
	printf("\n");
}
void DelElem(SeqList *A,SeqList B)
/*求A-B，即删除A中B的元素*/
{
	int i,flag,pos;
	DataType e;
	for(i=1;i<=B.length;i++)		
	{
		flag=GetElem(B,i,&e);		/*依次把B中每个元素取出给e*/
		if(flag==1)
		{
			pos=LocateElem(*A,e);	/*在A中查找元素e*/
			if(pos>0)				/*如果该元素存在*/
				DeleteList(A,pos,&e);/*则将其从A中删除*/
		}
	}
}