#ifndef Dijkstra__H__
#define Dijkstra__H__
#define MaxInt 32767
#define Max 100
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
typedef struct {
	char vexs[Max];
	int arcs[Max][Max];
	int venxum, arcnum;
}Graph;

//创建图
int create_graph(Graph& G);
//迪杰斯特拉算法
void dijkstra(Graph G, int* Path, int v0);
//输出最短路径
void print_min_rote(int* Path, Graph G);
#endif 
