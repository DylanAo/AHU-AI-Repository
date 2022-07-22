#ifndef hash__h__
#define hash__h__
#define Hash_Length 10
#include <stdio.h>
typedef struct h {
	int key;
	struct h* next;
}node,*hash;
//构建散列表
int create_hash(hash& H);
//输入数据
int in_hash(hash& H, int e);
//哈希表查找
int search_hash(hash& H, int e);
//打印表（一个链）
void print_hash(hash H, int e);
#endif // !hash__h__