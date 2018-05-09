#include<stdio.h>				
#include<malloc.h>
#include<stdlib.h>
typedef int DataType;

#include"LinkList.h"			/*包含单链表基本操作实现文件*/
void MergeList(LinkList A,LinkList B,LinkList *C);	/*函数声明：将单链表A和B的元素合并到C中*/
void main()
{
	int i;
	DataType a[]={12,16,21,33,35,87,102};
	DataType b[]={3,5,21,23,35,99,123};
	LinkList A,B,C;					/*声明单链表A和B*/
	ListNode *p;
	InitList(&A);					/*初始化单链表A*/
	InitList(&B);					/*初始化单链表B*/
	for(i=1;i<=sizeof(a)/sizeof(a[0]);i++)	/*利用数组元素创建单链表A*/
	{
		if(InsertList(A,i,a[i-1])==0)
		{
			printf("插入位置不合法!");
			return;
		}
	}
	for(i=1;i<=sizeof(b)/sizeof(b[0]);i++)	/*利用数组元素创建单链表B*/
	{
		if(InsertList(B,i,b[i-1])==0)
		{
			printf("插入位置不合法!");
			return;
		}
	}
	printf("单链表A中的元素有%d个：\n",ListLength(A));
	for(i=1;i<=ListLength(A);i++)	/*输出单链表A*/
	{
		p=Get(A,i);					/*返回单链表A中的每个结点的指针*/
		if(p)
			printf("%4d",p->data);	/*输出单链表A中的每个元素*/
	}
	printf("\n");
	printf("单链表B中的元素有%d个：\n",ListLength(B));
	for(i=1;i<=ListLength(B);i++)	/*输出单链表B*/
	{
		p=Get(B,i);					/*返回单链表B中的每个结点的指针*/
		if(p)
			printf("%4d",p->data);	/*输出单链表B中的每个元素*/
	}
	printf("\n");
	MergeList(A,B,&C);					/*将单链表A和B中的元素合并到C中*/
	printf("将A和B的元素合并成一个递减有序的单链表C(包含%d个元素)：\n",ListLength(C));
	for(i=1;i<=ListLength(C);i++)		
	{
		p=Get(C,i);					/*返回单链表C中每个结点的指针*/
		if(p)
			printf("%4d",p->data);	/*显示输出C中所有元素*/
	}
	printf("\n");
}
void MergeList(LinkList A,LinkList B,LinkList *C)
/*将非递减排列的单链表A和B中的元素合并到C中，使C中的元素按递减排列，相同值的元素只保留一个*/
{
	ListNode *pa,*pb,*qa,*qb;/*定义指向单链表A，B的指针*/
	pa=A->next;/*pa指向单链表A*/
	pb=B->next;/*pb指向单链表B*/
	free(B);/*释放单链表B的头结点*/
	*C=A;				/*初始化单链表C，利用单链表A的头结点作为C的头结点*/
	(*C)->next=NULL;/*单链表C初始时为空*/
	/*利用头插法将单链表A和B中的结点插入到单链表C中（先插入元素值较小的结点）*/
	while(pa&&pb)		/*单链表A和B均不空时*/
	{
		if(pa->data<pb->data)/*pa指向结点元素值较小时，将pa指向的结点插入到C中*/
		{
			qa=pa;
			pa=pa->next;
			if((*C)->next==NULL)/*单链表C为空时，直接将结点插入到C中*/
			{
				qa->next=(*C)->next;
				(*C)->next=qa;
			}
			else if((*C)->next->data<qa->data)/*pa指向的结点元素值不同于已有结点元素值时，才插入结点*/
			{
				qa->next=(*C)->next;
				(*C)->next=qa;
			}
			else/*否则，释放元素值相同的结点*/
				free(qa);
		}
		else/*pb指向结点元素值较小，将pb指向的结点插入到C中*/
		{
			qb=pb;
			pb=pb->next;
			if((*C)->next==NULL)/*单链表C为空时，直接将结点插入到C中*/
			{
				qb->next=(*C)->next;
				(*C)->next=qb;
			}
			else if((*C)->next->data<qb->data)/*pb指向的结点元素值不同于已有结点元素时，才将结点插入*/
			{
				qb->next=(*C)->next;
				(*C)->next=qb;
			}
			else/*否则，释放元素值相同的结点*/
				free(qb);
		}
	}
	while(pa)/*如果pb为空、pa不为空，则将pa指向的后继结点插入到C中*/
	{
		qa=pa;
		pa=pa->next;
		if((*C)->next&&(*C)->next->data<qa->data)
		{
			qa->next=(*C)->next;
			(*C)->next=qa;
		}
		else
			free(qa);
	}
	while(pb)/*如果pa为空、pb不为空，则将pb指向的后继结点插入到C中*/
	{
		qb=pb;
		pb=pb->next;
		if((*C)->next&&(*C)->next->data<qb->data)
		{
			qb->next=(*C)->next;
			(*C)->next=qb;
		}
		else
			free(qb);
	}
}