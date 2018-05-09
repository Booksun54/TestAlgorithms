#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include "string.h"
/*宏定义和链栈类型定义*/
typedef char DataType;
#include"LinkStack.h"					/*包含链栈实现文件*/
int Match(DataType e,DataType ch); 		/*检验括号是否匹配函数*/
void main()
{
    LinkStack S;
	char *p;
	DataType e;
	DataType ch[60];
	InitStack(&S);						/*初始化链栈*/
	printf("请输入算术表达式(可以包含括号'{}','[]','()'):\n");
	gets(ch);
	p=ch; 							/*p指向输入的括号表达式*/
	while(*p) 							/*判断p指向的字符是否是字符串结束标记*/
	{
		switch(*p)
		{
		case '(':
		case '[':
		case '{':
			PushStack(S,*p++);			/*如果是左括号，将括号进栈*/
			break;
		case ')':
		case ']':
		case '}':
			if(StackEmpty(S)) 			/*如果是右括号且栈已空，说明缺少左括号*/
			{
				printf("缺少左括号.\n");
				return;
			}
			else
			{
				GetTop(S,&e);			/*如果栈不空，读入的是右括号，则取出栈顶的括号*/
				if(Match(e,*p)) 			/*将栈顶的括号与读入的右括号进行比较*/
					PopStack(S,&e); 	/*如果栈顶括号与读入的右括号匹配，则将栈顶的括号出栈*/
				else					/*如果栈顶括号与读入的括号不匹配，则说明此括号序列不匹配*/
				{
					printf("左右括号不匹配.\n");
					return;
				}
			}
		default: 						/*如果是其它字符，则不处理，直接将p指向下一个字符*/
			p++;
		}
	}
	if(StackEmpty(S)) 					/*如果字符序列读入完毕，且栈已空，说明括号序列匹配*/
		printf("括号匹配.\n");
	else                                /*如果字符序列读入完毕，且栈不空，说明缺少右括号*/
		printf("缺少右括号.\n");			
}
int Match(DataType e,DataType ch)
/*判断左右两个括号是否为同类型的括号，同类型则返回1，否则返回0*/
{
	if(e=='('&&ch==')')
		return 1;
	else if(e=='['&&ch==']')
		return 1;
	else if(e=='{'&&ch=='}')
		return 1;
	else
		return 0;
}