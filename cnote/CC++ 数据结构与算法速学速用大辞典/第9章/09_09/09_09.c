#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MaxSize 200	/*待排序元素的最大个数*/
#define N 8         	/*待排序元素的实际个数*/
#define MaxNumKey 6	/*关键字项数的最大值*/
#define Radix 10		/*关键字基数，10表示十进制数字可以分为十组*/
/*静态链表的结点，存放待排序元素*/
typedef struct
{
	int key[MaxNumKey]; 	/*关键字*/
	int next;
}SListCell;	
/*静态链表，存放元素序列*/					
typedef struct
{
	SListCell data[MaxSize];		/*存储元素，data[0]为头结点*/
	int keynum;				/*每个元素的当前关键字个数*/
	int length;					/*静态链表的当前长度*/
}SList;				
typedef int addr[Radix]; /*指针数组类型，用来指向每个链表的第1个结点和最后一个结点*/ 
void DispList(SList L); 			/*输出链表中的元素*/
void DispStaticList(SList L); 		/*以静态链表的形式输出元素*/
void InitList(SList *L,int d[],int n);
int trans(char c); 				/*将字符转换为数字*/
void Distribute(SListCell data[],int i,addr f,addr r); 	/*分配*/
void Collect(SListCell data[],addr f,addr r); 		/*收集*/
void RadixSort(SList *L); 					/*基数排序*/
void Distribute(SListCell data[],int i,addr f,addr r) 
/*为data数组中的第i个关键字key[i]建立Radix个子表，使同一子表中元素的key[i]相同*/ 
/*f[0..Radix-1]和r[0..Radix-1]分别指向各个子表中第一个和最后一个元素*/
{ 
	int j,p;
	for(j=0;j<Radix;j++)			/*初始化各个子表*/
		f[j]=0;
	for(p=data[0].next;p;p=data[p].next)
	{
		j=trans(data[p].key[i]);		/*将关键字转换为数字*/
		if(!f[j])				/*f[j]是空表，则f[j]指示第一个元素*/
			f[j]=p;
		else
			data[r[j]].next=p;
		r[j]=p;		/*将p所指的结点插入第j个子表中*/
	}
}
void Collect(SListCell data[],addr f,addr r)
/*收集，按key[i]将f[0..Radix-1]所指各子表依次链接成一个静态链表*/
{ 
	int j,t;
	for(j=0;!f[j];j++);	/*找第一个非空子表，succ为求后继函数*/
	data[0].next=f[j];
	t=r[j];			/*r[0].next指向第一个非空子表中第一个结点*/
	while(j<Radix-1)
	{
		for(j=j+1;j<Radix-1&&!f[j];j++);		/*找下一个非空子表*/
		if(f[j])		/*将非空链表连接在一起*/
		{
			data[t].next=f[j];
			t=r[j];
		}
	}
	data[t].next=0;		/*t指向最后一个非空子表中的最后一个结点*/
}
void RadixSort(SList *L)
/*基数排序，使得L成为按关键字非递减的静态链表，L.r[0]为头结点*/
{ 
	int i;
	addr f,r;
	for(i=0;i<(*L).keynum;i++)	/*由低位到高位依次对各关键字进行分配
		和收集*/ 
	{				
		Distribute((*L).data,i,f,r);		/*第i趟分配*/
		Collect((*L).data,f,r);			/*第i趟收集*/
		printf("第%d趟收集后:",i+1);
		DispStaticList(*L);
	}
}
void InitList(SList *L,int a[],int n)
/*初始化静态链表L*/
{
	char ch[MaxNumKey],ch2[MaxNumKey];
	int i,j,max=a[0];
	for(i=1;i<n;i++)			/*将最大的元素存入max*/
		if(max<a[i])
			max=a[i];
		(*L).keynum=(int)(log10(max))+1;	/*求子关键字的个数*/
		(*L).length=n;					/*待排序个数*/
		for(i=1;i<=n;i++)
		{
			itoa(a[i-1],ch,10);	/*将整型转化为字符，并存入ch*/
			for(j=strlen(ch);j<(*L).keynum;j++)/*若ch的长度<max的位数，则在ch前补'0'*/ 
			{
				strcpy(ch2,"0");
				strcat(ch2,ch);
				strcpy(ch,ch2);
			}
			for(j=0;j<(*L).keynum;j++)	/*将每个元素的各位数存入key，作为关键字*/
				(*L).data[i].key[j]=ch[(*L).keynum-1-j];
		}
		for(i=0;i<(*L).length;++i)			/*初始化静态链表*/
			(*L).data[i].next=i+1;
		(*L).data[(*L).length].next=0; 
}
void main()
{
	int d[N]={325,138,29,214,927,631,732,205};
	SList L;
	InitList(&L,d,N);
	printf("待排序元素个数是%d个,关键字个数为%d个\n",L.length,
		L.keynum);
	printf("排序前的元素序列:");
	DispStaticList(L);
	printf("排序前的元素的存放情况:\n");
	DispList(L);
	RadixSort(&L);	
	printf("排序后元素的存放情况:\n");
	DispList(L);
}
void DispList(SList L)
/*按数组序号形式输出静态链表*/
{ 
	int i,j;
	printf("序号 关键字 地址\n");
	for(i=1;i<=L.length;i++)
	{
		printf("%2d    ",i);
		for(j=L.keynum-1;j>=0;j--)
			printf("%c",L.data[i].key[j]);
		printf("    %d\n",L.data[i].next);
	}
}
void DispStaticList(SList L)
/*按链表形式输出静态链表*/
{
	int i=L.data[0].next,j;
	while(i)
	{
		for(j=L.keynum-1;j>=0;j--)
			printf("%c",L.data[i].key[j]);
		printf(" ");
		i=L.data[i].next;
	}
	printf("\n");
}
int trans(char c)
/*将字符c转化为对应的整数*/
{ 
	return c-'0';
}
