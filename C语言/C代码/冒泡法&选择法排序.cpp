#include <stdio.h>

int main() {
	int a[10] = {9, 4, 2, 1, 3, 4, 6, 7, 8, 1};

	/*
	Ã°ÅÝ·¨
		for (int i = 0; i <= 9; i++)
			for (int j = 0; j <= 9 - i; j++)
				if (a[j] < a[j + 1]) {
					int t = a[j];
					a[j] = a[j + 1];
					a[j + 1] = t;
				}

		for (int i = 0; i <= 9; i++)
			printf("%d ", a[i]);*/
//Ñ¡Ôñ·¨
	for (int i = 0; i <= 9; i++)
		for (int j = i + 1; j <= 9; j++)
			if (a[i] < a[j]) {
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}

	for (int i = 0; i <= 9; i++)
		printf("%d ", a[i]);
}