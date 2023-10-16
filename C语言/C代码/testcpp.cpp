#include <stdio.h>

int main() {
	void swap(int *, int *);
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	swap(&a, &b);
	swap(&a, &c);
	swap(&b, &c);
	printf("%d %d %d", a, b, c);
}

void swap(int *p, int *q) {
	int t;
	if (*p > *q) {
		t = *p;
		*p = *q;
		*q = t;
	}
}