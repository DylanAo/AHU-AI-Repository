#include <stdio.h>
void col(int *);
void turn(int *);

int main() {
	int i, a[25];
	for (i = 0; i < 25; i++)
		scanf("%d", &a[i]);
	turn (a);
}

void turn (int *a) {
	int b[5][5] = {0};
	int i, i2;
	col (a);
	b[2][2] = a[24];
	b[0][0] = a[0];
	b[0][4] = a[1];
	b[4][0] = a[2];
	b[4][4] = a[3];
	for (i = 0; i < 5; i++) {
		for (i2 = 0; i2 < 5; i2++)
			printf("%d ", b[i][i2]);
		printf("\n");
	}
}

//从小到大
void col (int *a) {
	int j, i, i2, t;
	for (j = 0; j <= 24; j++)
		for (i = 0; i < 24 - j; i++)
			if (a[i] > a[i + 1]) {
				t = a[i];
				a[i] = a[i + 1];
				a[i + 1] = t;
			}
}