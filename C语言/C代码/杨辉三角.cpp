#include <stdio.h>

int main() {
	int a[11] = {1};
	int b[11] = {1};
	int i, j, sum = 0;
	for (j = 1; j <= 10; j++) { //控制第几行
		if (j % 2 == 0)//判断奇偶行
			goto os;
		else
			goto js;
js://奇数行
		for (i = 0;; i++) { //控制每行输出几个
			if (i == 0) //判断是否第一个
				printf("%-4d ", 1);//细节，控制格式更好看
			if (j == 1) {//判断是否第一行
				printf("\n");
				break;
			}
			sum = a[i] + a[i + 1];
			printf ("%-4d ", sum);//细节，控制格式更好看
			b[i + 1] = sum;
			if (sum == 1) {//判断受否最后一个
				printf("\n");
				break;
			}
		}
		continue;//这里要是不结束，会导致偶数行输出两遍
os://偶数行
		for (i = 0;; i++) { //控制每行输出几个
			if (i == 0) //判断是否第一个
				printf("%-4d ", 1);//细节，控制格式更好看
			sum = b[i] + b[i + 1];
			printf ("%-4d ", sum);//细节，控制格式更好看
			a[i + 1] = sum;
			if (sum == 1) {//判断是否最后一个
				printf("\n");
				break;
			}
		}
	}
	return 0;
}