#pragma once

#include <string>
#include <iostream>

using namespace std;

#define WEIGHT 1
#define CHAR 2

struct Weight_node {
	char character;
	int weight;
};

class Weight {
private:
	int all_table[256] = {};
	int size;
	Weight_node table[256];

	
public:
	Weight(string str);
	Weight_node* get();
	int length();
	int get(int index, int mode);
};