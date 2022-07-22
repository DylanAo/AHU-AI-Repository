#include "UND.h"
int findvex(char* vexs, char v) {
	int i = 0;
	while (v != vexs[i]) i++;
	return i;
}

int creategraph(Graph& G) {
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
int visited[Max]={0};

int print_graph(Graph G) {
	int i = 0, j = 0;
	for (i = 0; i < G.venxum; i++) {
		for (j = 0; j < G.venxum; j++) printf("%d ", G.arcs[i][j]);
		printf("\n");
	}
	return 1;
}

char find_vex(Graph G,char v) {
	int k=0,i=0;
	k=findvex(G.vexs,v);
	for (i = 0; i < G.venxum; i++) 
		if (G.arcs[k][i]&&!visited[i]) return G.vexs[i];
	return '0';
}


void DFS(Graph G,char v) {
	int i = 0;
	char w;
	printf("%c ", v);
	visited[findvex(G.vexs, v)]=1;
	for (w = find_vex(G, v); w != '0'; w = find_vex(G, w))
		if (!visited[w]) DFS(G, w);
}