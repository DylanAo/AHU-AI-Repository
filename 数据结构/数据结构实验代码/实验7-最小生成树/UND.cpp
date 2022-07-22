#include "UND.h"
int findvex(char* vexs, char v) {
	int i = 0;
	while (v != vexs[i]) i++;
	return i;
}

int create_Graph(Graph& G) {
	char ch[10];
	scanf("%d", &G.venxum);
	scanf("%d", &G.arcnum);
	gets_s(ch);
	int i = 0, j = 0, k = 0;
	for (i = 0; i < G.venxum; i++) {
		scanf("%c", &G.vexs[i]);
		getchar();
	}
	for (i = 0; i < G.arcnum; i++)
		for (j = 0; j < G.arcnum; j++)
			G.arcs[i][j] = 0;
	for (k = 0; k < G.arcnum; k++) {
		char v1, v2;
		int data;
		i = 0;
		j = 0;
		scanf("%c %c %d", &v1, &v2, &data);
		getchar();
		i = findvex(G.vexs, v1);
		j = findvex(G.vexs, v2);
		G.arcs[i][j] = data;
		G.arcs[j][i] = data;
	}
	return 1;
}

void sort(Edge *edge,Graph G) {
	int i = 0,j = 0;
	for (i = 0; i < G.arcnum- 1; i++) {
		for (j = 0; j < G.arcnum - i - 1; j++) {
			if (edge[j].lowcost > edge[j + 1].lowcost) {
				Edge change;
				change = edge[j];
				edge[j] = edge[j + 1];
				edge[j + 1] = change;
			}
		}
	}
}

void create_edge(Graph G, Edge *edge) {
	int k = 0;
	for (int i = 0; i < G.arcnum; i++) {
		for (int j = i; j < G.arcnum; j++) {
			if (G.arcs[i][j]) {
				edge[k].Head = G.vexs[i];
				edge[k].Tail = G.vexs[j];
				edge[k].lowcost = G.arcs[i][j];
				k++;
			}
		}
	}
}
void MCST_Kruskal(Graph G) {
	Edge edge[Max];
	create_edge(G, edge);
	sort(edge,G);
	int Vexset[Max];
	for (int i = 0; i < G.arcnum; i++)
		Vexset[i] = i;
	for (int i = 0; i < G.arcnum; i++) {
		int v1 = findvex(G.vexs, edge[i].Head);
		int v2 = findvex(G.vexs, edge[i].Tail);
		int v1s = Vexset[v1];
		int v2s = Vexset[v2];
		if (v1s != v2s) {
			printf("%c----%c\n", edge[i].Head, edge[i].Tail);
			for (int j = 0; j < G.venxum; j++) {
				if (Vexset[j] == v2s) Vexset[j] = v1s;
			}
		}
	}
}