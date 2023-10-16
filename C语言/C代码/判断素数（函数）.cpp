#include <stdio.h>

int prime(int x) {
	int i;
	for (i = 2; i < x; i++)
		if (x % i == 0)
			break;
	if (x == i)
		return 1;
	else
		return 0;
}

int main() {
	int a;
	scanf("%d", &a);
	if (prime(a))
		printf ("Yes.\n");
	else
		printf("No.\n");
	return 0;
}