#include <stdio.h>
#include <math.h>

//By ChenAO 2021.10.27
int main() {
	int m, n, my, ny, mi, ni, i;
	scanf("%d %d", &m, &n);
//Լ���������Լ��Ҳ���󣬵�����������Ұ������Ҳ���������ĸ�ģ�
//���ʱ���Ҫ�õ���͵͵�����������
//�����˰�
//���жϴ�ʱ�м���Լ��
	for (i = 1, mi = 0; i <= m - 1; i++) { //mi�����м���Լ��
		if (m % i != 0)
			continue;
		else {
			mi++;
		}
	}
//�����ÿ�ƽ���Ż��ˣ��պϿ��ɣ��������������︳ֵ mi-1
	int m1[mi];
	for (i = 1, mi = 0; i <= m - 1; i++) {
		if (m % i != 0)
			continue;
		else {
			m1[mi] = i;
			mi++;
		}
	}
//����ճ���ĳ�n��
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
