#include <stdio.h>

//该数组三行两列
int main() {
	int i, i2, i3, i4, ad;
	int a[3][2];
	//输入数组
	for (i = 0; i < 3; i++) {
		for (i2 = 0; i2 < 2; i2++) {
			scanf ("%d", &a[i][i2]);
		}
	}
	//展示数组
	for (i = 0; i < 3; i++) {
		for (i2 = 0; i2 < 2; i2++) {
			printf ("%-5d ", a[i][i2]);
		}
		printf("\n");
	}
	printf("\n");
	//判断鞍点
	for (i = 0; i < 3; i++) {
		for (i2 = 0; i2 < 2; i2++) {
			ad = a[i][i2];
			for (i4 = 0; i4 < 2; i4++) { //行最大
				if (i4 == i2) { //把自己扣除
					continue;
				} else {
					if (ad <= a[i][i4])//带等号为了满足最
						break;
				}
			}
			for (i3 = 0; i3 < 3; i3++) { //列最小
				if (i3 == i) {//把自己扣除
					continue;
				} else {
					if (ad >= a[i3][i2])//带等于号是为了满足最
						break;
				}
			}
			if ((i4 == 2 ) && (i3 == 3))
				printf("鞍点是%d\n", ad);
		}
	}
}