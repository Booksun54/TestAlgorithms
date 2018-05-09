#include<stdio.h>
#include<stdlib.h>
/*类型定义*/
typedef char DataType;
#include "SeqStack.h"		/*包含栈的基本操作实现*/
void main()
{
    SeqStack S;			/*定义一个栈*/
	int i;
	DataType a[]={'A','B','C','D','E','F','G','H'};
	DataType e;
    InitStack(&S);					/*初始化栈*/
    for(i=0;i<sizeof(a)/sizeof(a[0]);i++)	/*将数组a中元素依次进栈*/
    {
        if(PushStack(&S,a[i])==0)
        {
            printf("栈已满，不能进栈！");
            return;
        }
	}
	printf("依次出栈的元素是：");
	if(PopStack(&S,&e)==1)			/*元素H出栈*/
		printf("%4c",e);
	if(PopStack(&S,&e)==1)			/*元素G出栈*/
		printf("%4c",e);  
    printf("\n");
	printf("当前的栈顶元素是：");  
	if(GetTop(S,&e)==0) 				/*取栈顶元素*/
    {
        printf("栈已空！");
        return;
    }
    else
        printf("%4c\n",e);
	printf("将元素G、H依次入栈。\n");  
    if(PushStack(&S,'X')==0) 				/*元素X进栈*/
    {
        printf("栈已满，不能进栈！");
        return;
    }
	if(PushStack(&S,'Y')==0) 				/*元素Y进栈*/
    {
        printf("栈已满，不能进栈！");
        return;
	}
	printf("当前栈中的元素个数是：%d\n",StackLength(S)); 	/*输出栈中元素个数*/
	printf("将栈中元素出栈，出栈的序列是：\n");
	while(!StackEmpty(S))							 /*如果栈不空，将所有元素出栈*/
	{
        PopStack(&S,&e);
        printf("%4c",e);
	}
	printf("\n");
}