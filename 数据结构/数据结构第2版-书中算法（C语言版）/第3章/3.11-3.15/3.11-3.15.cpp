/***ѭ�����л�������***/

#include<iostream>
#include<fstream>
using namespace std;

#define MAXQSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef char QElemType;
typedef char SElemType;
typedef int Status;

typedef struct {
	QElemType *base;//��ʼ��ʱ��̬����洢�ռ�
	int front;//ͷָ��
	int rear;//βָ��
} SqQueue;

//�㷨3.11��ѭ�����еĳ�ʼ��
Status InitQueue(SqQueue &Q) {//����һ���ն���Q
	Q.base = new QElemType[MAXQSIZE]; //Ϊ���з���һ���������ΪMAXSIZE������ռ�
	if (!Q.base)
		exit(OVERFLOW); //�洢����ʧ��
	Q.front = Q.rear = 0; //ͷָ���βָ����Ϊ�㣬����Ϊ��
	return OK;
}

//�㷨3.12����ѭ�����еĳ���
int QueueLength(SqQueue Q) {//����Q��Ԫ�ظ����������еĳ���
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

//�㷨3.13��ѭ�����е����
Status EnQueue(SqQueue &Q, QElemType e) {//����Ԫ��eΪQ���µĶ�βԪ��
	if ((Q.rear + 1) % MAXQSIZE == Q.front) //βָ����ѭ�������ϼ�1�����ͷָ�룬��������
		return ERROR;
	Q.base[Q.rear] = e; //��Ԫ�ز����β
	Q.rear = (Q.rear + 1) % MAXQSIZE; //��βָ���1
	return OK;
}

//�㷨3.14��ѭ�����еĳ���
Status DeQueue(SqQueue &Q, QElemType &e) {//ɾ��Q�Ķ�ͷԪ�أ���e������ֵ
	if (Q.front == Q.rear)
		return ERROR; //�ӿ�
	e = Q.base[Q.front]; //�����ͷԪ��
	Q.front = (Q.front + 1) % MAXQSIZE; //��ͷָ���1
	return OK;
}

//�㷨3.15��ȡѭ�����еĶ�ͷԪ��
SElemType GetHead(SqQueue Q) {//����Q�Ķ�ͷԪ�أ����޸Ķ�ͷָ��
	if (Q.front != Q.rear) //���зǿ�
		return Q.base[Q.front]; //���ض�ͷԪ�ص�ֵ����ͷָ�벻��
}

int main() {
	int choose, flag = 0;
	SqQueue Q;
	QElemType e, j;
	cout << "1.��ʼ��\n";
	cout << "2.���\n";
	cout << "3.����ͷԪ��\n";
	cout << "4.����\n";
	cout << "0.�˳�\n\n";

	choose = -1;
	while (choose != 0) {
		cout << "��ѡ��:";
		cin >> choose;
		switch (choose) {
		case 1://�㷨3.16�����ӵĳ�ʼ��
			if (InitQueue(Q)) {
				flag = 1;
				cout << "�ɹ��Զ��н��г�ʼ��\n\n";
			} else
				cout << "��ʼ������ʧ��\n\n";
			break;
		case 2: {//�㷨3.17�����ӵ����
			fstream file;
			file.open("QNode.txt");
			if (!file) {
				cout << "����δ�ҵ��ļ���\n\n" << endl;
				exit(ERROR);
			}
			if (flag) {
				flag = 1;
				cout << "��ӵ�Ԫ������Ϊ��\n";
				while (!file.eof()) {
					file >> j;
					if (file.fail())
						break;
					else {
						EnQueue(Q, j);
						cout << j << "  ";
					}
				}
				cout << endl << endl;
			} else
				cout << "����δ������������ѡ��\n\n";
			file.close();
		}
			break;
		case 3://�㷨3.19��ȡ���ӵĶ�ͷԪ��
			if (flag != -1 && flag != 0)
				cout << "��ͷԪ��Ϊ��\n" << GetHead(Q) << endl << endl;
			else
				cout << "��������Ԫ�أ�������ѡ��\n" << endl;
			break;
		case 4://�㷨3.18�����ӵĳ���
			cout << "���ε����Ķ�ͷԪ��Ϊ:\n";
			while (DeQueue(Q, e)) {
				flag = -1;
				cout << e << "  ";
			}
			cout << endl << endl;
			break;
		}
	}
	return 0;
}