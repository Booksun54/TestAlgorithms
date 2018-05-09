
void  CreateBitTree(BiTree *T,char str[])
/*利用括号嵌套的字符串建立二叉链表*/
{
	char ch;
	BiTree stack[MAXSIZE];			/*定义栈，用于存放指向二叉树中结点的指针*/
	int top=-1;						/*初始化栈顶指针*/
	int flag,k;
	BitNode *p;
	*T=NULL,k=0;
	ch=str[k];
	while(ch!='\0')					/*如果字符串没有结束*/
	{
		switch(ch)
		{
		case '(':
			stack[++top]=p;
			flag=1;
			break;
		case ')':
			top--;
			break;
		case ',':
			flag=2;
			break;
		default:
			p=(BiTree)malloc(sizeof(BitNode));
			p->data=ch;
			p->lchild=NULL;
			p->rchild=NULL;
			if(*T==NULL)		/*如果是第一个结点，表示是根结点*/
				*T=p;
			else
			{
				switch(flag)
				{
				case 1:
					stack[top]->lchild=p;
					break;
				case 2:
					stack[top]->rchild=p;
					break;
				}
			}
		}
		ch=str[++k];
	}
}
void DestroyBitTree(BiTree *T)
/*销毁二叉树操作*/
{
	if(*T) 							/*如果是非空二叉树*/
	{
		if((*T)->lchild)
			DestroyBitTree(&((*T)->lchild));
		if((*T)->rchild)
			DestroyBitTree(&((*T)->rchild));
		free(*T);
		*T=NULL;
	}
}
void TreePrint(BiTree T,int level) 
/*按树状打印的二叉树*/ 
{   
	int i;
	if(T==NULL)									/*如果指针为空，返回上一层*/ 
		return;
	TreePrint(T->rchild,level+1);				/*打印右子树，并将层次加1*/ 
	for(i=0;i<level;i++)						/*按照递归的层次打印空格*/ 
		printf("   ");
	printf("%c\n",T->data);						/*输出根结点*/ 
	TreePrint(T->lchild,level+1);				/*打印左子树，并将层次加1*/ 
}