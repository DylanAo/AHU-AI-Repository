#include <stdio.h>

int main() {
	int a[10];
	int i, k, j, t;
	for (i = 0; i < 10; i++)
		scanf("%d", &a[i]);
	for (i = 0; i < 10; i++) {
		k = i; //k就就是最小的那个
		for (j = 1 + i; j <= 9; j++)
			if (a[j] < a[k])
				k = j; //这里修改的只是哪个数组最小，而不是数值变动
		if (i != k) { //如果第一次找的那个就是最小的就没有必要换了
			t = a[i];
			a[i] = a[k];
			a[k] = t; //将k中数往前赋值
		}
	}
	for (i = 0; i < 10; i++)
		printf("%d ", a[i]);
	return 0;
}

