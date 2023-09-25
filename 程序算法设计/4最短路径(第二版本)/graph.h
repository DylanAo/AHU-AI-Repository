#pragma once

#define SIDE_NUM 16
#define POINT_NUM 12
#define INFINITE 255
#define NO_PRODROMAL -1

#include <iostream>
using namespace std;



struct site_information {
	int departure;
	int destination;
	int weight;
};

class Graph {
private:
	site_information site[SIDE_NUM];
	int map[POINT_NUM][POINT_NUM];
	int path[POINT_NUM][POINT_NUM];
	bool dijstra(int point_index);

public:
	Graph(int departure[], int destination[], int weight[]);
	void print(int departure, int destination);
	void print();

};