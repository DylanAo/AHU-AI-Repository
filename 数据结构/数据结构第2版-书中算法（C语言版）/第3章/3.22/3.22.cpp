#include"3.22.h"

int menu() {
	int c;
	cout << "0-9���ڵĶ���ʽ����" << endl;
	cout << "1.����" << endl;
	cout << "0.�˳�\n" << endl;
	cout << "ѡ��";
	cin >> c;
	return c;
}

void main() {
	while (1) {
		switch (menu()) {
		case 1: {
			cout << "������Ҫ����ı��ʽ���������ͽ������0-9�ķ�Χ�ڣ���#��������" << endl;
			char res = EvaluateExpression();//�㷨3.22�����ʽ��ֵ
			cout << "������Ϊ" << res - 48 << endl << endl;
		}
			break;
		case 0:
			cout << "�˳��ɹ�\n" << endl;
			exit(0);
		default:
			break;
		}
	}
}