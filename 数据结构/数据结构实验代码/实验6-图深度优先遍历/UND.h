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

//��������ͼ
int creategraph(Graph& G);
//��ӡ�ٽӾ���
int print_graph(Graph G);
//��ȱ���
void DFS(Graph G, char v);
#endif // !UND__H__