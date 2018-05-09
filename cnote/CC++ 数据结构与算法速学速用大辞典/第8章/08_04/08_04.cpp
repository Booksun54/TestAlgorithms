#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
const int N=100;
int G[N][N];//0表示不存在弧，1表示存在弧
int path[N], visited[N],n,cycle;
int DFS(int u,int start)
//深度优先遍历有向图
{
	int i;
    visited[u] =-1;//顶点u标记为已访问
    path[u] =start;//记录源顶点
    for(i=0;i<n;i++) 
	{
		if(G[u][i]&&i!=start)//u到i存在弧且i不等于start
		{
			if(visited[i]<0) 
			{ 
				cycle =u;
				return 0;
			}
			if(!DFS(i,u))//若存在路径则继续深度搜索
				return 0;
		}
	}
	visited[u] =1;
	return 1;//u到i不存在弧则返回1，意味着停止此次深度搜索
}
void DisPath(int u)
//输出环中的顶点
{
    if(u<0) 
		return;
    DisPath(path[u]);
    cout<<" "<<u;
}
void main()
{
	int i,j;
	cout<<"请输入图中的顶点个数:"<<endl;
	cin>>n;
    memset(G,0,sizeof(G));
	cout<<"请输入一个"<<n<<"*"<<n<<"矩阵（1表示存在弧，0表示不存在弧）:"<<endl;
    for(i = 0;i < n;i++)
	{
		for(j = 0;j < n;j++)
		{
			cin>>G[i][j];
		}
    }
	cycle =-1;
	for(i=0;i<n;i++) 
	{
		if(!visited[i]&&!DFS(i,-1))//顶点i还没有被访问
			break;
	}
	if(cycle<0)
		cout<<"不存在环!"<<endl;
	else
	{
		cout<<"存在环!"<<endl;
		DisPath(cycle);
		cout<<endl;
	}
}