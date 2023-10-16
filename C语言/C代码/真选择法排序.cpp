#include <stdio.h>

int main() {
	int a[10] = {3, 4, 1, 2, 6, 5, 7, 9, 0, 1}, t = 0, max = 0;

	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]);

	putchar('\n');

	for (int i = 0; i < 10; i++) {
		max = a[i];

		for (int j = i; j < 10; j++) {

			if (max < a[j]) {
				max = a[j];
				t = j;
			}

		}

		a[t] = a[i];
		a[i] = max;
	}

	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]);
}