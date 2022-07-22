#include "Dijkstra.h"

int main() {
	Graph G;
	int Path[Max];
	create_graph(G);
	dijkstra(G, Path, 0);
	print_min_rote(Path, G);
}