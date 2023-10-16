#include <stdio.h>
#include <math.h>

//By ChenAo 2021.10.27
int main() {
	int m, n, i, i2, e1;
	scanf("%d %d", &m, &n);
	m < n ? i2 = m : i2 = n; //找最小
	for (i = 2; i <= i2; i++) {
		if (m % i == 0 && n % i == 0)
			e1 = i; //最后一个肯定是最大公约数
	}
	if (e1 == 0)
		printf("没有最大公约数\n");
	else
		printf("最大公约数为%d\n", e1);
//由百度可知，两个数乘积等于最大公约数和最小公倍数乘积(绝了，这个）
	if (e1 == 0)
		printf("没有最小公倍数\n");
	else {
		printf("最小公倍数为%d\n", n * m / e1);
	}
}