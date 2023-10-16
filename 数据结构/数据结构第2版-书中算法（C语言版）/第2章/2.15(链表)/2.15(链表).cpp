#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#define ERROR 0

typedef struct LNode {
	int data; //����������
	struct LNode *next; //����ָ����
} LNode, *List; //LinkListΪָ��ṹ��LNode��ָ������

int n, m;
char st = 'A';

void InitList(List &L) //��������
{
	L = new LNode;
	L->next = NULL;
}

void ListInput(List &L, int n) //�������ݵ�����
{
	int i;
	List p, r;
	r = L;
	char filename[20] = { 0 };
	cout << "������˳���L" << st << "�������ļ����ƣ��ļ���+��.txt������List" << st << ".txt����" << endl;
	++st;
	gets(filename);
	fstream file;
	file.open(filename);
	if (!file) {
		cout << "δ�ҵ�����ļ����޷��򿪣�" << endl;
		exit(ERROR);
	}
	while (!file.eof()) {
		p = new LNode;
		file >> p->data;
		p->next = NULL;
		r->next = p;
		r = p;
		n++;
	}
	file.close();
}

bool LocateElem(List L, int e) //�ж�List����û��e���Ԫ��
{
	List p;
	p = L->next;
	while (p != NULL) {
		if (p->data == e)
			return true;
		p = p->next;
	}
	return false;
}

void ListInsert(List &L, int e) //��e���뵽List��
{
	List p;
	p = new LNode;
	p->data = e;
	p->next = L->next;
	L->next = p;
}

void ListOutput(List L) //���List
{
	List p;
	p = L->next;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void unionList(List &LA, List LB) //�㷨2.15 ���Ա�ĺϲ�������
{
	//�����������Ա�LB�е�����LA�е�����Ԫ�ز��뵽LA��
	int e;
	List p;
	p = LB->next;
	while (p != NULL) {
		e = p->data;
		if (!LocateElem(LA, e)) //LA�в����ں�e��ͬ������Ԫ�أ������֮
			ListInsert(LA, e);
		p = p->next;
	}
} //unionList

int main() {
	List LA, LB;

	InitList(LA);
	
	InitList(LB);
	
	ListInput(LA, n);
	ListInput(LB, m);

	unionList(LA, LB);

	cout << "LA��LB�ϲ���ļ���Ϊ��\n";
	ListOutput(LA);
	return 0;
}