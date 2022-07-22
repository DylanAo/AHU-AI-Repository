#include "list.h"
int create_list(list& L) {
	L = new listnode;
	L->data = new int[5];
	if (!L->data) return -1;
	L->length = 0;
	return 1;
}

int indata_list(list& L, int* a) {
	int i = 0;
	for (i = 0; i < max; i++) L->data[i] = *(a + i);
	L->length = max;
	return 1;
}

int print_list(list L) {
	int i = 0;
	for (i = 0; i < L->length; i++) printf("%d ", L->data[i]);
	printf("\n");
	return 1;
}

int get_list(list L, int n, int& e) {
	if (n<1 || n>L->length) return -1;
	e = L->data[n - 1];
	return 1;
}

int find_list(list L, int e) {
	int i = 0;
	for (i = 0; i < L->length; i++) 
		if (L->data[i] == e) return i + 1;
	return 0;
}

int delete_list(list& L, int i) {
	if (i<1 || i>L->length) return -1;
	int j = 0;
	for (j = i; j < L->length; j++) L->data[j - 1] = L->data[j];
	L->length--;
	return 1;
}

int insert_list(list& L, int i,int e) {
	if (i<1 || i>L->length+1) return -1;
	if (L->length == max) return -1;
	int j = 0;
	for (j = L->length; j > i - 1; j--) L->data[j] = L->data[j-1];
	L->length++;
	L->data[i - 1] = e;
	return 1;
}