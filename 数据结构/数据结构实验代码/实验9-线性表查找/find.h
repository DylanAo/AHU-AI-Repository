#ifndef find__h__
#define find__h__
#include <stdio.h>
typedef struct {
	int *key;
	int length;
}Sqlist;
//创建线性表
void create_sqlist(Sqlist& L, int* data);
//顺序查找
int sequential_search(Sqlist L, int tag);
//折半查找
int binary_search(Sqlist L, int tag);
#endif // !find__h__
