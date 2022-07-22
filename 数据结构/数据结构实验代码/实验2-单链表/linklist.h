#ifndef linklist_h_
#define linklist_h_
#include <stdio.h>

typedef struct link {
	int data;
	struct link* next;
}*Linklist,LNode;
//��������
int create_linklist(Linklist& L);
//�ѵ�i���ŵ�e��
int loacted_linklist(Linklist L, int i, int& e);
//����ֵΪe�����ص�ַ
LNode* find_linklist(Linklist L, int e);
//��iλ�ò���ֵΪe
int insert_linklist(Linklist& L, int i, int e);
//ɾ����i��
int deldte_linklist(Linklist& L, int i);
//ͷ�巨
int head_linklist(Linklist& L, int* a, int n);
//β�巨
int bottom_linklist(Linklist& L, int* a, int n);
//���
int print_linklist(Linklist L);
#endif 