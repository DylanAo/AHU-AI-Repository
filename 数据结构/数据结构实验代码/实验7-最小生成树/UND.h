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

typedef struct {
	char Head;
	char Tail;
	int lowcost;
}Edge;
//��������ͼ
int create_Graph(Graph& G);
//��С����������³˹�����㷨
void MCST_Kruskal(Graph G);
#endif // !UND__H__
