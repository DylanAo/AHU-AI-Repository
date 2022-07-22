#include "hash.h"

int main() {
	hash H;
	create_hash(H);
	int number[12] = { 12,14,25,67,89,21,34,56,70,79,35,37 };
	for (int i = 0; i < 12; i++) {
		in_hash(H, number[i]);
	}
	int key = 0;
	scanf("%d", &key);
	if (search_hash(H, key)) {
		printf("Yes");
	}
	else {
		printf("No\n");
		print_hash(H, key);
	}
}