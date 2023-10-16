#include<iostream>
#include<fstream>
using namespace std;
#define ERROR 0

typedef struct LNode //���嵥����
{
	int data;
	struct LNode *next;
} LNode, *LinkList;

int num_a, num_b;
char st = 'A';

void InitList_L(LinkList &L) //����������
{
	L = new LNode;
	L->next = NULL;
}

void input(LinkList &L, int n) //������������L����������
{
	int i;
	LNode *p, *r;
	r = L;
	char filename[20] = { 0 };
	cout << "������ǵݼ�������" << st << "�������ļ����ƣ��ļ���+��.txt������List" << st << ".txt����" << endl;
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

void output(LinkList L) //����������������ÿ��Ԫ��
{
	int i = 0;
	LNode *p;
	p = L->next;
	while (p) {
		if (i)
			cout << ",";
		cout << p->data;
		p = p->next;
		i = 1;
	}
}

void MergeList_L(LinkList &LA, LinkList &LB, LinkList &LC) //�㷨2.17 ��ʽ�����ĺϲ�
{
	//��֪������LA��LB��Ԫ�ذ�ֵ�ǵݼ�����
	//�鲢LA��LB�õ��µĵ�����LC��LC��Ԫ��Ҳ��ֵ�ǵݼ�����
	LinkList pa, pb, pc;
	pa = LA->next;
	pb = LB->next; //pa��pb�ĳ�ֵ�ֱ�ָ��������ĵ�һ�����
	LC = LA; //��LA��ͷ�����ΪLC��ͷ���
	pc = LC; //pc�ĳ�ֵָ��LC��ͷ���
	while (pa && pb) //�������ǿ�
	{
		if (pa->data <= pb->data) //����"ժȡ"������ֵ��С�Ľ����뵽LC������
		{
			pc->next = pa; //��pa��ָ������ӵ�pc��ָ���֮��
			pc = pa;
			pa = pa->next;
		} else {
			pc->next = pb; //��pb��ָ������ӵ�pc��ָ���֮��
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb; //����ǿձ��ʣ���
	delete LB; //�ͷ�LB��ͷ���
} //MergeList_L()

int main() {
	LinkList La, Lb, Lc;

	InitList_L(La); //La��Ĵ���
	input(La, num_a); //������������La����������

	InitList_L(Lb); //Lb��Ĵ���	
	input(Lb, num_b); //������������La����������

	InitList_L(Lc);
	MergeList_L(La, Lb, Lc); //��������La��Lb���кϲ�


	cout << "�ǵݼ�������A��B�ϲ���ķǵݼ�������CΪ��\n"; //����ϲ���ĵ�����Lc
	output(Lc);
	cout << endl;
	return 0;
}