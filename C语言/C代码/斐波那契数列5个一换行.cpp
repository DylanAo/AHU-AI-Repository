#include <stdio.h>

//By ChenAo 2021.11.6
int main() {
	int a = 0, b = 1, c, t, i, n = 0;
	for (i = 0; i <= 30; i++) {
		//斐波那契数列运算
		c = a + b;
		printf("%d ", c);
		t = b;
		b = c;
		a = t;
		//下面开始控制5个一换行
		n++;
		if ( n % 5  == 0)
			printf("\n");
	}
}