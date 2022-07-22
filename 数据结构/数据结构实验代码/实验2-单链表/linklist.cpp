#include "linklist.h"

int create_linklist(Linklist &L) {
	L = new LNode;
	L->next = 0;
	return 1;
}

int loacted_linklist(Linklist L,int i,int &e) {
	LNode* p = L;
	int j = 0;
	for (j = 0; j < i&&p; j++) p = p->next;
	e = p->data;
	if (!p || j > i) return -1;
	return 1;
}

LNode* find_linklist(Linklist L, int e) {
	LNode* p = L->next;
	while (p&&p->data != e) p = p->next;
	return p;
}

int insert_linklist(Linklist& L, int i,int e) {
	int j = 0;
	LNode* p=L;
	for (j = 0; j < i - 1 && p; j++) p = p->next;
	if (!p && j > i - 1) return -1;
	LNode* s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return 1;
}

int deldte_linklist(Linklist& L, int i) {
	int j = 0;
	LNode* p =L;
	for (j = 0; j < i - 1 && p->next; j++) p = p->next;
	if (!p->next && j > i - 1) return -1;
	LNode* q = p->next;
	p->next = q->next;
	delete q;
	return 1;
}

int head_linklist(Linklist& L, int *a,int n) {
	int i = 0;
	for (i =n-1; i >=0; i--) {
		LNode* p = new LNode;
		p->data = *(a + i);
		p->next = L->next;
		L->next = p;
	}
	return 1;
}

int bottom_linklist(Linklist& L, int* a, int n) {
	int i = 0;
	LNode* r = L;
	for (i = 0; i <n; i++) {
		LNode* p = new LNode;
		p->data = *(a + i);
		p->next = NULL;
		r->next = p;
		r = r->next;
	}
	return 1;
}

int print_linklist(Linklist L) {
	L = L->next;
	while (L) {
		printf("%d ", L->data);
		L = L->next;
	}
	printf("\n");
	return 1;
}