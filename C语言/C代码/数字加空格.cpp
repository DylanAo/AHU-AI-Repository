#include <stdio.h>//ͷ�ļ� 

int main() { //������
	void convert(int n);//��������
	int number;//�������ͱ���
	printf("����һ��������");//��ʾ���
	scanf("%d", &number); //��������
	printf("����ṹ��");//��ʾ���
	if (number < 0) {
		putchar('-'); //�����һ��-��
		putchar(' '); //�����һ���ո�
		number = -number;
	}
	convert(number);//�����Զ����ת������
	printf("\n");//����
	return 0;//����������ֵΪ0
}

void convert(int n) { //�Զ����ת������
	int i;//�������ͱ���
	if ((i = n / 10) != 0) { //�ݹ�
		convert(i);
	}
	putchar(n % 10 + '0');
	putchar(32);
}