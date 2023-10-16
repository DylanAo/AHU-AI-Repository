#include <stdio.h>

//By ChenAo 2021.11.1
int main() {
	int a, i, i2, i3, sum;
	for (i = 1; i <= 1000; i++) {
		for (a = 1, i2 = 0, sum = 0; a < i; a++) { //本身除本身也能除尽，故不能<=
			if (i % a == 0) {
				sum += a;
				i2++;;//i2 计算有几个因数
			}
		}
		if (i == sum) {
			printf("%d its factors are ", i);
			for (a = 1, i3 = 1; a < i; a++) {
				if (i % a == 0) {
					printf("%d", a);
					if (i3 < i2) {//i3计算是第几个因数
						printf(",");
						i3++;
					} else
						printf("\n");
				}
			}
		}
	}
}


