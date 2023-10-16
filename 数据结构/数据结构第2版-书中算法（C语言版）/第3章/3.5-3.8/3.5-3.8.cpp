/***��ջ��ʵ��***/
#include<iostream>
#include<fstream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef char SElemType;

typedef struct StackNode {
	SElemType data;
	struct StackNode *next;
} StackNode, *LinkStack;

//�㷨3.5����ջ�ĳ�ʼ��
Status InitStack(LinkStack &S) { // ����һ����ջ S��ջ��ָ���ÿ�
	S = NULL;
	return OK;
}

//�㷨3.6����ջ����ջ
Status Push(LinkStack &S, SElemType e) {//��ջ������Ԫ��e
	LinkStack p;
	p = new StackNode; //�����½��
	p->data = e; //���½����������Ϊe
	p->next = S; //���½�����ջ��
	S = p; //�޸�ջ��ָ��Ϊp
	return OK;
}

//�㷨3.7����ջ�ĳ�ջ
Status Pop(LinkStack &S, SElemType &e) {//ɾ��S��ջ��Ԫ�أ���e������ֵ
	LinkStack p;
	if (S == NULL)
		return ERROR; //ջ��
	e = S->data; //��ջ��Ԫ�ظ���e
	p = S; //��p��ʱ����ջ��Ԫ�ؿռ䣬�Ա��ͷ�
	S = S->next; //�޸�ջ��ָ��
	delete p; //�ͷ�ԭջ��Ԫ�صĿռ�
	return OK;
}
//�㷨3.8��ȡ��ջ��ջ��Ԫ��
SElemType GetTop(LinkStack S) {//����S��ջ��Ԫ�أ����޸�ջ��ָ��
	if (S != NULL) //ջ�ǿ�
		return S->data; //����ջ��Ԫ�ص�ֵ��ջ��ָ�벻��
}

int main() {
	LinkStack s;
	int choose, flag = 0;
	SElemType j, t;
	cout << "1.��ʼ��\n";
	cout << "2.��ջ\n";
	cout << "3.��ջ��Ԫ��\n";
	cout << "4.��ջ\n";
	cout << "0.�˳�\n\n";

	choose = -1;
	while (choose != 0) {
		cout << "��ѡ��:";
		cin >> choose;
		switch (choose) {
		case 1://�㷨3.5����ջ�ĳ�ʼ��
			if (InitStack(s)) {
				flag = 1;
				cout << "�ɹ���ջ���г�ʼ��\n\n";
			} else
				cout << "��ʼ��ջʧ��\n\n";
			break;
		case 2: {//�㷨3.6����ջ����ջ
			fstream file;
			file.open("SqStack.txt");
			if (!file) {
				cout << "����δ�ҵ��ļ���\n\n" << endl;
				exit(ERROR);
			}
			if (flag) {
				flag = 1;
				cout << "��ջԪ������Ϊ��\n";
				while (!file.eof()) {
					file >> j;
					if (file.fail())
						break;
					else {
						Push(s, j);
						cout << j << "  ";
					}
				}
				cout << endl << endl;
			} else
				cout << "ջδ������������ѡ��\n\n";
			file.close();
		}
			break;
		case 3://�㷨3.8��ȡ��ջ��ջ��Ԫ��
			if (flag != -1 && flag != 0)
				cout << "ջ��Ԫ��Ϊ��\n" << GetTop(s) << endl << endl;
			else
				cout << "ջ����Ԫ�أ�������ѡ��\n" << endl;
			break;
		case 4://�㷨3.7����ջ�ĳ�ջ
			if (flag) {
				cout << "���ε�����ջ��Ԫ��Ϊ:\n";
				while (Pop(s, t))
					cout << t << "  ";
				cout << endl << endl;
			} else
				cout << "ջδ������������ѡ��\n\n";
			break;
		}
	}
	return 0;
}
