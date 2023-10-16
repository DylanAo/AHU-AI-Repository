#include<iostream>
#include<fstream>
using namespace std;
#define MAXSIZE 100
#define ERROR 0
typedef struct { //����˳���
	int *elem;
	int length;
} List;
int n, m;
char st = 'A';

void InitList(List &L) //����˳���
{
	L.elem = new int[MAXSIZE];
	L.length = 0;
}

void ListInput(List &L, int n) //˳������ݵ�����
{
	int i = 0;
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
		file >> L.elem[i];
		i++;
	}
	L.length = i;

}

int ListLength(List L) //��˳���ĳ���
{
	return L.length;
}

void GetElem(List L, int i, int &e) //��˳���ĵ�i��Ԫ�أ�����e����
{
	e = L.elem[i - 1];
}

bool LocateElem(List L, int e) //�ж�List����û��e���Ԫ��
{
	int i;
	for (i = 0; i < L.length; i++)
		if (e == L.elem[i])
			return true;
	return false;
}

void ListInsert(List &L, int e) //��e���뵽List�����
{
	L.elem[L.length] = e;
	L.length++;
}

void ListOutput(List L) //���List
{
	int i;
	for (i = 0; i < L.length; i++)
		cout << L.elem[i] << " ";
	cout << endl;
}

void unionList(List &LA, List LB) //�㷨2.14 ���Ա�ĺϲ���˳���
{
	//�����������Ա�LB�е�����LA�е�����Ԫ�ز��뵽LA��
	int LA_len, LB_len, i, e;
	LA_len = ListLength(LA);
	LB_len = ListLength(LB); //�����Ա�ĳ���
	for (i = 1; i <= LB_len; i++) {
		GetElem(LB, i, e); //ȡLB�е�i������Ԫ�ظ���e
		if (!LocateElem(LA, e)) //LA�в����ں�e��ͬ������Ԫ�أ������֮
			ListInsert(LA, e);
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