#include <stdio.h>

int main() {
	void swap (int a[]);
	int a[6] = {1, 2, 3, 4, 5, 6};
	int i;
	for (i = 0; i <= 5; i++)
		printf("%d", a[i]);
	swap(a);
	putchar('\n');
	for (i = 0; i <= 5; i++)
		printf("%d", a[i]);
}

void swap (int a[]) {
	int *p = a;
	int *q = &a[5];
	int t;
	for (; p <= q; p++, q--) {//Å¼ÊýÊÇ<
		t = *p;
		*p = *q;
		*q = t;
	}
}