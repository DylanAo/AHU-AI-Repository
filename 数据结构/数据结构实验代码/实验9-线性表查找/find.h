#ifndef find__h__
#define find__h__
#include <stdio.h>
typedef struct {
	int *key;
	int length;
}Sqlist;
//�������Ա�
void create_sqlist(Sqlist& L, int* data);
//˳�����
int sequential_search(Sqlist L, int tag);
//�۰����
int binary_search(Sqlist L, int tag);
#endif // !find__h__
