#include<iostream>
#include<fstream>
using namespace std;
#define MAXSIZE 100
#define ERROR 0

typedef struct //����˳���
{
	int *elem;
	int length;
} SqList;
int num_a = 0, num_b = 0;
char st = 'A';

void InitList_Sq(SqList &L, int n) //����˳���
{
	L.elem = new int[MAXSIZE];
	if (!L.elem)
		exit(0);
	L.length = 0;
}

void input(SqList &L, int n) //������˳���L����������
{
	int i = 0;
	char filename[20] = { 0 };
	cout << "������ǵݼ����Ա�" << st << "�������ļ����ƣ��ļ���+��.txt������List" << st << ".txt����" << endl;
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

void output(SqList L) //�������˳������ÿ��Ԫ��
{
	int i;
	for (i = 0; i < L.length; i++) {
		if (i)
			cout << ",";
		cout << L.elem[i];
	}
}

void MergeList_Sq(SqList LA, SqList LB, SqList &LC) //�㷨2.16 ˳�������ĺϲ�
{
	//��֪˳�������LA��LB��Ԫ�ذ�ֵ�ǵݼ�����
	//�鲢LA��LB�õ��µ�˳�������LC��LC��Ԫ��Ҳ��ֵ�ǵݼ�����
	int *pa, *pb, *pc, *pa_last, *pb_last;
	pa = LA.elem;
	pb = LB.elem; //ָ��pa��pb�ĳ�ֵ�ֱ�ָ��������ĵ�һ��Ԫ��
	LC.length = LA.length + LB.length; //�±���Ϊ���ϲ�����ĳ���֮��
	LC.elem = new int[LC.length]; //Ϊ�ϲ�����±����һ������ռ�
	pc = LC.elem; //ָ��pcָ���±�ĵ�һ��Ԫ��
	pa_last = LA.elem + LA.length - 1; //ָ��pa_lastָ��LA������һ��Ԫ��
	pb_last = LB.elem + LB.length - 1; //ָ��pb_lastָ��LB������һ��Ԫ��
	while (pa <= pa_last && pb <= pb_last) //�������ǿ�
	{
		if (*pa <= *pb) //���Ρ�ժȡ��������ֵ��С�Ľ����뵽LC������
			*pc++ = *pa++;
		else
			*pc++ = *pb++;
	}
	while (pa <= pa_last) //LB�ѵ����β�����ν�LA��ʣ��Ԫ�ز���LC������
		*pc++ = *pa++;
	while (pb <= pb_last) //LA�ѵ����β�����ν�LB��ʣ��Ԫ�ز���LC������
		*pc++ = *pb++;
} //MergeList_List

int main() {
	SqList La, Lb, Lc;
	
	InitList_Sq(La, num_a); //La��Ĵ���
	input(La, num_a); //������˳���La����������

	InitList_Sq(Lb, num_b); //Lb��Ĵ���	
	input(Lb, num_b); //������˳���La����������

	MergeList_Sq(La, Lb, Lc); //��˳���La��Lb���кϲ�

	cout << "�ǵݼ����Ա�A��B�ϲ���ķǵݼ����Ա�CΪ��\n"; //����ϲ��������˳���Lc
	output(Lc);
	cout << endl;
	return 0;
}