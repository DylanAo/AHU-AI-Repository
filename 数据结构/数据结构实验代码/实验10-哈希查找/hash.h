#ifndef hash__h__
#define hash__h__
#define Hash_Length 10
#include <stdio.h>
typedef struct h {
	int key;
	struct h* next;
}node,*hash;
//����ɢ�б�
int create_hash(hash& H);
//��������
int in_hash(hash& H, int e);
//��ϣ�����
int search_hash(hash& H, int e);
//��ӡ��һ������
void print_hash(hash H, int e);
#endif // !hash__h__