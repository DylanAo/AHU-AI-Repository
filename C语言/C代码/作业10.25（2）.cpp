#include <stdio.h>

//By ChenAo 2021.10.25
int main() {
	long long int a, b, c, sum;
	a = 1;
	sum = 0;
	while (a <= 20) {
		b = c = 1;
		while (b <= a) {
			c = c * b;
			b++;
		}
		a++;
		sum = sum + c;
	}
	printf("%lld\n", sum);
	return 0;
}