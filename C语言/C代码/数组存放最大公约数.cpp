#include <stdio.h>
#include <math.h>

//By ChenAO 2021.10.27
int main() {
	int m, n, my, ny, mi, ni, i;
	scanf("%d %d", &m, &n);
//约数好求，最大约数也好求，但这个公不好找啊（公找不到，就找母的）
//这个时候就要用到我偷偷卷出来的数组
//看好了啊
//先判断此时有几个约数
	for (i = 1, mi = 0; i <= m - 1; i++) { //mi计算有几个约数
		if (m % i != 0)
			continue;
		else {
			mi++;
		}
	}
//不想用开平方优化了，凑合看吧，接下来往数组里赋值 mi-1
	int m1[mi];
	for (i = 1, mi = 0; i <= m - 1; i++) {
		if (m % i != 0)
			continue;
		else {
			m1[mi] = i;
			mi++;
		}
	}
//复制粘贴改成n的
	for (i = 1, ni = 0; i <= n - 1; i++) {
		if (n % i != 0)
			continue;
		else {
			ni++;
		}
	}
	int n1[ni];
	for (i = 1, ni = 0; i <= n - 1; i++) {
		if (n % i != 0)
			continue;
		else {
			n1[ni] = i;
			ni++;
		}
	}
	
}
