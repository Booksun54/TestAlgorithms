#include<stdio.h>
#include<stdlib.h>
#define StackSize 100
typedef char DataType;
#define CHAR1 "左端栈的栈顶元素是：%c，右端栈的栈顶元素是:%c\n"
#define CHAR2 "%5c"
#include "SSeqStack.h"		/*包含共享栈的基本类型定义和基本操作实现*/
void main()
{
    SSeqStack S;			/*定义一个共享栈*/
	int i;
	DataType a[]={'a','b','c','d','e','f'};
	DataType b[]={'p','w','x','y','z'};
	DataType e1,e2;
    InitStack(&S);					/*初始化共享栈*/
    for(i=0;i<sizeof(a)/sizeof(a[0]);i++)	/*将数组a中元素依次进左端栈*/
    {
        if(PushStack(&S,a[i],1)==0)
        {
            printf("栈已满，不能入栈!");
            return;
        }
	}
	for(i=0;i<sizeof(b)/sizeof(b[0]);i++)	/*将数组b中元素依次进右端栈*/
    {
        if(PushStack(&S,b[i],2)==0)
        {
            printf("栈已满，不能入栈!");
            return;
        }
	}	
	if(GetTop(S,&e1,1)==0)
	{
		printf("栈已空");
		return;
	}
	if(GetTop(S,&e2,2)==0)
	{
		printf("栈已空");
		return;
	}
	printf(CHAR1,e1,e2);
	printf("左端栈的出栈的元素次序是：");
	
	while(!StackEmpty(S,1))	/*将左端栈元素出栈*/
    {
        PopStack(&S,&e1,1);
        printf(CHAR2,e1);	
	}
	printf("\n");
	printf("右端栈的出栈的元素次序是：");
	while(!StackEmpty(S,2))	/*将右端栈元素出栈*/
	{
		PopStack(&S,&e2,2);
		printf(CHAR2,e2);
	}
	printf("\n");	
}