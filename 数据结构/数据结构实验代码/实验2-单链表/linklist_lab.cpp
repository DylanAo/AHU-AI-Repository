#include "linklist.h"

int main() {
	Linklist L;
	int a[5] = { 1,2,3,4,5 };
	create_linklist(L);
	//head_linklist(L, a, 5);
	bottom_linklist(L, a, 5);
	print_linklist(L);
	int e;
	loacted_linklist(L, 3, e);
	printf("%d\n", e);
	LNode* p = find_linklist(L, 4);
	printf("%d\n", p->data);
	deldte_linklist(L, 1);
	insert_linklist(L, 1, 9);
	print_linklist(L);
}