#include <stdio.h>
#include <windows.h>

int main() {
	int n, a, c[100];
	scanf("%d", &n);
	int *p = c, *q = c;
	while ( n != 0) {
		a = n % 10; //第一位
		*p++ = a;
		n = (n - a) / 10; //减少一位
	}
	p--;
	while ( p > q)
		if (*p-- != *q++) {
			printf("no!");
			system("pause");
		}
	printf("yes!");
}