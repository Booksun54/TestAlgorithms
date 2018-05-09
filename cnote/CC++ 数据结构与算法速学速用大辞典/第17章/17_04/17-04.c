/*包含头文件*/
#include<stdio.h>
#include<string.h>
/*包含顺序栈基本操作实现函数*/
typedef char DataType;
#include"SeqStack.h"
#define MAXSIZE 50
/*操作数栈定义*/
typedef struct
{
	float data[MAXSIZE];
	int top;                  
}OpStack;  
/*函数声明*/
void TranslateExpress(char s1[],char s2[]);
float ComputeExpress(char s[]);
void main()
{
	char a[MAXSIZE],b[MAXSIZE];
	float f;
	printf("请输入一个算术表达式：\n");
	gets(a);
	printf("中缀表达式为：%s\n",a);
	TranslateExpress(a,b);
	printf("后缀表达式为：%s\n",b);
	f=ComputeExpress(b);
	printf("计算结果：%f\n",f);
}   
float ComputeExpress(char a[])
/*计算后缀表达式的值*/
{
	OpStack S; 				/*定义一个操作数栈*/
	int i=0,value;
	float x1,x2;
	float result;
	S.top=-1; 					/*初始化栈*/
	while(a[i]!='\0') 				/*依次扫描后缀表达式中的每个字符*/
	{
		if(a[i]!=' '&&a[i]>='0'&&a[i]<='9') 	/*如果当前字符是数字字符*/
		{
			value=0;
			while(a[i]!=' ') 				/*如果不是空格，说明数字字符是两位数以上的数字字符*/
			{
				value=10*value+a[i]-'0';
				i++;
			}
			S.top++;
			S.data[S.top]=value; 		/*处理之后将数字进栈*/
		}		
		else							/*如果当前字符是运算符*/
		{
			switch(a[i]) 				/*将栈中的数字出栈两次，然后用当前的运算符进行运算，再将结果入栈*/
			{		
			case '+':
				x1=S.data[S.top];
				S.top--;
				x2=S.data[S.top];
				S.top--;
				result=x1+x2;
				S.top++;
				S.data[S.top]=result;
				break;
			case '-':
				x1=S.data[S.top];
				S.top--;
				x2=S.data[S.top];
				S.top--;
				result=x2-x1;
				S.top++;
				S.data[S.top]=result;
				break;
			case '*':
				x1=S.data[S.top];
				S.top--;
				x2=S.data[S.top];
				S.top--;
				result=x1*x2;
				S.top++;
				S.data[S.top]=result;
				break;
			case '/':
				x1=S.data[S.top];
				S.top--;
				x2=S.data[S.top];
				S.top--;
				result=x2/x1;
				S.top++;
				S.data[S.top]=result;
				break;
			}
			i++;
		}
	}
	if(!S.top!=-1)						/*如果栈不空，将结果出栈，并返回*/
	{
		result=S.data[S.top];
		S.top--;
		if(S.top==-1)
			return result;
		else
		{
			printf("表达式错误");
			exit(-1);
		}
	}
}
void TranslateExpress(char str[],char exp[])
/*把中缀表达式转换为后缀表达式*/ 
{
	SeqStack S; 				/*定义一个栈，用于存放运算符*/
	char ch;   
	DataType e;
	int i=0,j=0;
	InitStack(&S);
	ch=str[i];
	i++;
	while(ch!='\0')				/*依次扫描中缀表达式中的每个字符*/
	{
		switch(ch)
		{
		case'(': 				/*如果当前字符是左括号，则将其进栈*/
			PushStack(&S,ch);
			break;
		case')': 				/*如果是右括号，将栈中的操作数出栈，并将其存入数组exp中*/
			while(GetTop(S,&e)&&e!='(')    
			{
				PopStack(&S,&e);
				exp[j]=e;
				j++;
			}
			PopStack(&S,&e);	/*将左括号出栈*/
			break;
		case'+':
		case'-': 				/*如果遇到的是'+'和'-'，因为其优先级低于栈顶运算符的优先级，所以先将栈顶字符出栈，并将其存入数组exp中，然后将当前运算符进栈*/
			while(!StackEmpty(S)&&GetTop(S,&e)&&e!='(')
			{
				PopStack(&S,&e);
				exp[j]=e;
				j++;
			}
			PushStack(&S,ch);	/*当前运算符进栈*/
			break;
		case'*': 				/*如果遇到的是'*'和'/',先将同级运算符出栈，并存入数组exp中，然后将当前的运算符进栈*/
		case'/':
			while(!StackEmpty(S)&&GetTop(S,&e)&&e=='/'||e=='*')
			{
				PopStack(&S,&e);
				exp[j]=e;
				j++;
			}
			PushStack(&S,ch);	/*当前运算符进栈*/
			break;
		case' ': 				/*如果遇到空格，忽略*/
			break;
		default: 				/*如果遇到的是操作数，则将操作数直接送入数组exp中，并在其后添加一个空格，用来分隔数字字符*/
			while(ch>='0'&&ch<='9')
			{
				exp[j]=ch;
				j++;
				ch=str[i];
				i++;
			}
			i--;
			exp[j]=' ';
			j++;
		}
		ch=str[i];				/*读入下一个字符，准备处理*/
		i++;
	}
	while(!StackEmpty(S)) 		/*将栈中所有剩余的运算符出栈，送入数组exp中*/
	{
		PopStack(&S,&e);
		exp[j]=e;
		j++;
	}
	exp[j]='\0';
}


