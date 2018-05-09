#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include<iostream.h>
#define MAXSIZE 100
typedef struct Node
{ 
	char data;
	struct Node * lchild,*rchild;
}BitNode,*BiTree;
#include"BiTreeQueue.h"
void  CreateBitTree(BiTree *T,char str[]);
void PrintLevel(BiTree T);
int JudgeComplete(BiTree T)
//判断是否为完全二叉树
{
	int tag=0;//标志
	BiTree p=T;
	Queue Q;//队列Q中存放结点的指针
	if(p==NULL)//若为空二叉树，则直接返回1
		return 1;
	InitQueue(&Q);//初始化队列
	EnQueue(&Q,p);//根结点指针入队
	while(!QueueEmpty(Q))//队列不为空
	{
		DeQueue(&Q,&p);//将队头指针出队
		if(p->lchild && !tag)//若左孩子存在
			EnQueue(&Q,p->lchild);//则将左孩子入队
		else if(p->lchild)//若前面有结点为空，而该结点不为空
			return 0;//则说明不是完全二叉树
		else//若出现结点为空
			tag=1;//标志置为1
		if(p->rchild && !tag)//若右孩子存在
			EnQueue(&Q,p->rchild);//将右孩子指针入队
		else if(p->rchild)//右孩子存在，但前面有结点为空
			return 0;//则说明不是完全二叉树
		else//若出现结点为空
			tag=1;//标志置为1
	}
	ClearQueue(&Q);//清空队列
	return 1;//返回1表示为完全二叉树
}
void  CreateBitTree(BiTree *T,char str[])
/*利用括号嵌套的字符串建立二叉链表*/
{
	char ch;
	BiTree stack[MAXSIZE];	/*定义栈，用于存放指向二叉树中结点的指针*/
	int top=-1;				/*初始化栈顶指针*/
	int flag,k;
	BitNode *p;
	*T=NULL,k=0;
	ch=str[k];
	while(ch!='\0')		/*如果字符串没有结束*/
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
			if(*T==NULL)/*如果是第一个结点，表示是根结点*/
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
void main()
{  
	BiTree T;
	int flag;
	char str[MAXSIZE];
	cout<<"请输入二叉树的广义表形式："<<endl;
	cin>>str;
	cout<<"由广义表形式的字符串构造二叉树："<<endl;
	CreateBitTree(&T,str);
	TreePrint(T,1);
	flag=JudgeComplete(T);
	if(flag)
		cout<<"是完全二叉树!"<<endl;
	else
		cout<<"不是完全二叉树!"<<endl;
	cout<<"请输入二叉树的广义表形式："<<endl;
	cin>>str;
	cout<<"由广义表形式的字符串构造二叉树："<<endl;
	CreateBitTree(&T,str);
	TreePrint(T,1);
	flag=JudgeComplete(T);
	if(flag)
		cout<<"是完全二叉树!"<<endl;
	else
		cout<<"不是完全二叉树!"<<endl;
}
