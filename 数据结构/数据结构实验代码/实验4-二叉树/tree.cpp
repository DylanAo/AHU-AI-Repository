#include "tree.h"
Bitree create_tree(char* f, char* m, int f1, int f2, int m1, int m2) {
	int root_num = f1;
	Bitree root = new Binode;
	root->data = *(f + f1);
	root->lchild = NULL;
	root->rchild = NULL;
	if (*(f + f1) == *(f + f2)) return root;
	if (root->data != *(f + f1)) return root;
	while (*(f + f1) != *(m + root_num) && root_num <= m2) root_num++;
	int left = root_num - m1;
	int right = m2 - root_num;
	if (left > 0)root->lchild = create_tree(f, m, f1 + 1, f1 + left, m1, root_num - 1);
	if (right > 0)root->rchild = create_tree(f, m, f1 + left + 1, f2, root_num + 1, m2);
	return root;
}

void front_print(Bitree T) {
	if (T) {
		printf("%c", T->data);
		front_print(T->lchild);
		front_print(T->rchild);
	}
}

void middle_print(Bitree T) {
	if (T) {
		front_print(T->lchild);
		printf("%c", T->data);
		front_print(T->rchild);
	}
}

void last_print(Bitree T) {
	if (T) {
		front_print(T->lchild);
		front_print(T->rchild);
		printf("%c", T->data);
	}
}

int NodeNum(Bitree T) {
	if (!T) return 0;
	else return (NodeNum(T->lchild) + NodeNum(T->rchild) + 1);
}

int deep(Bitree T) {
	if (!T) return 0;
	int left = 0, right = 0;
	left = deep(T->lchild);
	right = deep(T->rchild);
	return left > right ? left + 1 : right + 1;
}

int leaf(Bitree T) {
	if (!T) return 0;
	if (!T->lchild && !T->rchild) return 1;
	else return (leaf(T->lchild) + leaf(T->rchild));
}

int deep_1(Bitree T) {
	if (!T) return 0;
	if (T->lchild && !T->rchild) return 1;
	if (T->rchild && !T->lchild) return 1;
	else return deep_1(T->lchild) + deep_1(T->rchild);
}