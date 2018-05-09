#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
	unsigned int weight;  /*权值*/
	unsigned int parent,LChild,RChild;  /*指向双亲、左右孩子结点的指针*/
} HTNode, *HuffmanTree;  /*存储哈夫曼树*/
typedef char *HuffmanCode;  /*存储哈夫曼编码*/
void CreateHuffmanTree(HuffmanTree *ht,int *w,int n);
void Select(HuffmanTree *ht,int n,int *s1,int *s2);
void CreateHuffmanCode(HuffmanTree *ht, HuffmanCode *hc, int n);
void main()
{
	HuffmanTree HT;
	HuffmanCode HC;
	int *w,i,n,w1;
	printf("***********哈夫曼编码***********\n" );
	printf("请输入结点个数:" );
	scanf("%d",&n);
	w=(int *)malloc((n+1)*sizeof(int)); 
	printf("输入这%d个元素的权值:\n",n); 
	for(i=1; i<=n; i++)
	{ 
		printf("%d: ",i); 
//		fflush(stdin);
		scanf("%d",&w1);
		w[i]=w1;
	}
	CreateHuffmanTree(&HT,w,n);/*构造哈夫曼树*/
	CreateHuffmanCode(&HT,&HC,n);/*构造哈夫曼编码*/
}
void CreateHuffmanTree(HuffmanTree *ht,int *w,int n)
/*构造哈夫曼树ht,w存放已知的n个权值*/
{
	int m,i,s1,s2;
	m=2*n-1;    /*结点总数*/
	*ht=(HuffmanTree)malloc((m+1)*sizeof(HTNode));
	for(i=1; i<=n; i++)  /*初始化叶子结点*/
	{
		(*ht)[i].weight=w[i];
		(*ht)[i].LChild=0;
		(*ht)[i].parent=0;
		(*ht)[i].RChild=0;
	}
	for(i=n+1; i<=m; i++)  /*初始化非叶子结点*/
	{
		(*ht)[i].weight=0;
		(*ht)[i].LChild=0;
		(*ht)[i].parent=0;
		(*ht)[i].RChild=0;
	} 	
	printf("\n哈夫曼树为: \n");	
	for(i=n+1; i<=m; i++)   /*创建非叶子结点，建哈夫曼树*/
	/*在(*ht)[1]~(*ht)[i-1]的范围内选择两个最小的结点*/
	{ 
		Select(ht,i-1,&s1,&s2);
		(*ht)[s1].parent=i;
		(*ht)[s2].parent=i;
		(*ht)[i].LChild=s1;
		(*ht)[i].RChild=s2;
		(*ht)[i].weight=(*ht)[s1].weight+(*ht)[s2].weight;
		printf("%d (%d, %d)\n",
			(*ht)[i].weight,(*ht)[s1].weight,(*ht)[s2].weight);
	}
	printf("\n");
}
void CreateHuffmanCode(HuffmanTree *ht, HuffmanCode *hc, int n)
/*从叶子结点到根，逆向求每个叶子结点对应的哈夫曼编码*/
{
	char *cd;   /*定义的存放编码的空间*/
	int a[100];
	int i,start,p,w=0;
	unsigned int c;
	hc=(HuffmanCode *)malloc((n+1)*sizeof(char *));  /*分配n个编码的头指针*/
	cd=(char *)malloc(n*sizeof(char));  /*分配求当前编码的工作空间*/
	cd[n-1]='\0';  /*从右向左逐位存放编码，首先存放编码结束符*/
	for(i=1; i<=n; i++)  
	/*求n个叶子结点对应的哈夫曼编码*/
	{
		a[i]=0;
		start=n-1;  /*起始指针位置在最右边*/
		for(c=i,p=(*ht)[i].parent; p!=0; c=p,p=(*ht)[p].parent)  
		/*从叶子到根结点求编码*/
		{
			
			if( (*ht)[p].LChild==c)
			{
				cd[--start]='0';  /*左分支记作0*/
				a[i]++;
			}
			else 
			{
				cd[--start]='1';  /*右分支记作1*/
				a[i]++;
			}
		}
		/*为第i个编码分配空间*/
		hc[i]=(char *)malloc((n-start)*sizeof(char)); 
		strcpy(hc[i],&cd[start]); /*将cd复制编码到hc*/
	}
	free(cd);
	for(i=1; i<=n; i++)
		printf("权值为%d的哈夫曼编码为:%s\n",(*ht)[i].weight,hc[i]);
	for(i=1; i<=n; i++)
		w+=(*ht)[i].weight*a[i];
	printf("带权路径为:%d\n",w);	
} 
void Select(HuffmanTree *ht,int n,int *s1,int *s2)
/*选择两个parent为0，且weight最小的结点s1和s2*/
{
	int i,min;
	for(i=1; i<=n; i++)
	{
		if((*ht)[i].parent==0)
		{
			min=i;
			break;
		}
	}
	for(i=1; i<=n; i++)
	{
		if((*ht)[i].parent==0)
		{
			if((*ht)[i].weight<(*ht)[min].weight)
				min=i;
		}
	}
	*s1=min;
	
	for(i=1; i<=n; i++)
	{
		if((*ht)[i].parent==0 && i!=(*s1))
		{
			min=i;
			break;
		}
	}
	for(i=1; i<=n; i++)
	{
		if((*ht)[i].parent==0 && i!=(*s1))
		{
			if((*ht)[i].weight<(*ht)[min].weight) 
				min=i;
		}
	}
	*s2=min;
}
