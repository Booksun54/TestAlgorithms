#include<stdio.h>		
#include<stdlib.h>		
#include<string.h>		
#include<malloc.h>		
typedef char DataType;	/*数据类型为字符类型*/
#include"LinkStack.h"
#include"LinkQueue.h"
void PrintStackQueue(LStackNode *LStack,LinkQueue LQueue);
void main()
{
	DataType str1[]="ABCDEFEDCBA";	/*回文字符序列1*/
	DataType str2[]="xabcdcaax";	/*回文字符序列2*/
	int i;
	LinkQueue LQueue1,LQueue2;		/*定义链式循环队列*/
	LStackNode *LStack1,*LStack2;	/*定义链栈*/
	InitQueue(&LQueue1);		/*初始化链式循环队列1*/
	InitQueue(&LQueue2);		/*初始化链式循环队列2*/
	InitStack(&LStack1);		/*初始化链栈1*/
	InitStack(&LStack2);		/*初始化链栈2*/
	for(i=0;i<strlen(str1);i++)
	{
		EnQueue(&LQueue1,str1[i]);	/*字符序列1入队*/
	    PushStack(LStack1,str1[i]);	/*字符序列1入栈*/
	}
	for(i=0;i<strlen(str2);i++)
	{
		EnQueue(&LQueue2,str2[i]);	/*字符序列2入队*/
		PushStack(LStack2,str2[i]);	/*字符序列2入栈*/
	}
	printf("字符序列1：%s\n",str1);
	PrintStackQueue(LStack1,LQueue1);
	printf("字符序列2：%s\n",str2);
	PrintStackQueue(LStack2,LQueue2);
}
void PrintStackQueue(LStackNode *LStack,LinkQueue LQueue)
{
	DataType st,qu;
	printf("出队序列  出栈序列\n");
	while(!StackEmpty(LStack))		/*判断栈1是否为空*/
	{
		DeQueue(&LQueue,&qu);		/*字符依次出队，并把元素赋给q*/
		PopStack(LStack,&st);		/*字符出栈，并把元素赋给s*/	
		printf("%5c",qu);			/*输出字符序列1*/
		printf("%10c\n",st);
		if(qu!=st)				/*判断字符序列1是否为回文*/
		{
			printf("该字符序列不是回文！\n");
			return;
		}
	}
	printf("该字符序列是回文！\n");	
}