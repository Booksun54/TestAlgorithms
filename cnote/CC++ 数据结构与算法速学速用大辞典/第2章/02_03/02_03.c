#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
typedef struct node
{
    DataType data;
    struct node *next;
}LStackNode,*LinkStack;
void Coversion(int N)
/*利用链表模拟栈将十进制数转换为八进制数*/
{
	LStackNode *p,*top=NULL; 		/*定义指向结点的指针和栈顶指针top，并初始化栈为空*/
    do
    {
        p=(LStackNode*)malloc(sizeof(LStackNode));	/*动态生成新结点*/
        p->data=N%8;							/*将余数送入新结点的数据域*/
        p->next=top; 							/*将新结点插入到原栈顶结点之前，使其成为新的栈顶*/
		top=p;									/*栈顶指针指向刚插入链表的结点，成为栈顶*/
        N=N/8;
    }while(N!=0);
	while(top!=NULL)							/*如果栈不空，从栈顶开始输出栈顶元素*/
	{
		p=top;									/*p指向栈顶*/
        printf("%d",p->data); 						/*输出栈顶元素*/
        top=top->next; 							/*栈顶结点元素出栈*/
        free(p); 								/*释放栈顶结点*/
	}
}
void main()
{
	int n;
    printf("请输入一个十进制数:\n");
	scanf("%d",&n);
	printf("转换后的八进制数为:\n");
	Coversion(n);
	printf("\n");
}