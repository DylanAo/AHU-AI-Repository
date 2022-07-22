#include "hash.h"

int create_hash(hash& H) {
	H = new node[Hash_Length];
	for (int i = 0; i < Hash_Length; i++) {
		H[i].next = NULL;
		H[i].key = 0;
	}
	return 1;
}

int in_hash(hash& H,int e) {
	int num = e % Hash_Length;
	node *p = new node;
	p->key = e;
	p->next = NULL;
	if (H[num].next == NULL) {
		H[num].next = p;
		H[num].key++;
	}
	else {
		node* q = H[num].next;
		while (q->next != NULL) {
			q = q->next;
		}
		q->next = p;
		H[num].key++;
	}
	return 1;
}

int search_hash(hash& H, int e) {
	int num = e % Hash_Length;
	node* p = H[num].next;
	int flag = 0;
	while (p) {
		if (p->key == e) {
			flag = 1;
			break;
		}
		else {
			p = p->next;
		}
	}
	if (flag == 0) {
		node* q = new node;
		q->key = e;
		q->next = H[num].next;
		H[num].next = q;
	}
	return flag;
}

void print_hash(hash H,int e) {
	int num = e % Hash_Length;
	node* p = H[num].next;
	while (p) {
		printf("%d ", p->key);
		p = p->next;
	}
}