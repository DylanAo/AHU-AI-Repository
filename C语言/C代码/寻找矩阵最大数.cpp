#include <stdio.h>

int main() {
	int i, i2, max, h, l;
	int a[3][2];
	for (i = 0; i < 3; i++) {
		for (i2 = 0; i2 < 2; i2++)
			scanf ("%d", &a[i][i2]);
	}
	for (i = 0; i < 3; i++) {
		for (i2 = 0; i2 < 2; i2++) {
			printf ("%-5d ", a[i][i2]);
		}
		printf("\n");
	}
	printf("\n");
	max = a[0][0];
	h = l = 0;
	for (i = 0; i < 3; i++) {
		for (i2 = 0; i2 < 2; i2++) {
			if (max < a[i][i2]) {
				max = a[i][i2];
				h = i;
				l = i2;
			}
		}
	}
	printf ("%d %d %d", max, h + 1, l + 1);
	return 0;
}