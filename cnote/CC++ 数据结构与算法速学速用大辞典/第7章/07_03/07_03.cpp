#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<iostream.h>
#include<iomanip.h>
typedef char DataType;
#define MAXSIZE 100				
typedef struct Node				/*二叉链表存储结构类型定义*/
{
	DataType data;			 	/*数据域*/
	struct Node *lchild; 		/*指向左孩子结点*/
	struct Node *rchild; 		/*指向右孩子结点*/
}*BiTree,BitNode;
void CreateBitTree(BiTree *T,char str[]);	/*利用括号嵌套的字符串建立二叉树的函数声明*/
void TreePrint(BiTree T,int nLayer);
void PreOrderTraverse(BiTree T);
void DestroyBitTree(BiTree *T);
void main()
{
	BiTree root;
	cout<<"根据广义表输入形式(A(B(C,D),E(F(,G),H(I)))建立二叉树:"<<endl;
	CreateBitTree(&root,"(A(B(C,D),E(F(,G),H(I)))");
	cout<<"树状显示二叉树:"<<endl;
	TreePrint(root,0);
	cout<<"先序遍历二叉树:"<<endl;
	PreOrderTraverse(root);
	cout<<endl;
	DestroyBitTree(&root);
}
void PreOrderTraverse(BiTree T)
/*先序遍历二叉树的非递归实现*/
{
	BiTree stack[MAXSIZE]; 				/*定义一个栈，用于存放结点的指针*/
	int top; 							/*定义栈顶指针*/
	BitNode *p; 						/*定义一个结点的指针*/
	top=0;							/*初始化栈*/
	p=T;
	while(p!=NULL||top>0)
	{
		while(p!=NULL) 					/*如果p不空，访问根结点，遍历左子树*/
		{
			cout<<setw(3)<<p->data; 	/*访问根结点*/
			stack[top++]=p; 				/*将p入栈*/
			p=p->lchild; 				/*遍历左子树*/
		}
		if(top>0) 						/*如果栈不空*/
		{
			p=stack[--top]; 				/*栈顶元素出栈*/
			p=p->rchild;					/*遍历右子树*/
		}
	}
}
void TreePrint(BiTree T,int level) 
/*按树状打印的二叉树*/ 
{   
	int i;
	if(T==NULL)									/*如果指针为空，返回上一层*/ 
		return;
	TreePrint(T->rchild,level+1);				/*打印右子树，并将层次加1*/ 
	for(i=0;i<level;i++)						/*按照递归的层次打印空格*/ 
		printf("   ");
	printf("%c\n",T->data);						/*输出根结点*/ 
	TreePrint(T->lchild,level+1);				/*打印左子树，并将层次加1*/ 
}

void  CreateBitTree(BiTree *T,char str[])
/*利用括号嵌套的字符串建立二叉链表*/
{
	char ch;
	BiTree stack[MAXSIZE];			/*定义栈，用于存放指向二叉树中结点的指针*/
	int top=-1;						/*初始化栈顶指针*/
	int flag,k;
	BitNode *p;
	*T=NULL,k=0;
	ch=str[k];
	while(ch!='\0')					/*如果字符串没有结束*/
	{
		switch(ch)
		{
		case '(':
			stack[++top]=p;
			flag=1;
			break;
		case ')':
			top--;
			break;
		case ',':
			flag=2;
			break;
		default:
			p=(BiTree)malloc(sizeof(BitNode));
			p->data=ch;
			p->lchild=NULL;
			p->rchild=NULL;
			if(*T==NULL)		/*如果是第一个结点，表示是根结点*/
				*T=p;
			else
			{
				switch(flag)
				{
				case 1:
					stack[top]->lchild=p;
					break;
				case 2:
					stack[top]->rchild=p;
					break;
				}
			}
		}
		ch=str[++k];
	}
}
void DestroyBitTree(BiTree *T)
/*销毁二叉树操作*/
{
	if(*T) 							/*如果是非空二叉树*/
	{
		if((*T)->lchild)
			DestroyBitTree(&((*T)->lchild));
		if((*T)->rchild)
			DestroyBitTree(&((*T)->rchild));
		free(*T);
		*T=NULL;
	}
}
void LevelPrint(BiTree T)
/*按层次打印二叉树中的结点*/
{ 
    BiTree queue[MAXSIZE];						/*定义一个队列，用于存放结点的指针*/
	BitNode *p;
    int front,rear;								/*定义队列的队头指针和队尾指针*/
    front=rear=-1;								/*队列初始化为空*/
    rear++;										/*队尾指针加1*/
    queue[rear]=T;								/*将根结点指针入队*/
    while(front!=rear)							/*如果队列不为空*/
    {
        front=(front+1)%MAXSIZE;
        p=queue[front];							/*取出队头元素*/
        printf("%c ",p->data);					/*输出根结点*/
        if(p->lchild!=NULL)						/*如果左孩子不为空，将左孩子结点指针入队*/
        {
            rear=(rear+1)%MAXSIZE;
            queue[rear]=p->lchild;
        }   
        if(p->rchild!=NULL)						/*如果右孩子不为空，将右孩子结点指针入队*/
        {
            rear=(rear+1)%MAXSIZE;
            queue[rear]=p->rchild;
        }     
    }    
}