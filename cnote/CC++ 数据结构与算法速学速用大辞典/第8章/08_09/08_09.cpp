#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<iostream.h>
#include"SeqStack.h"
/*图的邻接表类型定义*/
typedef char VertexType[4];
typedef char InfoPtr;
typedef int VRType;
#define MAXSIZE 100				/*最大顶点个数*/
typedef enum{DG,DN,UG,UN}GraphKind; 	/*图的类型：有向图、有向网、无向图和无向网*/
typedef struct ArcNode			/*边结点的类型定义*/
{
    int adjvex; 				/*弧指向的顶点的位置*/
	InfoPtr *info;				/*与弧相关的信息*/
	struct ArcNode *nextarc; 	/*指示下一个与该顶点相邻接的顶点*/
}ArcNode;
typedef struct VNode			/*头结点的类型定义*/
{
	VertexType data; 			/*用于存储顶点*/
	ArcNode *firstarc; 			/*指示第一个与该顶点邻接的顶点*/
}VNode,AdjList[MAXSIZE];
typedef struct					/*图的类型定义*/
{
	AdjList vertex;
	int vexnum,arcnum;			/*图的顶点数目与弧的数目*/
	GraphKind kind; 			/*图的类型*/
}AdjGraph;
int LocateVertex(AdjGraph G,VertexType v);
void CreateGraph(AdjGraph *G);
void DisplayGraph(AdjGraph G);
void DestroyGraph(AdjGraph *G);
void DFSTraverse(AdjGraph G);
int LocateVertex(AdjGraph G,VertexType v)
//返回图中顶点对应的位置
{ 
	int i;
	for(i=0;i<G.vexnum;i++)
		if(strcmp(G.vertex[i].data,v)==0)
			return i;
		return -1;
}
void CreateGraph(AdjGraph *G)
//采用邻接表存储结构创建无向图G
{ 
	int i,j,k;
	VertexType v1,v2;		//定义两个顶点v1和v2
	ArcNode *p;
	cout<<"请输入图的顶点数和边数: ";
	cin>>(*G).vexnum>>(*G).arcnum;
	cout<<"请输入"<<G->vexnum<<"个顶点的值:"<<endl;
	for(i=0;i<G->vexnum;i++)	//将顶点存储在头结点中
	{
		cin>>G->vertex[i].data;
		G->vertex[i].firstarc=NULL;	//将相关联的顶点置为空
	}
	cout<<"请输入弧尾 弧头:"<<endl;
	for(k=0;k<G->arcnum;k++)	//建立边链表
	{
		cin>>v1>>v2;
		i=LocateVertex(*G,v1);/*确定v1对应的编号*/
		j=LocateVertex(*G,v2);/*确定v2对应的编号*/
		//j为弧头i为弧尾创建邻接表
		p=(ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex=j;
		p->info=NULL;
		p->nextarc=G->vertex[i].firstarc;
		G->vertex[i].firstarc=p;
		//i为弧头j为弧尾创建邻接表
		p=(ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex=i;
		p->info=NULL;
		p->nextarc=G->vertex[j].firstarc;
		G->vertex[j].firstarc=p;
	}
	(*G).kind=UG;
}

void DestroyGraph(AdjGraph *G)
//销毁无向图G
{ 
	int i;
	ArcNode *p,*q;
	for(i=0;i<(*G).vexnum;i++)	//释放图中的边表结点
	{
		p=G->vertex[i].firstarc;//p指向边表的第一个结点
		if(p!=NULL)			//如果边表不为空，则释放边表的结点
		{
			q=p->nextarc;
			free(p);
			p=q;
		}
	}
	(*G).vexnum=0;		//将顶点数置为0
	(*G).arcnum=0;		//将边的数目置为0
}
void DisplayGraph(AdjGraph G)
//输出图的邻接矩阵G
{ 
	int i;
	ArcNode *p;
	cout<<G.vexnum<<"个顶点："<<endl;
	for(i=0;i<G.vexnum;i++)
		cout<<G.vertex[i].data<<" ";
	cout<<endl<<2*G.arcnum<<"条边:"<<endl;
	for(i=0;i<G.vexnum;i++)
	{
		p=G.vertex[i].firstarc;
		while(p)
		{
			cout<<G.vertex[i].data<<"→"<<G.vertex[p->adjvex].data<<" ";
			p=p->nextarc;
		}
		cout<<endl;
	}
}
void BriefPath(AdjGraph G,int u,int v)
/*求图G中从顶点u到顶点v的一条简单路径*/
{
	int k,i;
	SeqStack S,T;
	ArcNode *p;
	int visited[MAXSIZE];
	int parent[MAXSIZE];		/*存储已经访问顶点的前驱顶点*/
	InitStack(&S);
	InitStack(&T);
	for(k=0;k<G.vexnum;k++)		/*访问标志初始化*/
		visited[k]=0;
	PushStack(&S,u);			/*开始顶点入栈*/
	visited[u]=1;				/*访问标志置为1*/
	while(!StackEmpty(S))		/*广度优先搜索图，访问路径用parent存储*/
	{
		PopStack(&S,&k);
		p=G.vertex[k].firstarc;
		while(p!=NULL)
		{
			if(p->adjvex==v)	/*如果找到顶点v*/
			{
				parent[p->adjvex]=k;	/*顶点v的前驱顶点序号是k*/
				printf("顶点%s到顶点%s的路径是：",G.vertex[u].data,G.vertex[v].data);
				i=v;
				do						/*从顶点v开始将路径中的顶点依次入栈*/
				{
					PushStack(&T,i);
					i=parent[i];
				}while(i!=u);
				PushStack(&T,u);
				while(!StackEmpty(T))	/*从顶点u开始输出u到v中路径的顶点*/
				{
					PopStack(&T,&i);
					printf("%s ",G.vertex[i].data);
					
				}
				printf("\n");
			}
			else if(visited[p->adjvex]==0)/*若未找到顶点v且邻接点未访问过，则继续搜索*/
			{
				visited[p->adjvex]=1;
				parent[p->adjvex]=k;
				PushStack(&S,p->adjvex);
			}
			p=p->nextarc;
		}	
	}	
}
void main()
{
	AdjGraph G;
	VertexType u,v;
	int i,j;
	cout<<"采用邻接表创建无向图G："<<endl;
	CreateGraph(&G);
	cout<<"输出无向图G的邻接表："<<endl;
	DisplayGraph(G);
	cout<<"请输入要查找哪两个顶点之间的简单路径："<<endl;
	cin>>u>>v;
	i=LocateVertex(G,u);
	j=LocateVertex(G,v);
	BriefPath(G,i,j);
	cout<<endl;
	DestroyGraph(&G);
}
