#include <stdio.h>

int main() {
	float aver = 0;
	int i, i2, i3;
	int sum1 = 0;
	int a[10], b[5], c[5];
	for (i3 = 0; i3 <= 9; i3++)
		scanf("%d", &a[i3]);
	for (i3 = 0; i3 <= 9; i3++)
		sum1 += a[i3];
	aver =  sum1 / 10.0;
	for (i3 = i2 = i = 0; i3 <= 9; i3++) {
		if (a[i3] >= aver) {
			b[i2] = a[i3];
			i2++;
		} else {
			c[i] = a[i3];
			i++;
		}
	}//已经分成一半了
/*	for (i3 = 0; i3 <= 4 ; i3++)
		printf("%d ", b[i3]);
	printf("\n");
	for (i3 = 0; i3 <= 4; i3++)
		printf("%d ", c[i3]);
	printf("\n");*/
	//大于平均数部分的排序
	for (sum1=0;i3 = 0; i3 <= 4; i3++)
		sum1 += b[i3];
	aver =  sum1 / 5;
	int d[3]=0,e[3]=0;
		for (i3 = i2 = i = 0; i3 <=4 ; i3++) {
		if (b[i3] >= aver) {
			b[i2] = d[i3];
			i2++;
		} else {
			b[i] = e[i3];
			i++;
		}
}