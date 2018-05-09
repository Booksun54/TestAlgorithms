#define StackSize 100
typedef struct
{
    DataType stack[StackSize];
    int top;
}SeqStack;
void InitStack(SeqStack *S)    
/*初始化栈*/
{
S->top=0;	/*把栈顶指针置为0*/
}
int StackEmpty(SeqStack S)   
/*判断栈是否为空，栈为空返回1，否则返回0*/
{
    if(S.top==0)			/*如果栈顶指针top为0*/
        return 1;			/*返回1*/
    else					/*否则*/
        return 0; 			/*返回0*/
}
int GetTop(SeqStack S, DataType *e)   
/*取栈顶元素。将栈顶元素值返回给e，返回1表示成功，返回0表示失败。*/
{
if(S.top<=0)		/*如果栈为空*/
{
printf("栈已经空!\n");
return 0;
}
else				/*否则*/
{
*e=S.stack[S.top-1];	/*在取栈顶元素*/
return 1;
}
}
int PushStack(SeqStack *S,DataType e)   
/*将元素e进栈，元素进栈成功返回1，否则返回0.*/
{
if(S->top>=StackSize)				/*如果栈已满*/
{
printf("栈已满，不能将元素进栈！\n");
  return 0;
}
else								/*否则*/
{
S->stack[S->top]=e;			/*元素e进栈*/
S->top++;					/*修改栈顶指针*/
return 1;
}
}
int PopStack(SeqStack *S,DataType *e)
/*出栈操作。将栈顶元素出栈，并将其赋值给e。出栈成功返回1，否则返回0*/
{
    if(S->top==0)		/*如果栈为空*/
    {
        printf("栈中已经没有元素，不能进行出栈操作!\n");
        return 0;
    }
	else				/*否则*/
{
 S->top--;			/*先修改栈顶指针，即出栈*/
*e=S->stack[S->top];	/*将出栈元素赋给e*/
        return 1;
    }
}
int StackLength(SeqStack S)
/*求栈的长度*/
{
    return S.top;
}
void ClearStack(SeqStack *S)    
/*清空栈*/
{
S->top=0;			/*将栈顶指针置为0*/
}