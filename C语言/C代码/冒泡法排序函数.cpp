#include <stdio.h>
int a[10];

int main() {
	void col ();
	int i;
	for (i = 0; i <= 9; i++)
		scanf("%d", &a[i]);
	col();
	for (i = 0; i <= 9; i++)
		printf ("%d ", a[i]);
}

void col () {
	int j, i, t;
	for (j = 0; j <= 9; j++)
		for (i = 0; i < 9 - j; i++)
			if (a[i] > a[i + 1]) {
				t = a[i];
				a[i] = a[i + 1];
				a[i + 1] = t;
			}
}