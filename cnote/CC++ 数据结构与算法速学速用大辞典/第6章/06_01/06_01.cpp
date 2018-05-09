#include<stdio.h>
#include<stdlib.h>
#include<iostream.h>
typedef char AtomType;//元素类型为字符型
typedef enum{ATOM,LIST}ElemTag; /*ATOM=0，表示原子，LIST=1，表示子表*/
//广义表的存储结构
struct GNode
{
	ElemTag tag;	//标志域
	union
	{	
		AtomType atom;	//值域
		struct GNode *hp;//子表的表头指针
	};
	struct GNode *tp;	//后继结点的指针
};
int LengthGList(struct GNode *GL);	//求广义表的长度
int DepthGList(struct GNode *GL);	//求广义表的深度
void CreateGList(struct GNode **GL);//建立广义表的存储结构
void PrintGList(struct GNode *GL);	//打印输出广义表
int SearchGList(struct GNode *GL, AtomType e);//查找等于给定字符的单元素结点，查找成功则返回1，否则返回0

void main()
{
	int flag;
	AtomType e;
	struct GNode *GL;
	cout<<"输入一个广义表(以回车结束)."<<endl;
	CreateGList(&GL);
	cout<<"输出广义表："<<endl;
	PrintGList(GL);
	cout<<endl;
	cout<<"广义表的长度：";
	cout<<LengthGList(GL->hp)<<endl;
	cout<<"广义表的深度：";
	cout<<DepthGList(GL->hp)<<endl;
	cout<<"请输入要查找的原子元素:"<<endl;
	cin>>e;
	flag=SearchGList(GL,e);
	if(flag)
		cout<<"广义表中存在查找的元素。"<<endl;
	else
		cout<<"要查找的元素不存在。"<<endl;
}
int LengthGList(struct GNode *GL)
//求广义表的长度
{
	if(GL!=NULL)
		return(1 + LengthGList(GL->tp));
	else
		return(0);
}
int DepthGList(struct GNode *GL)
//求广义表的深度
{
	int max=0;//给max赋初值
	int dep;
	//遍历表中每一个结点，求出所有子表的最大深度
	while(GL!=NULL)
	{
		if(GL->tag==LIST)
		{
			dep = DepthGList(GL->hp);//递归调用求出一个子表的深度
			if(dep > max)
				max = dep;//让max始终为同一层所求过的子表中深度的最大值
		}
		GL = GL->tp;//使GL指向同一层的下一个结点
	}
	return max + 1;//返回表的深度
}
void CreateGList(struct GNode **GL)
//建立广义表的存储结构
{
	char ch;
	scanf("%c", &ch);//读入一个字符，此处只可能读入空格#、左括号或英文字母
	if(ch=='#')//若输入为空格，则置表头指针为空
		*GL = NULL;
	else if(ch=='(')//若输入为左括号则建立由*GL所指向的子表结点并递归构造子表
	{
		*GL = (struct GNode*)malloc(sizeof(struct GNode));
		(*GL)->tag = LIST;
		CreateGList(&((*GL)->hp));
	}
	else{	//若输入为字符则建立由*GL所指向的单元素结点
		*GL = (struct GNode*)malloc(sizeof(struct GNode));
		(*GL)->tag = ATOM;
		(*GL)->atom = ch;
	}
	scanf("%c", &ch);//此处读入的字符必为逗号、右括号或分号
	if(*GL==NULL)//若*GL为空，则什么都不做
		;	
	else if(ch==',')//若输入逗号则递归构造后继表
		CreateGList(&((*GL)->tp));
	else if((ch==')') || (ch=='\n'))//若输入为右括号或分号则置*GL的后继指针域为空
		(*GL)->tp = NULL;
}
void PrintGList(struct GNode *GL)
//打印输出广义表
{
	if(GL->tag==LIST)	//对于子表，
	{
		printf("(");//则输出左括号，作为开始符号
		if(GL->hp==NULL)//若子表为空则输出‘#’字符
			printf("#");
		else//若子表非空，则递归输出子表
			PrintGList(GL->hp);
		printf(")");//当一个子表输出结束后，应输出一个右括号终止符
	}
	else//对于原子元素结点，则输出该结点的值
		printf("%c", GL->atom);
	if(GL->tp!=NULL)//输出结点的后继子表
	{
		printf(",");//先输出逗号分隔符
		PrintGList(GL->tp);//再递归输出后继子表
	}
}
int SearchGList(struct GNode *GL, AtomType e)
//查找等于原子元素结点，查找成功则返回1，否则返回0
{
	while(GL!=NULL)
	{
		if(GL->tag == LIST)//存在子表，则递归搜索本层该子表
		{
			if(SearchGList(GL->hp, e))
				return 1;
		}
		else//存在原子元素结点，则查询是否存在值e ，若存在则返回1
		{
			if(GL->atom == e)
				return 1;
		}
		GL = GL->tp;//使GL指向同一层的下一个结点
	}
	return 0;//搜索不到值e ，则返回0
}
