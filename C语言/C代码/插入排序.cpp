#include <stdio.h>

int main() {
	int a[5];
	int t;
	for (int i = 0; i < 5; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < 5; i++)
		printf("%d ", a[i]);
	printf("\n");
	for (int i = 1; i < 5; i++) {
		t = a[i];
		if (a[i] < a[i - 1]) {
			for (int j = i - 1; (j >= 0 ) && (a[j] > t); j--) {
				a[j + 1] = a[j];
				a[j] = t;
			}
		}
	}
	for (int i = 0; i < 5; i++)
		printf("%d ", a[i]);
}