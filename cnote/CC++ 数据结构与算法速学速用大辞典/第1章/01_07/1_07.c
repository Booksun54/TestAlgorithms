#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef int DataType;
#include"LinkList.h"					/*包含单链表实现文件*/
void DelElem(LinkList A,LinkList B);	/*删除A中出现B的元素的函数声明*/
void SortList(LinkList S);
ListNode *Append(ListNode *last,DataType e);
ListNode *Difference(ListNode *A,ListNode *B);
void main()
{
	int i;
	DataType a[]={22,7,15,56,89,38,44,65,109,83};
	DataType b[]={15,9,22,89,33,65,90,83};
	LinkList A,B,C;					/*声明单链表A、B、C*/
	ListNode *p;
	InitList(&A);					/*初始化单链表A*/
	InitList(&B);					/*初始化单链表B*/
	/*将数组a中元素插入到单链表A中*/
	for(i=1;i<=sizeof(a)/sizeof(a[0]);i++)
	{
		if(InsertList(A,i,a[i-1])==0)
		{
			printf("位置不合法");
			return;
		}
	}
	/*将数组b中元素插入单链表B中*/
	for(i=1;i<=sizeof(b)/sizeof(b[0]);i++)
	{
		if(InsertList(B,i,b[i-1])==0)
		{
			printf("位置不合法");
			return;
		}
	}
	printf("单链表A中的元素有%d个：\n",ListLength(A));
	p=A->next;
	while(p!=NULL)
	{
		printf("%4d",p->data);	/*输出链表A中的每个元素*/
		p=p->next;
	}
	printf("\n");
	printf("单链表B中的元素有%d个：\n",ListLength(B));
	p=B->next;
	while(p!=NULL)
	{
		printf("%4d",p->data);	/*输出链表B中的每个元素*/
		p=p->next;
	}
	printf("\n");
	SortList(A);
	SortList(B);
	//	DelElem(A,B);					/*将在单链表A中出现的B的元素删除，即A-B*/
	C=Difference(A,B);
	printf("C中的元素：\n");
	p=C;
	while(p!=NULL)
	{
		printf("%4d",p->data);
		p=p->next;
	}
	printf("\n");
}
void SortList(LinkList S)
/*利用选择排序法对链表S进行从小到大排序 从头到尾 找到最小的元素 按顺序插入*/
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
ListNode *Append(ListNode *last,DataType e)
//释放头结点
{
	last->next=(ListNode*)malloc(sizeof(ListNode));
	last->next->data=e;
	return last->next;
}
ListNode *Difference(ListNode *A,ListNode *B)
//求A-B，将结果存放在C中
{
	ListNode *C,*last;
	C=last=(ListNode*)malloc(sizeof(ListNode));
	while(A!=NULL&&B!=NULL)
		if(A->data<B->data)
		{
			last=Append(last,A->data);
			A=A->next;
		}
		else if(A->data==B->data)
		{
			A=A->next;
			B=B->next;
		}
		else 
			B=B->next;
		while(A!=NULL)//如果A中还有剩余元素，把剩下的元素追加到C中
		{
			last=Append(last,A->data);
			A=A->next;
		}
		last->next=NULL;//最后一个结点的指针域置为空
		last=C;
		C=C->next;//指向第一个结点
		free(last);//释放头结点
		return C;
}
