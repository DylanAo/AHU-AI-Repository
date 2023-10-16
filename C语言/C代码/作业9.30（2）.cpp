#include <stdio.h>

//By ChenAo
int main() {
	int a, b, c, d;
	scanf("%d,%d,%d", &a, &b, &c);
	int max(int x, int y);
	d = max(a, b);
	d = max(d, c);
	printf("The max is %d\n", d);
	return 0;
}

int max(int x, int y) {
	int z;
	if (x > y)
		z = x;
	else
		z = y;
	return (z);
}