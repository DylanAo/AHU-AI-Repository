#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
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
typedef struct DuLNode {
	Book data; //������
	struct DuLNode *prior; //ֱ��ǰ��
	struct DuLNode *next; //ֱ�Ӻ��
} DuLNode, *DuLinkList;

string head_1, head_2, head_3;
int length;

Status InitDuList_L(DuLinkList &L) {
	//����һ���յ�˫������L
	L = new DuLNode; //�����½����Ϊͷ��㣬��ͷָ��Lָ��ͷ���
	L->next = NULL; //ͷ����ָ�����ÿ�
	L->prior = NULL;
	return OK;
}

DuLNode *GetElemP_DuL(DuLinkList L, int i) {
	//�ڴ�ͷ����˫������L�в��ҵ�i��Ԫ�أ����ؽ��ĵ�ַ
	int j;
	DuLinkList p;
	p = L->next;
	j = 1; //��ʼ����pָ���һ����㣬jΪ������
	while (j < i && p) { //˳�������ɨ�裬ֱ��pָ���i��Ԫ�ػ�pΪ��
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return NULL; //��i��Ԫ�ز�����
	return p;
} //GetElemP_DuL

Status ListInsert_DuL(DuLinkList &L, int i, Book e) { //�㷨2.13 ˫������Ĳ���
	//�ڴ�ͷ����˫������L�е�i��λ��֮ǰ����Ԫ��e��i�ĺϷ�ֵΪ1<=i<=��+1
	DuLinkList s, p;
	if (!(p = GetElemP_DuL(L, i))) //��L��ȷ����i��Ԫ�ص�λ��ָ��p
		return ERROR; //pΪNULLʱ����i��Ԫ�ز�����
	if (i == 1) {//��˫������ĵ�һ��Ԫ���ϲ���
		s = new DuLNode; //�����½��s
		s->data = e; //�����s������Ϊe
		DuLinkList p = L->next;
		L->next = s;
		s->prior = L;
		s->next = p;//�����*s����L��
		p->prior = s;
		++length;
	} else if (i == length) {//��˫����������һ��Ԫ���ϲ���
		s = new DuLNode; //�����½��s
		s->data = e; //�����s������Ϊe
		DuLinkList p = L;
		while (p->next)
			p = p->next;//��LinkList pָ��˫�������β
		p->next = s;
		s->prior = p;//�����*s���뵽p�ĺ��棬���뵽L��
		s->next = NULL;
		++length;
	} else {
		s = new DuLNode; //�����½��*s
		s->data = e; //�����*s��������Ϊe
		s->prior = p->prior; //�����*s����L�У��˲���Ӧͼ2.20�� 
		p->prior->next = s; //��Ӧͼ2.20��
		s->next = p; //��Ӧͼ2.20��
		p->prior = s; //��Ӧͼ2.20��
		++length;
	}
	return OK;
} //ListInsert_DuL

Status ListDelete_DuL(DuLinkList &L, int i) { //�㷨2.14 ˫�������ɾ��
	//ɾ����ͷ����˫������L�е�i��λ��֮ǰ����Ԫ��e��i�ĺϷ�ֵΪ1<=i<=��
	DuLinkList p;
	if (!(p = GetElemP_DuL(L, i))) //��L��ȷ����i��Ԫ�ص�λ��ָ��p
		return ERROR; //pΪNULLʱ����i��Ԫ�ز�����
	if (i == 1)//ɾ��˫������ĵ�һ��Ԫ��
		L = L->next;
	else if (i == length) {//ɾ��˫����������һ��Ԫ��
		p->prior->next = NULL;
		delete p;
		--length;
		return OK;
	} else {
		p->prior->next = p->next; //�޸ı�ɾ����ǰ�����ĺ��ָ�룬��Ӧͼ2.21��
		p->next->prior = p->prior; //�޸ı�ɾ���ĺ�̽���ǰ��ָ�룬��Ӧͼ2.21��
		delete p; //�ͷű�ɾ���Ŀռ� 
		--length;
		return OK;
	}
}//ListDelete_DuL

void CreateDuList_L(DuLinkList &L) {
	//��λ������n��Ԫ�ص�ֵ����������ͷ����˫������L��ͬʱ����ǰ��ָ��
	DuLinkList r, p;
	L = new DuLNode;
	L->next = NULL; //�Ƚ���һ����ͷ���Ŀ�����
	r = L;//βָ��rָ��ͷ���
	length = 0;
	fstream file;
	file.open("book.txt");
	if (!file) {
		cout << "δ�ҵ�����ļ����޷��򿪣�" << endl;
		exit(ERROR);
	}
	file >> head_1 >> head_2 >> head_3;
	while (!file.eof()) {
		p = new DuLNode; //�����½��
		file >> p->data.id >> p->data.name >> p->data.price; //����Ԫ��ֵ
		p->next = NULL;
		r->next = p; //���뵽��β
		r = p; //rָ���µ�β���
		p->prior = L->prior; //���뵽��ͷ
		L->prior = p;
		length++;
	}
	file.close();
} //CreateDuList_L

int main() {
	int a, choose;
	Book e;
	DuLinkList L, p;
	cout << "1. ����\n";
	cout << "2. ����\n";
	cout << "3. ����\n";
	cout << "4. ɾ��\n";
	cout << "5. ���\n";
	cout << "0. �˳�\n\n";

	choose = -1;
	while (choose != 0) {
		cout << "��ѡ��:";
		cin >> choose;
		switch (choose) {
		case 1: //����һ��˫������
			if (InitDuList_L(L))
				cout << "�ɹ�����˫������!\n\n";
			break;
		case 2: //ʹ�ú�巨����˫������
			CreateDuList_L(L);
			cout << "���� book.txt ��Ϣ���\n\n";
			break;
		case 3: //˫������Ĳ���
			cout << "�������������ֱ��������λ�ú���ֵ�������Ϣ�����&����&�۸�:";
			cin >> a;
			cin >> e.id >> e.name >> e.price;
			if (ListInsert_DuL(L, a, e))
				cout << "����ɹ�.\n\n";
			else
				cout << "����ʧ��!\n\n";
			break;
		case 4: //˫�������ɾ��
			cout << "��������Ҫɾ�����鼮��λ��:";
			cin >> a;
			if (ListDelete_DuL(L, a))
				cout << "ɾ���ɹ�!\n\n";
			else
				cout << "ɾ��ʧ��!\n\n";
			break;
		case 5: //˫����������
			cout << "��ǰͼ��ϵͳ��Ϣ����:\n";
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