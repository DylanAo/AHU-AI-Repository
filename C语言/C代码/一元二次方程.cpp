#include <stdio.h>
#include <math.h>

int main () {
	float a, b, c, deta, a1, a2;
	scanf("%f %f %f", &a, &b, &c);
	for (;;) {
		if (b * b - 4 * a * c < 0 || a == 0)
			scanf("%f %f %f", &a, &b, &c);
		else
			break;
	}
	deta = sqrt(b * b - 4 * a * c);
	if (deta == 0)
		printf("%f", -b / 2.0 / a);
	else {
		a1 = -b / 2.0 / a;
		a2 = deta / 2 / a;
		printf("%f,%f", a1 = a2, a1 - a2);
	}

}