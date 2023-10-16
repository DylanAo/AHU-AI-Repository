#include <stdio.h>
void big(int *);

int main() {
	int a[5][5] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
	big(&a[0][0]);
	int *p = &a[0][0];
	for (int i = 0; i <= 4; i++) {
		for (int i2 = 0; i2 <= 4; i2++)
			printf("%2d ", *p++);
		printf("\n");
	}
}

void big(int *a) {
	int *max = a, t;
	for (int i = 0; i <= 24; i++)
		if (*max < * (a + i))
			max = a + i;
	t = *max;
	*max = *(a + 12);
	*(a + 12) = t;

}