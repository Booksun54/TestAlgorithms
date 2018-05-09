#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<iostream.h>
#include<iomanip.h>
/*宏定义和单链表类型定义*/
typedef char DataType;
#include"LinkList.h"
/*函数声明*/
LinkList CreateList(DataType a[],int n);/*根据给定的数组创建单链表*/
void Decompose(LinkList L,LinkList *ha,LinkList *hb,LinkList *hc);	/*分解单链表为三个循环单链表*/
void DispList(LinkList L);
void DispCycList(LinkList head);
int CycListLength(LinkList head);
void main()
{
	LinkList h,ha,hb,hc;
	int n;
	DataType a[]={'a','X','0','$','@','%','p','m','3','9','y','*','i','&'};
	n=sizeof(a)/sizeof(a[0]);
	h=CreateList(a,n);
	Decompose(h,&ha,&hb,&hc);
	cout<<"大小写英文字母的字符有"<<CycListLength(ha)<<"个，分别是:"<<endl;
	DispCycList(ha);
	cout<<"数字字符的有:"<<CycListLength(hb)<<"个，分别是:"<<endl;
	DispCycList(hb);
	cout<<"其他字符有:"<<CycListLength(hc)<<"个，分别是:"<<endl;
	DispCycList(hc);
}
LinkList CreateList(DataType a[],int n)
//根据数组中的元素创建单链表
{
	LinkList L;			
	int i;
	InitList(&L);		//初始化单链表L
	for(i=1;i<=n;i++)	//将数组a中元素插入到单链表L中
	{
		if(InsertList(L,i,a[i-1])==0)
		{
			printf("插入位置不合法!");
			return NULL;
		}
	}
	DispList(L);
	return L;
}
void Decompose(LinkList L,LinkList *ha,LinkList *hb,LinkList *hc)
/*将带头结点的单链表L分解为三个带头结点的循环单链表ha、hb和hc，其中ha
仅含英文字母字符，hb仅含数字字符，hc仅含其他字符*/
{
	ListNode *p,*q;
	p=L->next;
	*ha=(LinkList)malloc(sizeof(ListNode));
	*hb=(LinkList)malloc(sizeof(ListNode));
	*hc=(LinkList)malloc(sizeof(ListNode));
	(*ha)->next=(*ha);
	(*hb)->next=(*hb);
	(*hc)->next=(*hc);
	while(p)
	{
		if((p->data>='A' && p->data<='Z')||(p->data>='a' && p->data<'z'))
		{
			q=p;
			p=p->next;
			q->next=(*ha)->next;
			(*ha)->next=q;
		}
		else if(p->data>='0' && p->data<='9')
		{
			q=p;
			p=p->next;
			q->next=(*hb)->next;
			(*hb)->next=q;
		}
		else
		{
			q=p;
			p=p->next;
			q->next=(*hc)->next;
			(*hc)->next=q;
		}
	}
}
void DispList(LinkList L)
//输出单链表中的元素
{
	int i;
	LinkList p;
	cout<<"单链表L中的元素有"<<ListLength(L)<<"个"<<endl;
	for(i=1;i<=ListLength(L);i++)	/*输出单链表L中的每个元素*/
	{
		p=Get(L,i);					/*返回单链表L中的每个结点的指针*/
		if(p)
			cout<<setw(4)<<p->data;	/*输出单链表L中的每个元素*/
	}
	cout<<endl;
}
void DispCycList(LinkList h)
//输出循环单链表中的元素
{
	ListNode *p=h->next;
	if(p==NULL)
	{
		cout<<"链表为空!"<<endl;
		return;
	}
	while(p->next!=h)
	{
		cout<<setw(4)<<p->data;
		p=p->next;
	}
	cout<<setw(4)<<p->data;
	cout<<endl;
}
int CycListLength(LinkList head)
//求循环单链表的表长
{
    ListNode *p;
    int count=0;
    p=head;
    while(p->next!=head)
    {
        p=p->next;
        count++;
    }
    return count;
}