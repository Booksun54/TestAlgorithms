#include <stdio.h>
#include <stdlib.h>
#include<iostream.h>
#include <assert.h>
typedef struct node
{
	struct node* fch;
	char data;
	struct node* nsib;
	int level;
} NODE;
typedef NODE* TREE;
#define SET(pos, c, l) \
{\
	pos = (NODE*)malloc(sizeof(NODE));\
	pos->data = c;\
	pos->level = l;\
	pos->fch = NULL;\
	pos->nsib = NULL;\
	return pos;\
}
void Display(TREE tree);
void ListPrintTree(TREE T);
TREE InitTree()
{
	TREE tree;
	SET(tree, '\0', 0);
}
void ReleaseTree(TREE tree)
{
	assert(tree);
	if (tree->fch != NULL) 
		ReleaseTree(tree->fch);
	if (tree->nsib != NULL) 
		ReleaseTree(tree->nsib);
	free(tree);
}
TREE Insert(TREE tree, char data, int level)
{
	assert(tree);
	if (tree->level == level - 1) 
		SET(tree->fch, data, level);
	if (tree->level == level) 
		SET(tree->nsib, data, level);
	return NULL;
}
void main()
{
	TREE T = InitTree(), temp1, temp2, temp3, temp4;
	temp1 = Insert(T, 'A', 1);
	temp2 = Insert(temp1, 'B', 2);
	temp3 = Insert(temp2, 'C', 2);
	Insert(temp3, 'D', 2);
	temp4 = Insert(temp2, 'E', 3);
	Insert(temp4, 'F', 3);
	Insert(temp3, 'G', 3);
	cout<<"树的各条边分别是:"<<endl;
	Display(T->fch);
	cout<<endl;
	cout<<"以广义表形式输出树结构:\n";
	ListPrintTree(T);
	cout<<endl;
	ReleaseTree(T);
}
void Display(TREE tree)
//输出树中的各条边
{
	NODE* p;
	if (tree == NULL) 
		return;
	if (tree->fch != NULL)//如果有子树
	{
		//输出全部边
		for (p = tree->fch; p != NULL; p = p->nsib) 
			cout<<tree->data<<p->data<<",";
	}
	//输出兄弟的全部边
	if (tree->nsib != NULL) 
		Display(tree->nsib);
	//进入下一层
	if (tree->fch != NULL) 
		Display(tree->fch);
}
void ListPrintTree(TREE T)
//以广义表形式输出树结构
{
	TREE p;
	if(T==NULL)
		return;
	cout<<T->data;
	p=T->fch;
	if(p!=NULL)
	{
		cout<<"(";
		ListPrintTree(p);
		p=p->nsib;
		while(p!=NULL)
		{
			cout<<",";
			ListPrintTree(p);
			p=p->nsib;
		}
		cout<<")";
	}
}