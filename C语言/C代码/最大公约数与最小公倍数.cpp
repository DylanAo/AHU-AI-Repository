#include <stdio.h>
#include <math.h>

//By ChenAo 2021.10.27
int main() {
	int m, n, i, i2, e1;
	scanf("%d %d", &m, &n);
	m < n ? i2 = m : i2 = n; //����С
	for (i = 2; i <= i2; i++) {
		if (m % i == 0 && n % i == 0)
			e1 = i; //���һ���϶������Լ��
	}
	if (e1 == 0)
		printf("û�����Լ��\n");
	else
		printf("���Լ��Ϊ%d\n", e1);
//�ɰٶȿ�֪���������˻��������Լ������С�������˻�(���ˣ������
	if (e1 == 0)
		printf("û����С������\n");
	else {
		printf("��С������Ϊ%d\n", n * m / e1);
	}
}