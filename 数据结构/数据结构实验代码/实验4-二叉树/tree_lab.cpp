#include  "tree.h"

int main() {
	Bitree T;
	char f[9] = { 'a','b','d','e','c','f'};
	char m[9] = { 'd','b','e','a','c','f'};
	T = create_tree(f, m, 0, 5, 0, 5);
	front_print(T);
	printf("\n");
	middle_print(T);
	printf("\n");
	last_print(T);
	printf("\n%d", NodeNum(T));
	printf("\n%d", deep(T));
	printf("\n%d", leaf(T));
	printf("\n%d", deep_1(T));
}