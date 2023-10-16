#include <stdio.h>

int main() {
	float a, b, c, d, e, f, i;
	float sum;
	a = 2.0;
	c = 3.0;
	b = 1.0;
	d = 2.0;
	sum = 2.0 / 1 + 3.0 / 2;
	for (i = 1; i <= 18; i++) {
		e = a + c;
		a = c;
		c = e;
		f = b + d;
		b = d;
		d = f;
		sum += e / f;
	}
	printf("%f\n", sum);
	return 0;
}
