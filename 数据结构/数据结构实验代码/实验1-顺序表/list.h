#ifndef list_h_
#define list_h_
#include <stdio.h>
#define max 5
typedef struct list_1{
	int *data;
	int length;
}*list,listnode;
//创建线性表
int create_list(list& L);
//输入数据一次给五个，用数组输入
int indata_list(list& L, int* a);
//打印线性表
int print_list(list L);
//获取线性表第n个，把数据放在e中
int get_list(list L, int n, int& e);
//找线性表值为e，返回第几个
int find_list(list L, int e);
//删除第i个
int delete_list(list& L, int i);
//第i个位置插入值为e
int insert_list(list& L, int i, int e);
#endif 

