/***Hanoi������***/

#include"3.10.h"

int main() {
	int n;
	char a, b, c;
	a = '1';
	b = '2';
	c = '3';
	cout << "�������ʼ��һ�������ϵ�Բ�̸�����" << endl;
	cin >> n;
	cout << "����һ�������ϵ�Բ��ȫ���ƶ��������������ϵĹ���Ϊ��" << endl;
	Hanoi(n, a, b, c);
	return 0;
}
