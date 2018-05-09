#include<iostream.h>
#include<malloc.h>
#include<stdio.h>
typedef char DataType;
#define  MAXSIZE 200
typedef struct BiTnode
{
	DataType data;
	struct  BiTnode *lchild,*rchild;
}*BiTree,BitNode;
int CreateBiTree(BiTree *T, DataType *str);
void DispBTNode(BiTree T);
int CreateBiTree(BiTree *T, DataType *str)
{    
	BiTree S[MAXSIZE],  p=NULL;   //顺序栈
	int top=0,k=0,j=0;
	char ch;              //top栈顶指针
	*T=NULL;	         //二叉树初始时为空
	ch=str[j];
	while (ch!='@')//扫描广义表中的字符
	{ 	                          
		switch(ch)
		{
		case '(':  //进入到下一层，可能为左孩子结点
			S[top++]=p; 
			k=1;
			break;
		case ')'://回到上一层
			top--;
			break;
		case ',':  //为右孩子结点  
			k=2;
			break;                 
		default:
			p=(BiTree)malloc(sizeof(BitNode));
			p->data=ch; 
			p->lchild=p->rchild=NULL;
			if (*T==NULL) //根结点 
				*T=p;       //创建根结点                                                    
			else//已建立二叉树根结点
			{                              
				switch(k)//根据k值建立与栈顶结点的关系
				{                               
				case 1:  
					S[top-1]->lchild=p; 
					break;
				case 2:   
					S[top-1]->rchild=p; 
					break;
				}
			}
			break;
		}
		ch=str[++j];   //读下一个字符
	}
	return 1;
} 
void main()
{
	int n,len=0;
	char ch,str[MAXSIZE];
	BiTree T;
	cout<<"输入广义表,以'@'结束："<<endl;
	while((ch=getchar())!='\n')
	{
		str[len++]=ch;
	}
    n= CreateBiTree(&T,str);
    if(n==1) 
		cout<<"创建成功."<<endl;
	else 
		cout<<"创建失败."<<endl;
	DispBTNode(T);
}
void DispBTNode(BiTree T)
{
	BitNode *qu[MAXSIZE];
	BitNode *p;
	int front,rear,n;
	n = 0;	//初始化层号
	front=rear=0;
	qu[rear++]=NULL;
	p = T;
	if (p != NULL)
	{
		qu[rear ++] = p;
	}
	do
	{
		p = qu[front ++];
		if (p == NULL)
		{
			qu[rear++] = NULL;			//队列中进入空指针作为分层标志
			n++;	//层号加1
			printf("\n");
		}
		else
		{
			cout<<"第"<<n<<"层:"<<p->data<<endl;
			if (p->lchild != NULL)
			{
				qu[rear++] = p->lchild;
			}
			if (p->rchild != NULL)
			{
				qu[rear++] = p->rchild;
			}
		}
	} while (front!=rear-1);
}

void level_order(BiTree T)
{
    BiTree  ptr ,tree[MAXSIZE];
	int i,front=-1,rear=0;
	for(i=0;i<MAXSIZE;i++)
		tree[i]=NULL;
    ptr=T;
	while(ptr!=NULL)
	{
		cout<<ptr->data;
		if(ptr->lchild!=NULL)tree[rear++]=ptr->lchild;
		if(ptr->lchild!=NULL)tree[rear++]=ptr->rchild;
		if(front!=rear)ptr=tree[++front];
	}
}