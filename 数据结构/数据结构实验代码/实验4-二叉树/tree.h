#ifndef tree__h__
#define tree__h__
#include <stdio.h>
typedef struct tree {
	char data;
	struct tree* lchild;
	struct tree* rchild;
}Binode,*Bitree;
//ǰ��������������
Bitree create_tree(char* f, char* m, int f1, int f2, int m1, int m2);
//ǰ�����
void front_print(Bitree T);
//�������
void middle_print(Bitree T);
//�������
void last_print(Bitree T);
//�ڵ���
int NodeNum(Bitree T);
//�������
int deep(Bitree T);
//Ҷ����
int leaf(Bitree T);
//��Ϊ1����
int deep_1(Bitree T);
#endif // !tree__h__

