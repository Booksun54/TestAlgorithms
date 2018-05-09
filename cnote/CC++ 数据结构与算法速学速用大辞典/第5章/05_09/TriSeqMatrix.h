#define MaxSize 200
typedef struct			/*三元组类型定义*/
{
	int i; 				/*非零元素的行号*/
	int j; 				/*非零元素的列号*/
    DataType e;
}Triple;
typedef struct				/*矩阵类型定义*/
{
    Triple data[MaxSize];
	int m; 			/*矩阵的行数*/
	int n; 			/*矩阵的列数*/
	int len; 			/*矩阵中非零元素的个数*/
}TriSeqMatrix;
int CreateMatrix(TriSeqMatrix *M)
/*创建稀疏矩阵（按照行优先顺序输入非零元素值）*/
{ 
	int i,m,n;
	DataType e;
	int flag;
	printf("请输入稀疏矩阵的行数、列数及非零元素个数：");
	scanf("%d,%d,%d",&M->m,&M->n,&M->len);
	if(M->len>MaxSize)
		return 0;
	for(i=0;i<M->len;i++)
	{
		do
		{
			printf("请按行序顺序输入第%d个非零元素所在的行(0～%d),列(0～%d),元素值:",i+1,M->m-1,M->n-1);
			scanf("%d,%d,%d",&m,&n,&e);
			flag=0;							/*初始化标志位*/
			if(m<0||m>M->m||n<0||n>M->n)			/*如果行号或列号正确，标志位为1*/
				flag=1;                        
			/*若输入的顺序正确，则标志位为1*/
			if(i>0&&m<M->data[i-1].i||m==M->data[i-1].i&&n<=M->data[i-1].j)	
				flag=1;
		}while(flag);
		M->data[i].i=m;
		M->data[i].j=n;
		M->data[i].e=e;
	}
	return 1;
}
void CopyMatrix(TriSeqMatrix M,TriSeqMatrix *N)
/*由稀疏矩阵M复制得到另一个副本N*/
{ 
	
	int i;
	N->len=M.len;				/*修改稀疏矩阵N的非零元素的个数*/
	N->m=M.m;				/*修改稀疏矩阵N的行数*/
	N->n=M.n;				/*修改稀疏矩阵N的列数*/
	for(i=0;i<M.len;i++)	/*把M中非零元素的行号、列号及元素值依次赋值给N的行号、列号及元素值*/
	{
		N->data[i].i=M.data[i].i;
		N->data[i].j=M.data[i].j;
		N->data[i].e=M.data[i].e;
	}
}
void TransposeMatrix(TriSeqMatrix M,TriSeqMatrix *N)
/*稀疏矩阵的转置*/
{ 
	int i,k,col;
	N->m=M.n;
	N->n=M.m;
	N->len=M.len;
	if(N->len)
	{
		k=0;
		for(col=0;col<M.n;col++)			/*按照列号扫描三元组顺序表*/
			for(i=0;i<M.len;i++)
				if(M.data[i].j==col)		/*如果元素的列号是当前列，则进行转置*/
				{
					N->data[k].i=M.data[i].j;
					N->data[k].j=M.data[i].i;
					N->data[k].e=M.data[i].e;
					k++;
				}
	}
}

void DestroyMatrix(TriSeqMatrix *M)
/*销毁稀疏矩阵*/
{ 
	M->m=M->n=M->len=0;
}