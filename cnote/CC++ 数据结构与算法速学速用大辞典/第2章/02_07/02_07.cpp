#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream.h>
typedef char DataType;
#include"LinkList.h"
#define MAXSIZE 100
void CreateList(LinkList *L,DataType str[MAXSIZE]);
int SymmetryString(LinkList L);
void main()
{
	DataType a[MAXSIZE],b[MAXSIZE];
	LinkList L;
	int flag;
	cout<<"请输入一个字符串："<<endl;
	cin>>a;
	CreateList(&L,a);
	flag=SymmetryString(L);
	if(flag==1)
		cout<<"中心对称!"<<endl;
	else
		cout<<"中心不对称!"<<endl;
	cout<<"请输入一个字符串："<<endl;
	cin>>b;
	CreateList(&L,b);
	flag=SymmetryString(L);
	if(flag==1)
		cout<<"中心对称!"<<endl;
	else
		cout<<"中心不对称!"<<endl;
}   
int SymmetryString(LinkList L)
/*判断字符串是否中心对称*/
{
	char str[MAXSIZE];
	int i=1,n;
	ListNode *p;
	n=ListLength(L);//n为链表中结点元素个数
	p=L->next;//p指向第一个结点
	for(i=0;i<n/2;i++)//将链表中前一半元素入栈
	{
		str[i]=p->data;
		p=p->next;
	}
	i--;//恢复最后的i值
	if(n%2)//若n为奇数，则后移过中心结点
		p=p->next;
	while(p!=NULL && str[i]==p->data)//将前半部分和后半部分元素进行比较
	{
		i--;
		p=p->next;
	}
	if(i==-1)//若为空栈，则表明链表中心对称
		return 1;
	else//否则，链表中心不对称
		return 0;
}
void CreateList(LinkList *L,DataType str[MAXSIZE])
//根据字符数组str创建单链表L
{
	int i;
	InitList(L);
	for(i=0;str[i]!='\0';i++)
		InsertList(*L,i+1,str[i]);
}