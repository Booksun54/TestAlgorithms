#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include<iostream.h>
#define MAXSIZE 100
typedef char DataType;
typedef struct Node
{ 
	DataType data;
	struct Node * lchild,*rchild;
}BitNode,*BiTree;
void TreePrint(BiTree T,int level);
BiTree CreateBitTree();
int Degrees1(BitNode *T);
int Degrees0(BitNode *T);
BiTree CreateBitTree()
/*利用先序输入方式创建二叉树*/
{
	DataType ch;
	BiTree bt;
	scanf("%c",&ch);
	if(ch=='#')
		bt=NULL;
	else
	{
		bt=(BitNode*)malloc(sizeof(BitNode));
		bt->data=ch;
		bt->lchild=CreateBitTree();
		bt->rchild=CreateBitTree();
	}
	return bt;
}
int Degrees1(BitNode *T)
//求二叉树中度为1的结点个数
{
	if(T==NULL)//空二叉树
		return 0;//度为1的结点为0
	if(T->lchild !=NULL && T->rchild==NULL || T->lchild ==NULL && T->rchild!=NULL)//若只有左子树或右子树
		return 1 + Degrees1(T->lchild) + Degrees1(T->rchild);//则该结点度为1，且求左子树和右子树的度为1的结点个数之和
	return  Degrees1(T->lchild) + Degrees1(T->rchild);//其他情况就是求左右子树度为1的结点个数之和
}
int Degrees0(BiTree T)
/*求二叉树中度为0的结点个数*/
{
    if(!T)										/*如果是空二叉树，返回0*/
		return 0;
    else 
		if(!T->lchild&&!T->rchild)					/*如果左子树和右子树都为空，返回1*/
			return 1;
		else 
			return Degrees0(T->lchild)+Degrees0(T->rchild); 	/*把左子树叶子结点个数与右子树叶子结点个数相加*/
}
void TreePrint(BiTree T,int level) 
/*按树状打印的二叉树*/ 
{   
	int i;
	if(T==NULL)									/*如果指针为空，返回上一层*/ 
		return;
	TreePrint(T->rchild,level+1);				/*打印右子树，并将层次加1*/ 
	for(i=0;i<level;i++)						/*按照递归的层次打印空格*/ 
		cout<<"   ";
	cout<<T->data<<endl;						/*输出根结点*/ 
	TreePrint(T->lchild,level+1);				/*打印左子树，并将层次加1*/ 
}
void main()
{  
	BiTree T;
	cout<<"请按照先序方式输入二叉树的结点元素："<<endl;
	T=CreateBitTree();
	cout<<"创建的二叉树："<<endl;
	TreePrint(T,1);
	cout<<"度为0的结点个数:"<<Degrees0(T)<<endl;
	cout<<"度为1的结点个数:"<<Degrees1(T)<<endl;
}
