#include <stdio.h>

int main() {
	int a[11] = {1};
	int b[11] = {1};
	int i, j, sum = 0;
	for (j = 1; j <= 10; j++) { //���Ƶڼ���
		if (j % 2 == 0)//�ж���ż��
			goto os;
		else
			goto js;
js://������
		for (i = 0;; i++) { //����ÿ���������
			if (i == 0) //�ж��Ƿ��һ��
				printf("%-4d ", 1);//ϸ�ڣ����Ƹ�ʽ���ÿ�
			if (j == 1) {//�ж��Ƿ��һ��
				printf("\n");
				break;
			}
			sum = a[i] + a[i + 1];
			printf ("%-4d ", sum);//ϸ�ڣ����Ƹ�ʽ���ÿ�
			b[i + 1] = sum;
			if (sum == 1) {//�ж��ܷ����һ��
				printf("\n");
				break;
			}
		}
		continue;//����Ҫ�ǲ��������ᵼ��ż�����������
os://ż����
		for (i = 0;; i++) { //����ÿ���������
			if (i == 0) //�ж��Ƿ��һ��
				printf("%-4d ", 1);//ϸ�ڣ����Ƹ�ʽ���ÿ�
			sum = b[i] + b[i + 1];
			printf ("%-4d ", sum);//ϸ�ڣ����Ƹ�ʽ���ÿ�
			a[i + 1] = sum;
			if (sum == 1) {//�ж��Ƿ����һ��
				printf("\n");
				break;
			}
		}
	}
	return 0;
}