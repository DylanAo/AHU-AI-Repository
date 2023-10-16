#include <stdio.h>

int main() {
	int a[3];
	for (int i = 0; i <= 2; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2 - i; j++)
			if (a[j] < a[j + 1]) {
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
	for (int i = 0; i <= 2; i++)
		printf("%d", a[i]);
}