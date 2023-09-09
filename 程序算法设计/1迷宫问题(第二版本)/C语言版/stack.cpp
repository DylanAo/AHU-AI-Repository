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
	s = s_back;
	while (s != NULL) {
		int de = 0; // жу╣Ц
		if (s->next != NULL) {
			if (s->line > s->next->line) { // вС
				de = 1;
			}
			if (s->line < s->next->line) { // ср
				de = 3;
			}
			if (s->row > s->next->row) { // ио
				de = 2;
			}
			if (s->row < s->next->row) { // об
				de = 4;
			}
		}
		printf("%d %d %d\n", s->line, s->row, de);
		s = s->next;
	}
	printf("\n");
	return 1;
}

int print_maze(int maze[maze_line][maze_row], lstack s) {
	while (s->next != NULL){
		maze[s->line][s->row] = 9;
		s = s->next;
	}
	int line = 0, row = 0;
	for (line = 0; line < maze_line; line++) {
		for (row = 0; row < maze_row; row++) {
			printf("%d ", maze[line][row]);
		}
		printf("\n");
	}
	return 1;
}