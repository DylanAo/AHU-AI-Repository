/***��ջʵ�����Ƶ�ת��***/

#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2

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
Status Push(LinkStack &S, int e) {
	LinkStack p;
	p = new SNode;
	if (!p) {
		return OVERFLOW;
	}
	p->data = e;
	p->next = S;
	S = p;
	return OK;
}
Status Pop(LinkStack &S, int &e) {
	LinkStack p;
	if (!S)
		return ERROR;
	e = S->data;
	p = S;
	S = S->next;
	delete p;
	return OK;
}
//�㷨3.20�����Ƶ�ת��(��ջʵ��)
void conversion(int N) {//��������һ���Ǹ�ʮ����������ӡ��������ֵ�İ˽�����
	int e;
	LinkStack S;
	InitStack(S); //��ʼ����ջS
	while (N) //��N����ʱ,ѭ��
	{
		Push(S, N % 8); //��N��8����õ��İ˽�����ѹ��ջS
		N = N / 8; //N����ΪN��8����
	}
	while (!StackEmpty(S)) //��ջS�ǿ�ʱ��ѭ��
	{
		Pop(S, e); //����ջ��Ԫ��e
		cout << e; //���e
	}
}
int main() {//�������������һ���Ǹ�ʮ����������ӡ��������ֵ�İ˽�����
	int n, e;
	cout << "����һ���Ǹ�ʮ������:" << endl;
	cin >> n;

	conversion(n);
	return 0;
}