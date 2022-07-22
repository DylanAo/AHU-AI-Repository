#ifndef tree__h__
#define tree__h__
#include <stdio.h>
typedef struct tree {
	char data;
	struct tree* lchild;
	struct tree* rchild;
}Binode,*Bitree;
//前序中序建立二叉树
Bitree create_tree(char* f, char* m, int f1, int f2, int m1, int m2);
//前序遍历
void front_print(Bitree T);
//中序遍历
void middle_print(Bitree T);
//后序遍历
void last_print(Bitree T);
//节点数
int NodeNum(Bitree T);
//树的深度
int deep(Bitree T);
//叶子数
int leaf(Bitree T);
//度为1的数
int deep_1(Bitree T);
#endif // !tree__h__

