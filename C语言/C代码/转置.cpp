#include <stdio.h>

int main() {
	int i, i2;
	int a[3][2], b[2][3];
	for (i = 0; i < 3; i++) { //ÐÐ
		for (i2 = 0; i2 < 2; i2++) { //ÁÐ
			scanf ("%d", &a[i][i2]);
		}
	}
	for (i = 0; i < 3; i++) {
		for (i2 = 0; i2 < 2; i2++) {
			printf ("%-5d ", a[i][i2]);
		}
		printf("\n");
	}
	printf("\n");
	for (i = 0; i < 3; i++) {
		for (i2 = 0; i2 < 2; i2++) {
			b[i2][i] = a[i][i2];
		}
	}
	for (i2 = 0; i2 < 2; i2++) {
		for (i = 0; i < 3; i++) {
			printf("%-5d ", b[i2][i]);
		}
		printf ("\n");
	}
	return 0;
}