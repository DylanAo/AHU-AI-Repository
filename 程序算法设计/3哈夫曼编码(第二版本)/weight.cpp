#include"weight.h"

Weight::Weight(string str) {
	for (int i = 0; i < str.length(); i++) {
		char c = str[i];
		all_table[(int)c]++;
	}
	size = 0;
	for (int i = 0; i < 256; i++) {
		if (all_table[i] != 0) {
			size++;
		}
	}
	size = length();
	int index = 0;
	for (int i = 0; i < 256; i++) {
		if (all_table[i] != 0) {
			table[index].character = i;
			table[index].weight = all_table[i];
			index++;
		}
	}
}

int Weight::length() {	
	return size;
}

Weight_node* Weight::get() {
	return table;
}

int Weight::get(int index, int mode) {
	if (mode == WEIGHT) {
		return table[index].weight;
	}
	else if (mode == CHAR) {
		return table[index].character;
	}
	else{
		return 0;
	}
}