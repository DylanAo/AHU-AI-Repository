#include <stdio.h>

//By ChenAo 2021.10.25
int main() {
	long long int a, b, c, sum;
	sum = 0;
	for (a = 1; a <= 20; a++) { //���Ƶ�1��20
		for (c = 1, b = 1; b <= a; b++) //1��20�׳�
			c = c * b; //���ڲ�
		sum = sum + c;//�����
	}
	printf("%lld\n", sum);

}
