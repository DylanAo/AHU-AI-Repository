#include <stdio.h>

int main() {
	int num, a, b, c, e, i, i2;
	scanf("%d", &num);
	e = num;
	for (i = 0; num != 0; i++) {
		a = num % 10; //���һλ
		printf("%d ", a);
		num = (num - a) / 10; //��ȥһλ��ȥ��0
	}
	printf("Ϊ%dλ��\n", i);
	int d[i];
	for (i2 = 0; e != 0; i2++) {
		a = e % 10;
		e = (e - a) / 10;
		d[i2] = a;
	}
	for (; i > 0; i--) {
		printf("%d\n", d[i - 1]);
	}
}
