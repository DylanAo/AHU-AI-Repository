#include "find.h"

int main() {
	int data[11], tag = 0;
	Sqlist L;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &data[i]);
	}
	create_sqlist(L, data);
	scanf("%d", &tag);
	printf("%d   %d", sequential_search(L, tag), binary_search(L, tag));
}