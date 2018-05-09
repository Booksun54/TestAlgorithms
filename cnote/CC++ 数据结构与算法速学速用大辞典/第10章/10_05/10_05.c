#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct		/*元素类型定义*/
{
	int value;		/*元素值*/
	int hi;			/*冲突次数*/
}DataType;
typedef struct		/*哈希表类型定义*/
{
	DataType *data;
	int length;		/*哈希表的长度*/
	int num;		/*表中元素个数*/
}HashTable;
void CreateHashTable(HashTable *H,int m,int p,int hash[],int n);
int SearchHash(HashTable H,int k);
void HashASL(HashTable H,int m);
void DisplayHash(HashTable H,int m);
void main()
{
	int hash[]={78,90,66,70,155,82,123,231};
	HashTable H;
	int m=11,p=11,n=8,pos,v;
	CreateHashTable(&H,m,p,hash,n);
	DisplayHash(H,m);
	printf("请输入待查找的元素:");
	scanf("%d",&v);
	pos=SearchHash(H,v);
	printf("元素%d在哈希表中的位置:%d\n",v,pos);
	HashASL(H,m);
}
void CreateHashTable(HashTable *H,int m,int p,int hash[],int n)
/*构造哈希表，并处理冲突*/
{ 
	int i,sum,addr,di,k=1;
	/*为哈希表分配存储空间*/
	(*H).data=(DataType*)malloc(m*sizeof(DataType));
	if(!(*H).data)	
		exit(-1); 
	(*H).num=n;			/*初始化哈希表的元素个数*/
    (*H).length=m;		/*初始化哈希表的长度*/
	for(i=0;i<m;i++)	/*初始化哈希表*/
	{
		(*H).data[i].value=-1;
		(*H).data[i].hi=0;
	}
	/*构造哈希表并处理冲突*/
	for(i=0;i<n;i++)
	{
		sum=0;			/*sum记录冲突次数*/
		addr=hash[i]%p;	/*利用除留余数法求哈希函数地址*/
		di=addr;
		if((*H).data[addr].value==-1)	/*如果不冲突则将元素存储在表中*/
		{
			(*H).data[addr].value=hash[i];
			(*H).data[addr].hi=1;
		}
		else			/*用线性探测再散列法处理冲突*/
		{
			do 
			{
				di=(di+k)%m;
				sum+=1;
			} while((*H).data[di].value!=-1);
			(*H).data[di].value=hash[i];
			(*H).data[di].hi=sum+1;
		}
	}
}
int SearchHash(HashTable H,int v)
/*在哈希表H中查找值为v的元素*/
{
	int d,d1,m;
	m=H.length;
	d=d1=v%m;				/*求v的哈希地址*/
	while(H.data[d].value!=-1)
	{
		if(H.data[d].value==v)	/*如果找到要查找的元素v，则返回v的位置*/
			return d;
		else					/*如果不是要找的元素，则继续向后查找*/
			d=(d+1)%m;
		if(d==d1)				/*如果找遍了哈希表中的所有位置还没有找到v，则返回0*/
			return 0;
	}
	return 0;					/*该位置不存在元素v*/
}
void HashASL(HashTable H,int m)
/*求哈希表的平均查找长度*/
{
	float average=0;
	int i;
	for(i=0;i<m;i++)
		average=average+H.data[i].hi;
	average=average/H.num;
	printf("平均查找长度ASL:%.2f",average);
	printf("\n");  
}
void DisplayHash(HashTable H,int m)
/*输出哈希表*/
{
	int i;
	printf("哈希表地址:  ");
	for(i=0;i<m;i++)		/*输出哈希表的地址*/
		printf("%-5d",i);
	printf("\n");
	printf("元素值value: ");
	for(i=0;i<m;i++)		/*输出哈希表的元素值*/
		printf("%-5d",H.data[i].value);
	printf("\n");
	printf("冲突次数:    ");
	for(i=0;i<m;i++)		/*冲突次数*/
		printf("%-5d",H.data[i].hi);
	printf("\n");
}