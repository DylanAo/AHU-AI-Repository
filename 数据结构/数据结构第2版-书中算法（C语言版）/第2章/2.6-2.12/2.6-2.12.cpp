#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status; //Status �Ǻ�������ֵ���ͣ���ֵ�Ǻ������״̬���롣
typedef int ElemType; //ElemType Ϊ�ɶ�����������ͣ�����Ϊint����

struct Book {
	string id;//ISBN
	string name;//����
	double price;//����
};
typedef struct LNode {
	Book data; //����������
	struct LNode *next; //����ָ����
} LNode, *LinkList; //LinkListΪָ��ṹ��LNode��ָ������

string head_1, head_2, head_3;
int length;

Status InitList_L(LinkList &L) { //�㷨2.6 ������ĳ�ʼ��
	//����һ���յĵ�����L
	L = new LNode; //�����½����Ϊͷ��㣬��ͷָ��Lָ��ͷ���
	L->next = NULL; //ͷ����ָ�����ÿ�
	return OK;
}

Status GetElem_L(LinkList L, int i, Book &e) { //�㷨2.7 �������ȡֵ
	//�ڴ�ͷ���ĵ�����L�в��ҵ�i��Ԫ��
	//��e����L�е�i������Ԫ�ص�ֵ
	int j;
	LinkList p;
	p = L->next;
	j = 1; //��ʼ����pָ���һ����㣬jΪ������
	while (j < i && p) { //˳�������ɨ�裬ֱ��pָ���i��Ԫ�ػ�pΪ��
		p = p->next; //pָ����һ�����
		++j; //������j��Ӧ��1
	}
	if (!p || j > i)
		return ERROR; //iֵ���Ϸ�i��n��i<=0
	e = p->data; //ȡ��i������������
	return OK;
} //GetElem_L

LNode *LocateElem_L(LinkList L, int e) { //�㷨2.8 ��ֵ����
	//�ڴ�ͷ���ĵ�����L�в���ֵΪe��Ԫ��
	LinkList p;
	p = L->next;
	while (p && p->data.price != e)//˳�������ɨ�裬ֱ��pΪ�ջ�p��ָ�������������e
		p = p->next; //pָ����һ�����
	return p; //���ҳɹ�����ֵΪe�Ľ���ַp������ʧ��pΪNULL 
} //LocateElem_L

Status ListInsert_L(LinkList &L, int i, Book &e) { //�㷨2.9 ������Ĳ���
	//�ڴ�ͷ���ĵ�����L�е�i��λ�ò���ֵΪe���½��
	int j;
	LinkList p, s;
	p = L;
	j = 0;
	while (p && j < i - 1) {
		p = p->next;
		++j;
	}//���ҵ�i?1����㣬pָ��ý��
	if (!p || j > i - 1)
		return ERROR; //i��n+1����i��1
	s = new LNode; //�����½��*s 
	s->data = e; //�����*s����������Ϊe
	s->next = p->next; //�����*s��ָ����ָ����ai
	p->next = s; //�����*p��ָ����ָ����*s
	++length;
	return OK;
} //ListInsert_L

Status ListDelete_L(LinkList &L, int i) { //�㷨2.9 �������ɾ��
	//�ڴ�ͷ���ĵ�����L�У�ɾ����i��λ��	
	LinkList p, q;
	int j;
	p = L;
	j = 0;
	while ((p->next) && (j < i - 1)) //���ҵ�i?1����㣬pָ��ý��
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || (j > i - 1))
		return ERROR; //��i>n��i<1ʱ��ɾ��λ�ò����� 
	q = p->next; //��ʱ���汻ɾ���ĵ�ַ�Ա��ͷ� 
	p->next = q->next; //�ı�ɾ�����ǰ������ָ���� 
	delete q; //�ͷ�ɾ�����Ŀռ� 
	--length;
	return OK;
} //ListDelete_L

void CreateList_H(LinkList &L, int n) { //�㷨2.11 ǰ�巨����������
	//��λ������n��Ԫ�ص�ֵ��������ͷ���ĵ�����L
	LinkList p;
	L = new LNode;
	L->next = NULL; //�Ƚ���һ����ͷ���Ŀ�����
	length = 0;
	fstream file;
	file.open("book.txt");
	if (!file) {
		cout << "δ�ҵ�����ļ����޷��򿪣�" << endl;
		exit(ERROR);
	}
	file >> head_1 >> head_2 >> head_3;
	while (!file.eof()) {
		p = new LNode; //�����½��*p
		file >> p->data.id >> p->data.name >> p->data.price; //����Ԫ��ֵ�����½��*p��������
		p->next = L->next;
		L->next = p; //���½��*p���뵽ͷ���֮��
		length++;//ͬʱ�������Ƚ���ͳ��
	}
	file.close();
} //CreateList_F

void CreateList_R(LinkList &L, int n) { //�㷨2.12 ��巨����������
	//��λ������n��Ԫ�ص�ֵ����������ͷ���ĵ�����L 
	LinkList p, r;
	L = new LNode;
	L->next = NULL; //�Ƚ���һ����ͷ���Ŀ�����
	r = L; //βָ��rָ��ͷ���
	length = 0;
	fstream file; //���ļ����ж�д����
	file.open("book.txt");
	if (!file) {
		cout << "δ�ҵ�����ļ����޷��򿪣�" << endl;
		exit(ERROR);
	}
	file >> head_1 >> head_2 >> head_3;
	while (!file.eof()) { //���ļ��е���Ϣ���ú�巨���뵽������
		p = new LNode;//�����½��
		file >> p->data.id >> p->data.name >> p->data.price;//����Ԫ��ֵ�����½��*p��������
		p->next = NULL;
		r->next = p;//���½��*p����β���*r֮�� 		
		r = p;//rָ���µ�β���*p
		length++; //ͬʱ�������Ƚ���ͳ��
	}
	file.close();
} //CreateList_L

int main() {
	int a, n, choose;
	double price;
	Book e;
	LinkList L, p;
	cout << "1. ����\n";
	cout << "2. ����\n";
	cout << "3. ȡֵ\n";
	cout << "4. ����\n";
	cout << "5. ����\n";
	cout << "6. ɾ��\n";
	cout << "7. ���\n";
	cout << "0. �˳�\n\n";

	choose = -1;
	while (choose != 0) {
		cout << "��ѡ��:";
		cin >> choose;
		switch (choose) {
		case 1: //����һ��������
			if (InitList_L(L))
				cout << "�ɹ���������!\n\n";
			break;
		case 2: //ʹ�ú�巨����������
			CreateList_R(L, length);
			cout << "���� book.txt ��Ϣ���\n\n";
			break;
		case 3: //������İ����ȡֵ
			cout << "������һ��λ������ȡֵ:";
			cin >> a;
			if (GetElem_L(L, a, e)) {
				cout << "���ҳɹ�\n";
				cout << "��" << a << "��ͼ�����Ϣ�ǣ�\n";
				cout << left << setw(15) << e.id << "\t" << left << setw(50)
						<< e.name << "\t" << left << setw(5) << e.price << endl
						<< endl;
			} else
				cout << "����ʧ��\n\n";
			break;
		case 4: //������İ�ֵ����
			cout << "��������Ҫ���Ҽ۸�:";
			cin >> price;
			if (LocateElem_L(L, price) != NULL) {
				cout << "���ҳɹ�\n";
				cout << "�ü۸��Ӧ������Ϊ��" << LocateElem_L(L, price)->data.name
						<< endl << endl;
			} else
				cout << "����ʧ��! ����" << price << " û���ҵ�\n\n";
			break;
		case 5: //������Ĳ���
			cout << "����������λ�ú������Ϣ����������� ���� �۸��ÿո������:";
			cin >> a;
			cin >> e.id >> e.name >> e.price;
			if (ListInsert_L(L, a, e))
				cout << "����ɹ�.\n\n";
			else
				cout << "����ʧ��!\n\n";
			break;
		case 6: //�������ɾ��
			cout << "��������Ҫɾ�����鼮��λ��:";
			cin >> a;
			if (ListDelete_L(L, a))
				cout << "ɾ���ɹ�!\n\n";
			else
				cout << "ɾ��ʧ��!\n\n";
			break;
		case 7: //����������
			cout << "��ǰͼ��ϵͳ��Ϣ����������:\n";
			p = L->next;
			while (p) {
				cout << left << setw(15) << p->data.id << "\t" << left << setw(
						50) << p->data.name << "\t" << left << setw(5)
						<< p->data.price << endl;
				p = p->next;
			}
			cout << endl;
			break;
		}
	}
	return 0;
}
