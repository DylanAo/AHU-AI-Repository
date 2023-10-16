#include <stdio.h>

int main() {
	long a, b, c;
	scanf("%ld", &a);
	b = a / 100000;
	printf("%d\n", b);
	switch (b) {
		case 0:
			printf("%ld", a *= 0.1);
			break;
		case 1:
			printf("%d", a = 10000 + (a - 100000) * 0.075);
			break;
		case 2:
		case 3:
		default:
			printf("0");
	}
}