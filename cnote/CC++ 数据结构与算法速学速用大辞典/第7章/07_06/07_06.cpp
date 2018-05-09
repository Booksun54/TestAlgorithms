#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include<conio.h>
#define MAXSIZE 100
typedef struct Node
{ 
	char data;
	struct Node * lchild,*rchild;
}BitNode,*BiTree;
void CreateBiTree(BiTree *T,char *in,char *post,int len);
void PrintLevel(BiTree T);
void PrintTLR(BiTree T);
void PrintLRT(BiTree T);
void PrintLevel(BiTree T)
/*层次输出二叉树的结点*/
{ 
	BiTree Queue[MAXSIZE];
	int front,rear;
	if(T==NULL) 
		return;
	front=-1;							/*初始化化队列*/
	rear=0;
	Queue[rear]=T;
	while(front!=rear)					/*如果队列不空*/
	{ 
		front++;						/*将队头元素出队*/
		printf("%4c",Queue[front]->data);/*输出队头元素*/
		if(Queue[front]->lchild!=NULL)	/*如果队头元素的左孩子结点不为空，则将左孩子入队*/
		{
			rear++;
			Queue[rear]=Queue[front]->lchild;
		}
		if(Queue[front]->rchild!=NULL)	/*如果队头元素的右孩子结点不为空，则将右孩子入队*/
		{
			rear++;
			Queue[rear]=Queue[front]->rchild;
		}
	}
}
void PreTraverse(BiTree T)
/*先序输出二叉树的结点*/
{ 
	if(T!=NULL)
	{ 
		printf("%4c ",T->data);	/*输出根结点*/
		PreTraverse(T->lchild);	/*先序遍历左子树*/
		PreTraverse(T->rchild);	/*先序遍历右子树*/
	}
}
void CreateBiTree(BiTree *T,char *in,char *post,int len) 
/*由中序序列和后序序列构造二叉树*/
{
	
	int k;
	char *temp;
	if(len<=0)
	{
		*T=NULL;
		return;
	}
	for(temp=in;temp<in+len;temp++) /*在中序序列in中找到根结点所在的位置*/
		if(*(post+len-1)==*temp)
		{
			k=temp-in;				/*左子树的长度*/
			(*T)=(BitNode*)malloc(sizeof(BitNode));
			(*T)->data =*temp;
			break;
		}
	CreateBiTree(&((*T)->lchild),in,post,k);				/*建立左子树*/
	CreateBiTree(&((*T)->rchild),in+k+1,post+k,len-k-1); /*建立右子树*/		
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
	BiTree T,ptr=NULL;
	int len;
	char in[MAXSIZE],post[MAXSIZE];
	printf("由中序序列和后序序列构造二叉树：\n");
	printf("请你输入中序的字符串序列：");
	gets(in);
	printf("请你输入后序的字符串序列：");
	gets(post);
	len=strlen(post);
	CreateBiTree(&T,in,post,len);
	TreePrint(T,1);
	printf("\n你建立的二叉树先序遍历结果是：\n");
	PreTraverse(T);
	printf("\n你建立的二叉树层次遍历结果是：\n");
	PrintLevel(T);
	printf("\n");
}
