#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#include<iostream.h>
#include<iomanip.h>
typedef char VertexType[4];
typedef char InfoPtr;
typedef int VRType;
#define MAXSIZE 50				/*最大顶点个数*/
typedef enum{DG,DN,UG,UN}GraphKind; 	/*图的类型：有向图、有向网、无向图和无向网*/
//以下是邻接矩阵的类型定义
typedef struct
{
	VRType adj;				/*对于无权图，用1表示相邻，0表示不相邻；对于带权图，存储权值*/
	InfoPtr *info; 				/*与弧或边的相关信息*/
}AdjMatrix[MAXSIZE][MAXSIZE];
typedef struct					/*图的类型定义*/
{
	VertexType vex[MAXSIZE]; 	/*用于存储顶点*/
	AdjMatrix arc; 				/*邻接矩阵，存储边或弧的信息*/
	int vexnum,arcnum; 			/*顶点数和边（弧）的数目*/
	GraphKind kind; 			/*图的类型*/
}MGraph;
//以下是邻接表的类型定义
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
void CreateGraph(MGraph *G);
int LocateVertex(MGraph G,VertexType v);
void DestroyGraph(MGraph *G);
void DisplayGraph(MGraph G);
void DisplayAdjGraph(AdjGraph G);
void ConvertGraph(AdjGraph *A,MGraph M);
void main()
{
	MGraph M;
	AdjGraph A;
	cout<<"创建一个有向图："<<endl;
	CreateGraph(&M);
	cout<<"输出网的顶点和弧："<<endl;
	DisplayGraph(M);
	ConvertGraph(&A,M);
	DisplayAdjGraph(A);
	DestroyGraph(&M);
}
void CreateGraph(MGraph *G)
/*采用邻接矩阵表示法创建有向图G*/
{ 
	int i,j,k;
	VertexType v1,v2;
	cout<<"请输入有向图G的顶点数和弧数: ";
	cin>>(*G).vexnum>>(*G).arcnum;
	cout<<"请输入"<<G->vexnum<<"个顶点的值:"<<endl;
	for(i=0;i<G->vexnum;i++)		/*创建一个数组，用于保存图的各个顶点*/
		cin>>G->vex[i];
	for(i=0;i<G->vexnum;i++)		/*初始化邻接矩阵*/
		for(j=0;j<G->vexnum;j++)
		{
			G->arc[i][j].adj=0; 
			G->arc[i][j].info=NULL;	/*弧的信息初始化为空*/
		}
		cout<<"请输入"<<G->arcnum<<"条弧的弧尾 弧头(以空格分隔): "<<endl;
		for(k=0;k<G->arcnum;k++)
		{
			cin>>v1>>v2;	/*输入两个顶点元素*/
			i=LocateVertex(*G,v1);
			j=LocateVertex(*G,v2);
			G->arc[i][j].adj=1;
		}
		G->kind=DG;						/*图的类型为有向图*/
}
int LocateVertex(MGraph G,VertexType v)
/*在顶点向量中查找顶点v，找到返回在向量的序号，否则返回-1*/
{ 
	int i;
	for(i=0;i<G.vexnum;++i)
		if(strcmp(G.vex[i],v)==0)
			return i;
		return -1;
}
void DestroyGraph(MGraph *G)
/*销毁有向图G*/
{ 
	int i,j;
	for(i=0;i<G->vexnum;i++)				/*释放弧的相关信息*/
		for(j=0;j<G->vexnum;j++)
			if(G->arc[i][j].adj!=0)	/*如果存在弧*/
				if(G->arc[i][j].info!=NULL) /*如果弧有相关信息，释放该信息所占用空间*/
				{
					free(G->arc[i][j].info);
					G->arc[i][j].info=NULL;
				}
				G->vexnum=0;	 			/*将有向图的顶点数置为0*/
				G->arcnum=0; 				/*将图的弧的数目置为0*/
}
void DisplayGraph(MGraph G)
/*输出邻接矩阵存储表示的图G*/
{ 
	int i,j;
	cout<<"有向图具有"<<G.vexnum<<"个顶点"<<G.arcnum<<"条弧，顶点依次是: ";
	for(i=0;i<G.vexnum;++i)				/*输出图的顶点*/
		cout<<"  "<<G.vex[i];
	cout<<endl<<"有向图G:"<<endl;			
	/*输出图G的邻接矩阵*/
	cout<<"顶点：";
	for(i=0;i<G.vexnum;i++)
		cout<<setw(4)<<G.vex[i];
	cout<<endl;
	for(i=0;i<G.vexnum;i++)
	{
		cout<<setw(6)<<G.vex[i];
		for(j=0;j<G.vexnum;j++)
			cout<<setw(4)<<G.arc[i][j].adj;
		cout<<endl; 
	}
}
void ConvertGraph(AdjGraph *A,MGraph M)
//将采用邻接矩阵表示的有向图M转换成邻接表A
{ 
	int i,j;
	ArcNode *p;
	A->vexnum=M.vexnum;
	A->arcnum=M.arcnum;
	A->kind=M.kind;
	for(i=0;i<A->vexnum;i++)			/*将顶点存储在头结点中*/
	{
		strcpy(A->vertex[i].data,M.vex[i]);
		A->vertex[i].firstarc=NULL;	/*将相关联的顶点置为空*/
	}
	printf("请输入弧尾和弧头(以空格作为间隔):\n");
	for(i=0;i<M.arcnum;i++)			/*建立边链表*/
		for(j=0;j<M.arcnum;j++)
			if(M.arc[i][j].adj==1)
			{	
				/*j为弧头i为弧尾创建邻接表*/
				p=(ArcNode*)malloc(sizeof(ArcNode));
				p->adjvex=j;
				p->info=NULL;
				p->nextarc=A->vertex[i].firstarc;
				A->vertex[i].firstarc=p;
			}
			
			(*A).kind=DG;
}
void DisplayAdjGraph(AdjGraph G)
/*输出图的邻接矩阵G*/
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