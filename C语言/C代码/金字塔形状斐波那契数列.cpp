#include <stdio.h>

//By ChenAo 2021.11.6
int main() {
	int a = 0, b = 1, c, t, i, n = 0, m = 2;
	printf("1\n");
	for (i = 0; i <= 19; i++) {
		//쳲�������������
		c = a + b;
		printf("%d ", c);
		t = b;
		b = c;
		a = t;
		//���濪ʼ���ƽ�����
		n++;
		if ( n / m   == 1) {
			printf("\n");
			n = 0;
			m++;
		}
	}
}