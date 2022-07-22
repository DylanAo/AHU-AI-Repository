#include "Dijkstra.h"
int findvex(char* vexs, char v) {
	int i = 0;
	while (v != vexs[i]) i++;
	return i;
}

int create_graph(Graph& G) {
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
			G.arcs[i][j] = MaxInt;
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
	}
	return 1;
}

void dijkstra(Graph G, int *Path,int v0) {
	int n = G.venxum, i = 0,w = 0,v = 0;
	int visited[Max], D[Max];
	for (v = 0; v < n; v++) {
		visited[v] = 0;
		D[v] = G.arcs[v0][v];
		if (D[v] < MaxInt) Path[v] = v0;
		else Path[v] = -1;
	}
	visited[v0] = 1;
	D[v0] = 0;
	for (i = 1; i < n; i++) {
		int min = MaxInt;
		for (w = 0; w < n; w++) {
			if (!visited[w] && D[w] < min) {
				v = w;
				min = D[w];
			}
		}
		visited[v] = 1;
		for (w = 0; w < n; w++) {
			if (!visited[w] && (D[v] + G.arcs[v][w] < D[w])) {
					D[w] = D[v] + G.arcs[v][w];
					Path[w] = v;
			}
		}
	}
}

int find_min_rote(int* path,int n) {
	if (path[n] == -1) return n;
	else {
		int i=find_min_rote(path, path[n]);
		printf("%d-->", path[n]);
		return i;
	}
}

void print_min_rote(int* Path, Graph G) {
	for (int i = 0; i < G.venxum; i++) {
		int n = find_min_rote(Path, i);
		if (n != i) printf("%d\n", i);
		else if (n == 0) printf("%d is source\n", n);
		else printf("No way from 0 to %d\n", i);
	}
}