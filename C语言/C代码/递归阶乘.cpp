#include <stdio.h>

//Çó½×³Ë
int main() {
	double jc (double x);
	double n;
	scanf("%lf", &n);
	if (n == 0)
		printf("1");
	else
		printf ("%lf", jc(n));
	return 0;
}

double jc (double x) {
	double an;
	if (x != 1)
		return an = x * jc(x - 1);
	else
		return 1;
}