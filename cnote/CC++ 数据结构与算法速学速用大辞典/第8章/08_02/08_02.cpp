#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<iostream.h>
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
//采用邻接表存储结构创建有向图G
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
		/*j为弧头i为弧尾创建邻接表*/
		p=(ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex=j;
		p->info=NULL;
		p->nextarc=G->vertex[i].firstarc;
		G->vertex[i].firstarc=p;
	}
	(*G).kind=DG;
}

void DestroyGraph(AdjGraph *G)
//销毁有向图G
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
	cout<<endl<<G.arcnum<<"条边:"<<endl;
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
void main()
{
	AdjGraph G;
	cout<<"采用邻接矩阵创建有向图G："<<endl;
	CreateGraph(&G);
	cout<<"输出有向图G的邻接表："<<endl;
	DisplayGraph(G);
	DestroyGraph(&G);
}
