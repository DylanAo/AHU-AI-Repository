#include <stdio.h>
#include <math.h>

int main() {
	double r, h, l, s1, s2, v1, v2;
	double pi = 3.14159;
	scanf("��f %f", &r, &h);
	l = 2 * pi * r;
	s1 = pi * r * r;
	s2 = 4 * pi * r * r;
	v1 = 4 / 3 * pi * r * r * r;
	v2 = s1 * h;
	printf("Բ�ܳ�%7.2f\nԲ���%7.2f\nԲ������%7.2f\nԲ�����%7.2f\nԲ�����%7.2f\n", l, s1, s2, v1, v2);
	return 0;
}