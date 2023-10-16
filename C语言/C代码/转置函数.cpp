#include <stdio.h>

int main() {
	void change (int a[3][3]);
	int a[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9 };
	change(a);
}

void change (int a[3][3]) {
	int i, i2;;
	int b[3][3];
	for (i = 0; i < 3; i++)
		for (i2 = 0; i2 < 3; i2++)
			b[i2][i] = a[i][i2];
	for (i2 = 0; i2 < 3; i2++) {
		for (i = 0; i < 3; i++)
			printf("%-3d ", b[i2][i]);
		printf ("\n");
	}
}