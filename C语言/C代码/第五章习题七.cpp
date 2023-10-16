#include <stdio.h>

int main() {
	int i;
	float sum = 0;
	for (i = 1; i <= 100; i++)
		sum += i;
	for (i = 1; i <= 50; i++)
		sum += i * i;
	for (i = 1; i <= 10; i++)
		sum += 1.0 / i;
	printf("%f", sum);

}