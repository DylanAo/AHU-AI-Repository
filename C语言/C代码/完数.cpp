#include <stdio.h>

//By ChenAo 2021.11.1
int main() {
	int a, i, i2, i3, sum;
	for (i = 1; i <= 1000; i++) {
		for (a = 1, i2 = 0, sum = 0; a < i; a++) { //���������Ҳ�ܳ������ʲ���<=
			if (i % a == 0) {
				sum += a;
				i2++;;//i2 �����м�������
			}
		}
		if (i == sum) {
			printf("%d its factors are ", i);
			for (a = 1, i3 = 1; a < i; a++) {
				if (i % a == 0) {
					printf("%d", a);
					if (i3 < i2) {//i3�����ǵڼ�������
						printf(",");
						i3++;
					} else
						printf("\n");
				}
			}
		}
	}
}


