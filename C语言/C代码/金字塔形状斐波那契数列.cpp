#include <stdio.h>

//By ChenAo 2021.11.6
int main() {
	int a = 0, b = 1, c, t, i, n = 0, m = 2;
	printf("1\n");
	for (i = 0; i <= 19; i++) {
		//斐波那契数列运算
		c = a + b;
		printf("%d ", c);
		t = b;
		b = c;
		a = t;
		//下面开始控制金字塔
		n++;
		if ( n / m   == 1) {
			printf("\n");
			n = 0;
			m++;
		}
	}
}