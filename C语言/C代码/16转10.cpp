#include <stdio.h>
#include <math.h>

int main() {
	int n, a, b, sum = 0;
	scanf("%d", &n);
	b = n;
	for (int i = 0; b != 0; i++) {
		a = b % 10; //��һλ
		sum += a * pow(16, i);
		b = (b - a) / 10; //����һλ
	}
	printf("%d", sum);
}