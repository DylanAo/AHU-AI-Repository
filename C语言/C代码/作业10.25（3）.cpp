#include <stdio.h>

//By ChenAo 2021.10.25
int main() {
	long long int a, b, c, sum;
	a = 1;
	sum = 0;
	do {
		b = c = 1;
		do {
			c = c * b;
			b++;
		}	while (b <= a);
		a++;
		sum = sum + c;
	}	while (a <= 20);
	printf("%lld\n", sum);
	return 0;
}