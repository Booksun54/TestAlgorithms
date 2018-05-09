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
#include"LinkBiTree.h"
void CreateBitTree(BiTree *T,char str[]);	/*利用括号嵌套的字符串建立二叉树的函数声明*/
void LevelTraverse(BiTree T);
void main()
{
	BiTree root;
	cout<<"根据广义表输入形式(A(B(C,D),E(F(,G),H(I)))建立二叉树:"<<endl;
	CreateBitTree(&root,"(A(B(C,D),E(F(,G),H(I)))");
	cout<<"树状显示二叉树:"<<endl;
	TreePrint(root,0);
	cout<<"层次遍历二叉树:"<<endl;
	LevelTraverse(root);
	cout<<endl;
	DestroyBitTree(&root);
}
void LevelTraverse(BiTree T)
/*层次输出二叉树中的结点*/
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
        cout<<setw(3)<<p->data;					/*输出根结点*/
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