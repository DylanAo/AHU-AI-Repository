#include "UND.h"
#pragma warning(disable:4996)
int main() {
	Graph G;
	create_Graph(G);
	MCST_Kruskal(G);
}