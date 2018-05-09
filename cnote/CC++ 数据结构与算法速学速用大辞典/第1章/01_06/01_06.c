#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
/*单链表类型定义*/
typedef int DataType;
#include"LinkList.h"					/*单链表基本操作实现文件*/
void Sort(LinkList S);
void DispList( LinkList S);
void Interction(LinkList A,LinkList B,LinkList *C);	/*求A和B的交集的函数声明*/
void main()
{
	int i;
	DataType a[]={21,35,8,23,87,101,57,99};
	DataType b[]={44,57,12,63,35,23,56,99,88,72};
	LinkList A,B,C;					/*声明单链表A、B和C*/
	ListNode *p;
	InitList(&A);					/*初始化单链表A*/
	InitList(&B);					/*初始化单链表B*/
	for(i=1;i<=sizeof(a)/sizeof(a[0]);i++)	/*将数组a中元素插入到单链表A中*/
	{
		if(InsertList(A,i,a[i-1])==0)
		{
			printf("位置不合法");
			return;
		}
	}
	for(i=1;i<=sizeof(b)/sizeof(b[0]);i++)	/*将数组b中元素插入单链表B中*/
	{
		if(InsertList(B,i,b[i-1])==0)
		{
			printf("位置不合法");
			return;
		}
	}
	printf("单链表A中的元素有%d个：\n",ListLength(A));
	for(i=1;i<=ListLength(A);i++)	/*输出单链表A中的每个元素*/
	{
		p=Get(A,i);					/*返回单链表A中的每个结点的指针*/
		if(p)
			printf("%4d",p->data);	/*输出单链表A中的每个元素*/
	}
	printf("\n");
	printf("单链表B中的元素有%d个：\n",ListLength(B));
	for(i=1;i<=ListLength(B);i++)	
	{
		p=Get(B,i);					/*返回单链表B中的每个每个结点的指针*/
		if(p)
			printf("%4d",p->data);	/*输出单链表B中的每个元素*/
	}
	printf("\n");
	Interction(A,B,&C);					/*求A和B的交集*/
	printf("A和B的交集有%d个元素：\n",ListLength(C));
	for(i=1;i<=ListLength(C);i++)		
	{
		p=Get(C,i);					/*返回单链表C中每个结点的指针*/
		if(p)
			printf("%4d",p->data);	/*显示输出C中所有元素*/
	}
	printf("\n");
}
void Interction(LinkList A,LinkList B,LinkList *C)
/*求A和B的交集*/
{
	ListNode *pa,*pb,*pc;
	Sort(A);
	printf("排序后A中的元素:\n");
	DispList(A);
	Sort(B);
	printf("排序后B中的元素:\n");
	DispList(B);
	pa=A->next;
	pb=B->next;
	*C=(LinkList)malloc(sizeof(ListNode));
	(*C)->next=NULL;
	while(pa&&pb)
	{
		if(pa->data<pb->data)
			pa=pa->next;
		else if(pa->data>pb->data)
			pb=pb->next;
		else
		{
			pc=(ListNode*)malloc(sizeof(ListNode));
			pc->data=pa->data;
			pc->next=(*C)->next;
			(*C)->next=pc;
			pa=pa->next;
			pb=pb->next;
		}
	}
}
void Sort(LinkList S)
/*利用选择排序法对链表S进行从小到大排序*/
{
	ListNode *p,*q,*r;
	DataType t;
	p=S->next;
	while(p->next)
	{
		r=p;
		q=p->next;
		while(q)
		{
			if(r->data>q->data)
				r=q;
			q=q->next;
		}
		if(p!=r)
		{
			t=p->data;
			p->data=r->data;
			r->data=t;
		}
		p=p->next;
	}	
}
void DispList(LinkList S)
/*输出链表*/
{
	ListNode *p,*q;
	p=S->next;
	while(p)
	{
		q=p;
		printf("%4d",p->data);
		p=p->next;
	}
	printf("\n");
}