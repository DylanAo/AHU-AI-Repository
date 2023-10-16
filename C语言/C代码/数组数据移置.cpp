#include <stdio.h>

int main() {
	void get (int *, int);
	void put (int *, int);
	void move (int *, int, int);
	int n, m;
	scanf("%d %d", &n, &m);
	int a[n];
	get (a, n);
	put (a, n);
	move (a, n, m);
	put (a, n);
}

void move(int *p, int n, int m) {
	int b[n];
	int *q = b;
	int i;
	for (i = n - m; i <= n - 1; i++) //后几个
		*q++ = *(p + i);
	for (i = 0; i <= n - m - 1; i++)//前几个
		*q++ = *p++;
	q = b;
	p -= n - m;
	for (i = 0; i <= n - 1; i++)
		*p++ = *q++;
}

void get(int *p, int n) {
	int i;
	for (i = 0; i <= n - 1; i++)
		scanf("%d", p++);
}

void put (int *p, int n) {
	int i;
	for (i = 0; i <= n - 1; i++)
		printf("%d ", *p++);
	putchar('\n');
}