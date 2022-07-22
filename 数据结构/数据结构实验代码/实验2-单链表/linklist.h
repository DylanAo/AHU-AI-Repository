#ifndef linklist_h_
#define linklist_h_
#include <stdio.h>

typedef struct link {
	int data;
	struct link* next;
}*Linklist,LNode;
//创建链表
int create_linklist(Linklist& L);
//把第i个放到e里
int loacted_linklist(Linklist L, int i, int& e);
//找数值为e，返回地址
LNode* find_linklist(Linklist L, int e);
//第i位置插入值为e
int insert_linklist(Linklist& L, int i, int e);
//删除第i个
int deldte_linklist(Linklist& L, int i);
//头插法
int head_linklist(Linklist& L, int* a, int n);
//尾插法
int bottom_linklist(Linklist& L, int* a, int n);
//打表
int print_linklist(Linklist L);
#endif 