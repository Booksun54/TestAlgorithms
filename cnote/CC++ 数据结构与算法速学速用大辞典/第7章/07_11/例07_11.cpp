#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include<iostream.h>
#include<iomanip.h>
typedef char DataType;
#define MAXSIZE 100
typedef struct Node
{ 
    DataType data;
    struct Node * lchild,*rchild;
}BitNode,*BiTree;
void  CreateBitTree(BiTree *T,char str[]);
void PrintLevel(BiTree T);
void  CreateBitTree(BiTree *T,char str[])
/*利用括号嵌套法建立二叉链表*/
{
    char ch;
    BiTree stack[MAXSIZE]; /*栈用于存放指向二叉树中结点的指针*/
    int top=-1;    		  /*初始化栈顶指针*/
    int flag,k;
    BitNode *p;
    *T=NULL,k=0;
    ch=str[k];
    while(ch!='\0')		  /*如果字符串没有结束*/
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
    if(T==NULL)/*如果指针为空，返回上一层*/ 
        return;
    TreePrint(T->rchild,level+1);/*打印右子树，并将层次加1*/ 
    for(i=0;i<level;i++)		/*按照递归的层次打印空格*/ 
        printf("   ");
    printf("%c\n",T->data);	/*输出根结点*/ 
    TreePrint(T->lchild,level+1);/*打印左子树，并将层次加1*/ 
}
void Path(BiTree root, BitNode *r)
//输出从root到r之间路径上的结点
{
    BitNode *p,*q;
    int i,top=0;
    BitNode *s[MAXSIZE];
    q=NULL;
    p=root;
    while(p!=NULL||top!=0)
    {
        while(p!=NULL)
            /*遍历左子树*/
        {
            top++;
            if(top>=MAXSIZE)
                exit(-1);
            s[top]=p;
            p=p->lchild;
        }
        if(top>0)/*若栈不为空*/
        {
            p=s[top]; 
            if(p->rchild == NULL || p->rchild==q) /*根结点*/
            {
                if(p==r) /*找到r所指结点，则输出从根结点到r所指结点之间的结点*/
                {
                    for(i=1;i<=top;i++)
                        cout<<setw(4)<<s[i]->data;
                    top=0;p=NULL;/*将栈置为空且p=NULL，目的是为了退出整个循环*/
                }
                else
                {
                    q=p; 		/*用q保存刚刚遍历过的结点*/
                    top--; 		/*将栈顶指针退栈，回到上一层*/
                    p=NULL;
                }
            }
            else
                p=p->rchild;	/*遍历右子树*/
        }
    }
}
BiTree FindPointer(BiTree T,DataType e)
/*查找元素值为e的结点的指针*/
{
    BiTree Q[MAXSIZE]; 		/*队列用于存放二叉树中结点的指针*/
    int front=0,rear=0; 		/*初始化队列*/
    BitNode *p;
    if(T) 					/*如果二叉树非空*/
    {
        Q[rear]=T;
        rear++;
        while(front!=rear) 	/*如果队列非空*/
        {
            p=Q[front]; 		/*取出队头指针*/
            front++;			/*将队头指针出队*/
            if(p->data==e)
                return p;
            if(p->lchild)		/*若存在左孩子，将左孩子指针入队*/
            {
                Q[rear]=p->lchild;	/*左孩子结点的指针入队*/
                rear++;
            }
            if(p->rchild)		/*若存在右孩子，将右孩子指针入队*/
            {
                Q[rear]=p->rchild; /*右孩子结点的指针入队*/
                rear++;
            }
        }
    }
    return NULL;
}
void main()
{  
    BiTree T;
    BitNode *s;
    DataType e;
    char str[MAXSIZE];
    cout<<"请输入二叉树的广义表形式："<<endl;
    cin>>str;
    cout<<"由广义表形式的字符串构造二叉树："<<endl;
    CreateBitTree(&T,str);
    TreePrint(T,1);
    cout<<"请输入一个结点："<<endl;
    cin>>e;
    s=FindPointer(T,e);
    cout<<"从根结点到结点元素"<<e<<"之间路径上的结点为:"<<endl;
    Path(T,s);    
    cout<<endl;
}