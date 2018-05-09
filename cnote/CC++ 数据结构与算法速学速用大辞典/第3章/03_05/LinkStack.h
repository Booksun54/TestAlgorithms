typedef struct node
{
    DataType data;
    struct node *next;
}LStackNode,*LinkStack;
void InitStack(LinkStack *top)
/*将链栈初始化为空*/
{
	if((*top=(LinkStack)malloc(sizeof(LStackNode)))==NULL)		/*为头结点分配一个存储空间*/
		exit(-1);
	(*top)->next=NULL;				/*将链栈的头结点指针域置为空*/
}
int StackEmpty(LinkStack top)   
/*判断链栈是否为空，就是通过判断头结点的指针域是否为空*/
{
    if(top->next==NULL)				/*当链栈为空时*/
        return 1;					/*返回1*/
    else							/*否则*/
        return 0; 					/*返回0*/
}
int PushStack(LinkStack top, DataType e)
/*进栈操作就是要在链表的第一个结点前插入一个新结点，进栈成功返回1*/
{
	LStackNode *p;		
	if((p=(LStackNode*)malloc(sizeof(LStackNode)))==NULL)
	{
		printf("内存分配失败!");
		exit(-1);
	}
	p->data=e;		
	p->next=top->next;
	top->next=p;
	return 1;
}
int PopStack(LinkStack top,DataType *e)
/*删除单链表中的第i个位置的结点。删除成功返回1，失败返回0*/
{
	LStackNode *p;
	p=top->next;
    if(!p)							/*判断链栈是否为空*/
    {
        printf("栈已空");
        return 0;
    }
    top->next=p->next;				/*将栈顶结点与链表断开，即出栈*/
	*e=p->data;					/*将出栈元素赋值给e*/
    free(p);						/*释放p指向的结点*/
    return 1;
}
int GetTop(LinkStack top,DataType *e)
/*取栈顶元素。取栈顶元素成功返回1，否则返回0*/
{
    LStackNode *p;
    p=top->next; 					/*指针p指向栈顶结点*/
    if(!p)
	{
        printf("栈已空");
        return 0;
	}
	*e=p->data; 					/*将p指向的结点元素赋值给e*/
	return 1;
}
int StackLength(LinkStack top)
/*求表长操作。依次从栈顶指针开始，通过结点的指针域访问每一个结点，并计数，返回表的长度值*/
{
    LStackNode *p;
    int count=0; 						/*定义一个计数器，并初始化为0*/
    p=top; 							/*p指向栈顶指针*/
    while(p->next!=NULL) 				/*如果栈中还有结点*/
    {
        p=p->next; 						/*依次访问栈中的结点*/
        count++;						/*每次找到一个结点，计数器累加1*/
    }
    return count; 						/*返回栈的长度*/
}
void DestroyStack(LinkStack top)
/*销毁链栈*/
{
    LStackNode *p,*q;
    p=top;
    while(!p) 							/*如果栈还有结点*/
	{
		q=p; 							/*q就是要释放的结点*/
		p=p->next; 						/*p指向下一个结点，即下一次要释放的结点*/
		free(q); 						/*释放q指向的结点空间*/
    }
}
void ClearStack(LinkStack top)
/*销毁链栈*/
{
    LStackNode *p,*q;
    p=top->next;
    while(!p) 							/*如果栈还有结点*/
	{
		q=p; 							/*q就是要释放的结点*/
		p=p->next; 						/*p指向下一个结点，即下一次要释放的结点*/
		free(q); 						/*释放q指向的结点空间*/
    }
}