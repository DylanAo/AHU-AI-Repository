#include <stdio.h>

int main() {
	int i, i2, sum;
	int a[3][3];
	for (i = 0; i < 3; i++) { //ÐÐ
		for (i2 = 0; i2 < 3; i2++) { //ÁÐ
			scanf ("%d", &a[i][i2]);
		}
	}
	printf("\n");
	sum = a[0][0] + a[1][1] + a[2][2] + a[2][0] + a[0][2];
	printf("%d", sum);
}