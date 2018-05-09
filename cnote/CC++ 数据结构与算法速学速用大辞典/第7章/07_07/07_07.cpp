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
void  CreateBitTree(BiTree *T,char str[]);
void PrintLevel(BiTree T);
void SwapSubTree(BiTree *T);
void SwapSubTree(BiTree *T)
//交换左右子树
{
    BitNode *temp;
	if((*T))
	{
		//交换左右子树指针
		temp=(*T)->lchild;
		(*T)->lchild=(*T)->rchild;
		(*T)->rchild=temp;	
		SwapSubTree(&((*T)->lchild));
		SwapSubTree(&((*T)->rchild));
	}
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
	char str[MAXSIZE];
	cout<<"请输入二叉树的广义表形式："<<endl;
	cin>>str;
	cout<<"由广义表形式的字符串构造二叉树："<<endl;
	CreateBitTree(&T,str);
	cout<<endl<<"左右子树交互前的二叉树："<<endl;
	TreePrint(T,1);
	SwapSubTree(&T);
	cout<<endl<<"左右子树交互后的二叉树："<<endl;
	TreePrint(T,1);
}
