#ifndef UND__H__
#define UND__H__
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

//创建无向图
int creategraph(Graph& G);
//打印临接矩阵
int print_graph(Graph G);
//深度遍历
void DFS(Graph G, char v);
#endif // !UND__H__