#include <stdio.h>

int main() {
	float i, a = 1000, sum = 1000;
	for (i = 1; i <= 10; i++) {
		a /= 2.0;
		sum += 2 * a;
	}
	printf("%f %f", a, sum);
}