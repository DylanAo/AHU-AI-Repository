#include <stdio.h>

void swap (int *);
int main() {
	int a[4][4];

	for (int i = 0; i <= 3; i++)
		for (int j = 0; j <= 3; j++)
			scanf("%d", &a[i][j]);

	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++)
			printf("%d ", a[i][j]);

		printf("\n");
	}

	printf("\n");
	swap(&a[0][0]);

	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++)
			printf("%d ", a[i][j]);

		printf("\n");
	}
}

void swap (int *p) {
	int t;

	for (int j = 0; j <= 15; j++)
		if (*p > *(p + j)) {
			int t;
			t = *(p + j);
			*(p + j) = *p;
			*p = t;
		}

	for (int j = 1; j <= 15; j++) {
		if (*(p + 4) > *(p + j)) {
			int t;
			t = *(p + j);
			*(p + j) = *(p + 4);
			*(p + 4) = t;
		}
	}

	for (int j = 1; j <= 15; j++) {
		if (j == 4)
			continue;

		if (*(p + 8) > *(p + j)) {
			int t;
			t = *(p + j);
			*(p + j) = *(p + 8);
			*(p + 8) = t;
		}
	}

	for (int j = 1; j <= 15; j++) {
		if (j == 4 || j == 8)
			continue;

		if (*(p + 12) > *(p + j)) {
			int t;
			t = *(p + j);
			*(p + j) = *(p + 12);
			*(p + 12) = t;
		}
	}
}
