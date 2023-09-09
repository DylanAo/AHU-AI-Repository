#ifndef _stack_h
#define _stack_h

#define NULL 0

#define maze_line 7
#define maze_row 7
//Á´Õ»
typedef struct linkstack {
	int line;
	int row;
	linkstack* next;
}stacknode, * lstack;

int create_stack(lstack& s);
lstack push(lstack& s, int line, int row);
lstack pop(lstack& se);
int print_stack(lstack s);
int print_stack_back(lstack s);
int print_maze(int maze[maze_line][maze_row], lstack s);
#endif // !_stack_h
