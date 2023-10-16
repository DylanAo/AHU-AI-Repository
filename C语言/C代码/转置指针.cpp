#include <stdio.h>
void put (int *a);
void change(int *a);

int main() {
	int a[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, i, i2;
	put (&a[0][0]);
	printf("\n");
	change(&a[0][0]);
}

void change (int *a) {
	int b[3][3], i, i2;
	for (i = 0; i < 3; i++)
		for (i2 = 0; i2 < 3; i2++)
			*(*(b + i2) + i) = *a++;
	put (&b[0] [0]);
}

void put (int *a) {
	int i;
	for (i = 1; i <= 9; i++) {
		printf ("%-5d ", *a++);
		if (i % 3 == 0)
			printf("\n");
	}
	printf("\n");
}