#include <stdio.h>

//By ChenAo 2012.10.20
int main () {
	float x;
	scanf("%f", &x);
	if (x < 1)
		printf("%f", x);
	else if (x >= 1 && x < 10)
		printf("%f", 2 * x - 1);

	else if (x > 10)
		printf("%f", 3 * x - 11);
	return 0;
}