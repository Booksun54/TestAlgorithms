#include<stdio.h>
#include<malloc.h>
typedef struct Node	/*二叉排序树的类型定义*/
{
	int data;
	struct Node *lchild,*rchild;
}BiTreeNode,*BiTree;
BiTree BSTSearch(BiTree T,int x);
int BSTInsert(BiTree *T,int x);
void InOrderTraverse(BiTree T);
void main()
{
	BiTree T=NULL,p;
	int table[]={55,33,44,66,99,77,88,22,11};
	int n=sizeof(table)/sizeof(table[0]);
	int x,i;
	for(i=0;i<n;i++)
		BSTInsert(&T,table[i]);
	printf("中序遍历二叉排序树得到的序列为:\n");
	InOrderTraverse(T);
	printf("\n请输入要查找的元素:");
	scanf("%d",&x);
	p=BSTSearch(T,x);
	if(p!=NULL)
		printf("二叉排序树查找:元素%d查找成功.\n",x);
	else
		printf("二叉排序树查找:没有找到元素%d.\n",x);
}
BiTree BSTSearch(BiTree T,int x)
/*二叉排序树的查找操作。
如果找到元素x，则返回指向结点的指针，否则返回NULL*/
{
	BiTreeNode *p;
	if(T!=NULL)						/*如果二叉排序树不为空*/
	{
		p=T;
		while(p!=NULL)
		{
			if(p->data==x)	/*如果找到，则返回指向该结点的指针*/
				return p;
			else if(x<p->data)	/*如果关键字小于p指向的结点的值，则在左子树中查找*/
				p=p->lchild;
			else
				p=p->rchild;	/*如果关键字大于p指向的结点的值，则在右子树中查找*/
		}
	}
	return NULL;
}
int BSTInsert(BiTree *T,int x)
/*二叉排序树的插入操作.
如果树中不存在元素x，则将x插入到正确的位置并返回1，否则返回0*/
{
	BiTreeNode *p,*cur,*parent=NULL;
	cur=*T;
	while(cur!=NULL)
	{
		if(cur->data==x)	/*如果二叉树中存在元素为x的结点，则返回0*/
			return 0;
		parent=cur;				/*parent指向cur的前驱结点*/
		if(x<cur->data)		/*如果关键字小于p指向的结点的值，则在左子树中查找*/
			cur=cur->lchild;
		else
			cur=cur->rchild;			/*如果关键字大于p指向的结点的值，则在右子树中查找*/
	}
	p=(BiTreeNode*)malloc(sizeof(BiTreeNode));	/*生成结点*/
	if(!p)
		exit(-1);
	p->data=x;
	p->lchild=NULL;
	p->rchild=NULL;
	if(!parent)						/*如果二叉树为空，则第一结点成为根结点*/
		*T=p;
	else if(x<parent->data)		/*如果x小于parent指向的结点元素，则将x成为parent的左孩子*/
		parent->lchild=p;
	else						/*如果x大于parent指向的结点元素，则将x成为parent的右孩子*/
		parent->rchild=p;
	return 1;	
}
void InOrderTraverse(BiTree T)
/*中序遍历二叉排序树*/
{
    if(T)								/*如果二叉排序树不为空*/
	{
		InOrderTraverse(T->lchild);		/*中序遍历左子树*/
        printf("%4d",T->data); 			/*访问根结点*/
        InOrderTraverse(T->rchild); 	/*中序遍历右子树*/
    }
}
