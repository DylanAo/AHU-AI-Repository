#include <stdio.h>

//By ChenAo 2021.11.1
int main() {
	float f1 = 1, f2 = 1, f3 = 0, f4 = 1, e1, e2, sum;
	int i;
	for (i = 1; i <= 20; i++) {
		//分子
		e1 = f1 + f2;
		f1 = f2;
		f2 = e1;
		//分母
		e2 = f3 + f4;
		f3 = f4;
		f4 = e2;
		//求和
		sum += e1 / e2;
	}
	printf("%f\n", sum);
	return 0;
}