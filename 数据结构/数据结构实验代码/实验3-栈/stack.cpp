#include "stack.h"

void create_linkstack(LinkStack& S) {
	S = new SNode;
	S->next = NULL;
}

int push(LinkStack &S,char ch) {
	SNode* p = new SNode;
	p->data = ch;
	p->next = S;
	S = p;
	return 1;
}

int pop(LinkStack& S) {
	SNode* p = S;
	S = S->next;
	delete p;
	return 1;
}

char get(LinkStack& S) {
	return S->data;
}

void print_LinkStack(LinkStack S) {
	while (S->next) {
		printf("%c", S->data);
		S = S->next;
	}
	printf("\n");
}

int match(LinkStack& S,char *st) {
	if (strlen(st) % 2 != 0) return 0;
	char *str= st;
	int flage = 0;
	for (; *str; str++) {
		if (*str == '(' || *str == '[' || *str == '{') push(S, *str);
		else switch (*str) {
		case ')':if (get(S) == '(') pop(S);
				else flage = 1; break;
		case ']':if (get(S) == '[') pop(S); 
				else flage = 1; break;
		case '}':if (get(S) == '{') pop(S); 
				else flage = 1; break;
		default: flage = 1;
		}
	}
	if (flage) return 0;
	else return 1;
}

void conversion(LinkStack& S, int num) {
	while (num) {
		push(S, num % 8 + '0');
		num /= 8;
	}
	print_LinkStack(S);
}