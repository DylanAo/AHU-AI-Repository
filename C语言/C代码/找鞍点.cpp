#include <stdio.h>

//��������������
int main() {
	int i, i2, i3, i4, ad;
	int a[3][2];
	//��������
	for (i = 0; i < 3; i++) {
		for (i2 = 0; i2 < 2; i2++) {
			scanf ("%d", &a[i][i2]);
		}
	}
	//չʾ����
	for (i = 0; i < 3; i++) {
		for (i2 = 0; i2 < 2; i2++) {
			printf ("%-5d ", a[i][i2]);
		}
		printf("\n");
	}
	printf("\n");
	//�жϰ���
	for (i = 0; i < 3; i++) {
		for (i2 = 0; i2 < 2; i2++) {
			ad = a[i][i2];
			for (i4 = 0; i4 < 2; i4++) { //�����
				if (i4 == i2) { //���Լ��۳�
					continue;
				} else {
					if (ad <= a[i][i4])//���Ⱥ�Ϊ��������
						break;
				}
			}
			for (i3 = 0; i3 < 3; i3++) { //����С
				if (i3 == i) {//���Լ��۳�
					continue;
				} else {
					if (ad >= a[i3][i2])//�����ں���Ϊ��������
						break;
				}
			}
			if ((i4 == 2 ) && (i3 == 3))
				printf("������%d\n", ad);
		}
	}
}