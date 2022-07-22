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

//����ͼ
int create_graph(Graph& G);
//�Ͻ�˹�����㷨
void dijkstra(Graph G, int* Path, int v0);
//������·��
void print_min_rote(int* Path, Graph G);
#endif 
