#include <stdio.h>

int main() {
	int a[10];
	int i, i2, i3, i4, t;
	for (i3 = 0; i3 <= 9; i3++)
		scanf("%d", &a[i3]);
	for (i = 1; i <= 9; i++)
		for (i2 = 0; i2 <= 10 - i; i2++) {
			if (a[i2] > a[i2 + 1]) {
				t = a[i2];
				a[i2] = a[i2 + 1];
				a[i2 + 1] = t;
			}
		}
	for (i4 = 9; i4 >= 0; i4--)
		printf("%d\n", a[i4]);
	return 0;
}