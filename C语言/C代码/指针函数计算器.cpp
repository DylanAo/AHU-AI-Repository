#include <stdio.h>

float add (float, float);
float jian (float, float);
float cheng (float, float);
float chu (float, float);
int main() {
	float a, b;
	char c;
	float (*p)(float, float);
scan:
	scanf("%f %c %f", &a, &c, &b);
	switch (c) {
		case ('+'):
			p = add;
			break;
		case ('-'):
			p = jian;
			break;
		case ('*'):
			p = cheng;
			break;
		case ('/'):
			p = chu;
			break;
		default:
			goto scan;
	}
	printf("%-5.2f", (*p)(a, b));
}

float add (float x, float y) {
	return (x + y);
}

float jian (float x, float y) {
	return (x - y);
}

float cheng (float x, float y) {
	return (x * y);
}

float chu (float x, float y) {
	return (x / y);
}