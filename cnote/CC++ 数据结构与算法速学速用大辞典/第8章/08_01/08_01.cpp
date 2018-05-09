#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#include<iostream.h>
#include<iomanip.h>
typedef char VertexType[4];
typedef char InfoPtr;
typedef int VRType;
#define INFINITY 65535			/*定义一个无限大的值*/
#define MAXSIZE 100				/*最大顶点个数*/
typedef enum{DG,DN,UG,UN}GraphKind; 	/*图的类型：有向图、有向网、无向图和无向网*/
typedef struct
{
	VRType adj;				/*对于无权图，用1表示相邻，0表示不相邻；对于带权图，存储权值*/
	InfoPtr *info; 				/*与弧或边的相关信息*/
}ArcNode,AdjMatrix[MAXSIZE][MAXSIZE];
typedef struct					/*图的类型定义*/
{
	VertexType vex[MAXSIZE]; 	/*用于存储顶点*/
	AdjMatrix arc; 				/*邻接矩阵，存储边或弧的信息*/
	int vexnum,arcnum; 			/*顶点数和边（弧）的数目*/
	GraphKind kind; 			/*图的类型*/
}MGraph;
void CreateGraph(MGraph *N);
int LocateVertex(MGraph N,VertexType v);
void DestroyGraph(MGraph *N);
void DisplayGraph(MGraph N);
void main()
{
	MGraph N;
	cout<<"创建一个网："<<endl;
	CreateGraph(&N);
	cout<<"输出网的顶点和弧："<<endl;
	DisplayGraph(N);
	DestroyGraph(&N);
}
void CreateGraph(MGraph *N)
/*采用邻接矩阵表示法创建有向网N*/
{ 
	int i,j,k,w;
	VertexType v1,v2;
	cout<<"请输入有向网N的顶点数和弧数: ";
	cin>>(*N).vexnum>>(*N).arcnum;
	cout<<"请输入"<<N->vexnum<<"个顶点的值:"<<endl;
	for(i=0;i<N->vexnum;i++)		/*创建一个数组，用于保存网的各个顶点*/
		cin>>N->vex[i];
	for(i=0;i<N->vexnum;i++)		/*初始化邻接矩阵*/
		for(j=0;j<N->vexnum;j++)
		{
			N->arc[i][j].adj=INFINITY; 
			N->arc[i][j].info=NULL;	/*弧的信息初始化为空*/
		}
		cout<<"请分别输入"<<N->arcnum<<"条弧的弧尾 弧头 权值(以空格分隔):"<<endl;
		for(k=0;k<N->arcnum;k++)
		{
			cin>>v1>>v2>>w;	/*输入两个顶点和弧的权值*/
			i=LocateVertex(*N,v1);
			j=LocateVertex(*N,v2);
			N->arc[i][j].adj=w;
		}
		N->kind=DN;						/*图的类型为有向网*/
}
int LocateVertex(MGraph N,VertexType v)
/*在顶点向量中查找顶点v，找到返回在向量的序号，否则返回-1*/
{ 
	int i;
	for(i=0;i<N.vexnum;++i)
		if(strcmp(N.vex[i],v)==0)
			return i;
		return -1;
}
void DestroyGraph(MGraph *N)
/*销毁网N*/
{ 
	int i,j;
	for(i=0;i<N->vexnum;i++)				/*释放弧的相关信息*/
		for(j=0;j<N->vexnum;j++)
			if(N->arc[i][j].adj!=INFINITY)	/*如果存在弧*/
				if(N->arc[i][j].info!=NULL) /*如果弧有相关信息，释放该信息所占用空间*/
				{
					free(N->arc[i][j].info);
					N->arc[i][j].info=NULL;
				}
	N->vexnum=0;	 			/*将网的顶点数置为0*/
	N->arcnum=0; 				/*将网的弧的数目置为0*/
}
void DisplayGraph(MGraph N)
/*输出邻接矩阵存储表示的图N*/
{ 
	int i,j;
	cout<<"有向网具有"<<N.vexnum<<"个顶点"<<N.arcnum<<"条弧，顶点依次是: ";
	for(i=0;i<N.vexnum;++i)				/*输出网的顶点*/
		cout<<N.vex[i]<<" ";
	cout<<endl<<"有向网N的:"<<endl;			/*输出网N的弧*/
	cout<<"顶点：";
	for(i=0;i<N.vexnum;i++)
		cout<<setw(7)<<N.vex[i];
	cout<<endl;
	for(i=0;i<N.vexnum;i++)
	{
		cout<<setw(6)<<N.vex[i];
		for(j=0;j<N.vexnum;j++)
			cout<<setw(7)<<N.arc[i][j].adj;
		cout<<endl; 
	}
}
