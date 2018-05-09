typedef struct
{
    DataType stack[StackSize];
    int top[2];
}SSeqStack;
void InitStack(SSeqStack *S)
/*共享栈的初始化*/
{
    S->top[0]=0;
    S->top[1]=StackSize-1;
}
int GetTop(SSeqStack S, DataType *e,int flag)   
/*取栈顶元素。将栈顶元素值返回给e，并返回1表示成功；否则返回0表示失败。*/
{
	switch(flag)
	{
	case 1:		 /*为1，表示要取左端栈的栈顶元素*/
		if(S.top[0]==0)
			return 0;
		*e=S.stack[S.top[0]-1];
		break;
	case 2: 		/*为2，表示要取右端栈的栈顶元素*/
		if(S.top[1]==StackSize-1)
			return 0;
		*e=S.stack[S.top[1]+1];
		break;
	default:
		return 0;			
	}
	return 1;
}
int PushStack(SSeqStack *S,DataType e,int flag)
/*将元素e入共享栈。进栈成功返回1，否则返回0*/
{
	if(S->top[0]==S->top[1])		/*如果共享栈已满*/
		return 0; 				/*返回0，进栈失败*/
	switch(flag)
	{
	case 1:				/*当flag为1，表示将元素进左端的栈*/
		S->stack[S->top[0]]=e;	/*元素进栈*/
		S->top[0]++;			/*修改栈顶指针*/
		break;
	case 2:			/*当flag为2，表示将元素要进右端的栈*/
		S->stack[S->top[1]]=e;	/*元素进栈*/
		S->top[1]--;			/*修改栈顶指针*/
		break;
	default:
		return 0;
	}
	return 1; 					/*返回1，进栈成功*/
}
int PopStack(SSeqStack *S,DataType *e,int flag)
{
	switch(flag) 			/*在出栈操作之前，判断哪个栈要进行出栈操作*/
	{
	case 1: 			/*为1，表示左端的栈需要出栈操作*/
		if(S->top[0]==0)	/*左端的栈为空*/
			return 0; 	/*返回0，出栈操作失败*/
		S->top[0]--;		/*修改栈顶指针，元素出栈操作*/
		*e=S->stack[S->top[0]];	/*将出栈的元素赋给e*/
		break;
	case 2: 			/*为2，表示右端的栈需要出栈操作*/
		if(S->top[1]==StackSize-1)	/*右端的栈为空*/
			return 0; 			/*返回0，出栈操作失败*/
		S->top[1]++;				/*修改栈顶指针，元素出栈操作*/
		*e=S->stack[S->top[1]];	/*将出栈的元素赋给e*/
		break;
	default:
		return 0;
	}
	return 1; /*返回1，出栈操作成功*/
}
int StackEmpty(SSeqStack S,int flag)
/*判断栈是否为空。如果栈为空，返回1；否则，返回0。*/
{
	switch(flag)
	{
	case 1: 		/*为1，表示判断左端的栈是否为空*/
		if(S.top[0]==0)
			return 1;
		break;
	case 2: 		/*为2，表示判断右端的栈是否为空*/
		if(S.top[1]==StackSize-1)
			return 1;
		break;
	default:
		printf("输入的flag参数错误!");
		return -1;			
	}
	return 0;
}