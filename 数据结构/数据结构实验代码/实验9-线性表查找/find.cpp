#include "find.h"

void create_sqlist(Sqlist& L,int *data) {
	L.key = new int[11];
	L.length = 10;
	L.key[0] = 0;
	for (int i = 1; i <= 10; i++) {
		L.key[i] = data[i-1];
	}
}

int sequential_search(Sqlist L,int tag) {
	int i = 0;
	L.key[0] = tag;
	for (i = L.length; L.key[i] != L.key[0]; i--);
	return i;
}

int binary_search(Sqlist L, int tag) {
	int low = 1, high = L.length, middle = 0;
	while (low<=high) {
		middle = (low + high)/2;
		if (L.key[middle] == tag) return middle;
		if (tag < L.key[middle]) high = middle - 1;
		else low = middle + 1;
	}
	return 0;
}