#include <stdio.h>
#include <math.h>
//By ChenAo 2021.11.2

int main() {
	int a = 2, b, n, i, i2 = 0, sum1 = 0, sum2 = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (; i2 < i; i2++) {//不能在此将i2=0,否则每次否会多算，达不到幂的效果
			b = a * pow(10, i2);
			sum2 += b;
		}
		sum1 += sum2;
	}
	printf("%d", sum1);
}