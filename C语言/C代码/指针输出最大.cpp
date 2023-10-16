#include <stdio.h>

int main() {
	int n, m;
	int *p;
	scanf("%d %d", &m, &n);
	n > m ? p = &n : p = &m;
	printf("%d", *p);
}