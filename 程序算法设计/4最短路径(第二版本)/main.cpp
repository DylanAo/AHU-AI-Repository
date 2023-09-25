#include <iostream>
#include"graph.h"
using namespace std;


int main() {
	int departure[SIDE_NUM] = {0, 1, 1, 2, 3, 4, 5, 6, 5, 5, 5, 9, 7, 10, 8, 10};
	int destination[SIDE_NUM] = {1, 2, 3, 3, 4, 5, 6, 7, 7, 8, 9, 8, 10, 8, 10, 11};
	int weight[SIDE_NUM] = {6, 6, 1, 2, 12, 2, 2, 1, 2, 2, 9, 9, 1, 2, 2, 5};
	Graph huangshan(departure, destination, weight);
	//huangshan.print(0, 2);
	huangshan.print();
}