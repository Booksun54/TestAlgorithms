#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include "string.h"
/*宏定义和链栈类型定义*/
typedef char DataType;
#include"LinkStack.h"					/*包含链栈实现文件*/
void LineEdit();
void main()
{
	LineEdit();
}
void LineEdit()
/*行编辑程序*/
{
    LinkStack S;
    char ch;
	DataType e;
	DataType a[50];
	int i,j=0;
    InitStack(&S);
    printf("输入字符序列(#表示前一个字符无效，@表示当前行字符无效).\n");
    ch=getchar();
    while(ch!='\n')
    {
		switch(ch)
		{
		case '#':					/*如果当前输入字符是'#'，且栈不空，则将栈顶字符出栈*/
			if(!StackEmpty(S))
				PopStack(S,&ch);
			break;
		case '@': 					/*如果当前输入字符是'@'，则将栈清空*/
			ClearStack(S);
			break;
		default: 					/*如果当前输入字符不是'#'和'@'，则将字符进栈*/
			PushStack(S,ch);
		}
		ch=getchar();					/*读入下一个字符*/
	}
	while(!StackEmpty(S))
	{
		PopStack(S,&e);				/*将字符出栈，并存入数组a中*/
		a[j++]=e;
	}
	for(i=j-1;i>=0;i--)					/*输出正确的字符序列*/
		printf("%c",a[i]);
	printf("\n");
	DestroyStack(S);
}