#include "stack.h"
#include <stdio.h>

int create_stack(lstack &s) {
	s = NULL;
	return 1;
}

lstack push(lstack& s, int line, int row) {
	stacknode* p = new stacknode;
	p->line = line;
	p->row = row;
	p->next = s;
	s = p;
	return s;
}

lstack pop(lstack& s) {
	stacknode* p = s;
	if (s != NULL) {
		s = s->next;
	}
	return p;
}

int print_stack(lstack s) {
	while (s != NULL) {
		printf("%d %d\n", s->line, s->row);
		s = s->next;
	}
	return 1;
}

int print_stack_back(lstack s) {
	lstack s_back;
	create_stack(s_back);
	while (s != NULL) {
		stacknode* p = pop(s);
		push(s_back, p->line, p->row);
	}
	print_stack(s_back);
	return 1;
}
