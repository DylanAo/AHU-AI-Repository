#include <stdio.h>

int main() {
	int a[10];
	int i, k, j, t;
	for (i = 0; i < 10; i++)
		scanf("%d", &a[i]);
	for (i = 0; i < 10; i++) {
		k = i; //k�;�����С���Ǹ�
		for (j = 1 + i; j <= 9; j++)
			if (a[j] < a[k])
				k = j; //�����޸ĵ�ֻ���ĸ�������С����������ֵ�䶯
		if (i != k) { //�����һ���ҵ��Ǹ�������С�ľ�û�б�Ҫ����
			t = a[i];
			a[i] = a[k];
			a[k] = t; //��k������ǰ��ֵ
		}
	}
	for (i = 0; i < 10; i++)
		printf("%d ", a[i]);
	return 0;
}

