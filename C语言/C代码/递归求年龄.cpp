#include <stdio.h>

int main() {
	int age(int x);
	printf("%d", age(5));
}

int age (int x) {
	if (x == 1)
		return 10;
	else
		return (age(x - 1) + 2);
}