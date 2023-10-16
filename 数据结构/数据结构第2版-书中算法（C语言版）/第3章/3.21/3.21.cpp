/***��ջʵ������ƥ��***/

#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef char SElemType;
typedef int Status;
typedef struct SNode {
	int data;
	struct SNode *next;
} SNode, *LinkStack;

Status InitStack(LinkStack &S) {
	S = NULL;
	return OK;
}
bool StackEmpty(LinkStack S) {
	if (!S)
		return true;
	return false;
}
Status Push(LinkStack &S, SElemType e) {
	SNode *p = new SNode;
	if (!p) {
		return OVERFLOW;
	}
	p->data = e;
	p->next = S;
	S = p;
	return OK;
}
Status Pop(LinkStack &S, SElemType &e) {
	SNode *p;
	if (!S)
		return ERROR;
	e = S->data;
	p = S;
	S = S->next;
	delete p;
	return OK;
}
Status GetTop(LinkStack &S) {
	if (!S)
		return ERROR;
	return S->data;
}

//�㷨3.21�����ŵ�ƥ��
Status Matching() {//������ʽ�����������Ƿ���ȷƥ�䣬���ƥ�䣬�򷵻�true�����򷵻�false
	//���ʽ�ԡ�#������
	char ch;
	SElemType x;
	LinkStack S;
	InitStack(S); //��ʼ����ջ
	int flag = 1; //���ƥ�����Կ���ѭ�������ؽ��
	cin >> ch; //�����һ���ַ�
	while (ch != '#' && flag) //������ʽ�ԡ�#����β
	{
		switch (ch) {
		case '[' :
		case '(': //���������ţ�����ѹ��ջ
			Push(S, ch);
			break;
		case ')': //���ǡ�)��������ݵ�ǰջ��Ԫ�ص�ֵ���������
			if (!StackEmpty(S) && GetTop(S) == '(')
				Pop(S, x); //��ջ�ǿ���ջ��Ԫ���ǡ�(��������ȷƥ��
			else
				flag = 0; //��ջ�ջ�ջ��Ԫ�ز��ǡ�(���������ʧ��
			break;
		case ']': //���ǡ�]��������ݵ�ǰջ��Ԫ�ص�ֵ���������
			if (!StackEmpty(S) && GetTop(S) == '[')
				Pop(S, x); //��ջ�ǿ���ջ��Ԫ���ǡ�[��������ȷƥ��
			else
				flag = 0; //��ջ�ջ�ջ��Ԫ�ز��ǡ�[���������ƥ��
			break;
		} //switch
		cin >> ch; //����������һ���ַ�
	} //while
	if (StackEmpty(S) && flag)
		return true; //ƥ��ɹ�
	else
		return false; //ƥ��ʧ��
}
int main() {
	LinkStack S;
	cout << "�������ƥ��ı��ʽ���ԡ�#��������" << endl;
	int flag = (int) Matching();
	if (flag)
		cout << "����ƥ��ɹ���" << endl;
	else
		cout << "����ƥ��ʧ�ܣ�" << endl;
	return 0;
}
