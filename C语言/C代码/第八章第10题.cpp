#include <stdio.h>

int main() {
	void change(int *p);
	int num[5][5];
	int i, j, * p;
	p = &num[0][0];
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			scanf("%d", &num[i][j]);
		}
	}
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			printf("%3d", num[i][j]);
		}
		printf("\n");
	}
	change(p);
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			printf("%3d", num[i][j]);
		}
		printf("\n");
	}
	return 0;
}

void change(int *p) {
	int i, j, t, * max = p;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (* max < * (p + i * 5 + j))
				max = p + i * 5 + j;
		}
	}
	t = *(p + 2 * 5 + 2);
	*(p + 2 * 5 + 2) = *max;
	*max = t;

	int *min = p;
	//找到最小的值
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (*min > * (p + i * 5 + j)) {
				min = p + i * 5 + j;
			}
		}
	}
	t = *min;
	*min = *p;
	*p = t;
	min = p + 1;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (i == 0 && j == 0)
				continue;
			else if (*min > *(p + i * 5 + j)) {
				min = p + i * 5 + j;
			}
		}
	}
	t = *min;
	*min = *(p + 4);
	*(p + 4) = t;
	min = p + 1;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if ((i == 0 && j == 0) || (i == 0 && j == 4))
				continue;
			else if (*min > *(p + i * 5 + j)) {
				min = p + i * 5 + j;
			}
		}
	}
	t = *min;
	*min = *(p + 20);
	*(p + 20) = t;
	min = p + 1;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if ((i == 0 && j == 0) || (i == 0 && j == 4) || (i == 4 && j == 0))
				continue;
			else if (*min > *(p + i * 5 + j)) {
				min = p + i * 5 + j;
			}
		}
	}

	t = *min;
	*min = *(p + 24);
	*(p + 24) = t;
}
