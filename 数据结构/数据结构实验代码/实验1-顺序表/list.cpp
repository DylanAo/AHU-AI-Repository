#include "list.h"

int main() {
	list L;
	int a[5] = {1,2,3,4,5};
	create_list(L);
	indata_list(L,a);
	print_list(L);
	printf("%d\n", find_list(L, 2));
	int e = 0;
	get_list(L, 3, e);
	printf("%d\n", e);
	delete_list(L, 1);
	insert_list(L, 3, 9);
	print_list(L);
	delete_list(L, 1);
	print_list(L);
}