#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<iostream.h>
typedef char DataType;
typedef struct Node				/*二叉链表存储结构类型定义*/
{
	DataType data;			 	/*数据域*/
	struct Node *lchild; 			/*指向左孩子结点*/
	struct Node *rchild; 			/*指向右孩子结点*/
}*BiTree,BitNode;
void CreateBitTree(BiTree *T);
void PreOrderTraverse(BiTree T);	/*二叉树的先序遍历的递归函数声明*/
void InOrderTraverse(BiTree T);		/*二叉树的中序遍历的递归函数声明*/
void PostOrderTraverse(BiTree T);	/*二叉树的后序遍历的递归函数声明*/
void InitBitTree(BiTree *T);
void DestroyBitTree(BiTree *T);
void main()
{
	BiTree T;
	InitBitTree(&T);
	cout<<"根据输入二叉树的先序序列创建二叉树('#'表示为空)："<<endl;
	CreateBitTree(&T);
	cout<<"二叉树的先序序列："<<endl;
	PreOrderTraverse(T);
	printf("\n");
	cout<<"二叉树的中序序列："<<endl;
	InOrderTraverse(T);
	printf("\n");
	cout<<"二叉树的后序序列："<<endl;
	PostOrderTraverse(T);
	cout<<endl;
	DestroyBitTree(&T);
}
void CreateBitTree(BiTree *T)
/*创建二叉树的递归实现*/
{ 
    DataType ch;
    scanf("%c",&ch);
    if(ch=='#') 
        *T=NULL;
    else
    {
        *T=(BiTree)malloc(sizeof(BitNode)); 		/*生成根结点*/
        if(!(*T))
            exit(-1);
        (*T)->data=ch;
        CreateBitTree(&((*T)->lchild)); 			/*构造左子树*/
        CreateBitTree(&((*T)->rchild)); 			/*构造右子树*/
    }
}
void DestroyBitTree(BiTree *T)
/*销毁二叉树*/
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
void InitBitTree(BiTree *T)
/*二叉树的初始化操作*/
{
	*T=NULL;
}
void PreOrderTraverse(BiTree T)
/*先序遍历二叉树的递归实现*/
{
    if(T)								/*如果二叉树不为空*/
    {
        printf("%2c",T->data); 				/*访问根结点*/
        PreOrderTraverse(T->lchild);		/*先序遍历左子树*/
        PreOrderTraverse(T->rchild); 		/*先序遍历右子树*/
    }
}
void InOrderTraverse(BiTree T)
/*中序遍历二叉树的递归实现*/
{
    if(T)								/*如果二叉树不为空*/
	{
		InOrderTraverse(T->lchild);			/*中序遍历左子树*/
        printf("%2c",T->data); 				/*访问根结点*/
        InOrderTraverse(T->rchild); 		/*中序遍历右子树*/
    }
}
void PostOrderTraverse(BiTree T)
/*后序遍历二叉树的递归实现*/
{
    if(T)								/*如果二叉树不为空*/
	{
		PostOrderTraverse(T->lchild);		/*后序遍历左子树*/
        PostOrderTraverse(T->rchild); 		/*后序遍历右子树*/
		printf("%2c",T->data); 				/*访问根结点*/
    }
}