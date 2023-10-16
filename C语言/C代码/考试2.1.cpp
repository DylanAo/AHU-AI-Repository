#include <stdio.h>

int main() {
	char a[10];

	for (int i = 0; i <= 9; i++)
		scanf("%c", &a[i]);

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9 - i; j++)
			if (a[j] > a[j + 1]) {
				char t;
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}

	for (int i = 0; i <= 9; i++)
		printf("%c ", a[i]);
}