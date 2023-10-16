#include <stdio.h>

//By ChenAo 2021.10.25
int main() {
	long long int a, b, c, sum;
	sum = 0;
	for (a = 1; a <= 20; a++) { //控制的1到20
		for (c = 1, b = 1; b <= a; b++) //1到20阶乘
			c = c * b; //最内层
		sum = sum + c;//最外层
	}
	printf("%lld\n", sum);

}
