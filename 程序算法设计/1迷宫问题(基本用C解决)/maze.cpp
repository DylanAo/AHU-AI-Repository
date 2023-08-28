#include <stdio.h>
#include "stack.h"

#define maze_line 4
#define maze_row 4

// 看好了，递归开始
lstack detection(int line, int row, lstack& s, int maze[maze_line][maze_row]) {

	//探测该位置是不是终点
	if (maze[line][row] == 2) {
		s = push(s, line, row);
		return s;
	}

	// 是终点的强制结束，结束一切递归
	if (s != NULL && maze[s->line][s->row] == 2) {
		return s;
	}

	// 四方探测
	if (maze[line][row] == 0) {
		push(s, line, row);  //没走过，入栈
		maze[line][row] = 3;  //走过设置为3

		// 上
		if (line - 1 >= 0) { // 检查是否超下标
			s = detection(line - 1, row, s, maze);
		}
		if (s->line == line && s->row == row) { //检测动没动地方
			maze[line][row]++;// 没动地方加1
		}

		// 下
		if (line + 1 <= maze_line - 1) {
			s = detection(line + 1, row, s, maze);
		}
		if (s->line == line && s->row == row) { //检测动没动地方
			maze[line][row]++;// 没动地方加1
		}

		// 左
		if (row - 1 >= 0) {
			s = detection(line, row - 1, s, maze);
		}
		if (s->line == line && s->row == row) { //检测动没动地方
			maze[line][row]++;// 没动地方加1
		}

		// 右
		if (row + 1 <= maze_row - 1) {
			s = detection(line, row + 1, s, maze);
		}
		if (s->line == line && s->row == row) { //检测动没动地方
			maze[line][row]++;// 没动地方加1
		}

		// 3 + 4 = 7 4次没动地方，出栈
		if (maze[line][row] == 7) { 
			pop(s);
		}
	}
	return s;
}

int main() {
	lstack s;
	create_stack(s);
	int maze[maze_line][maze_row]{ // 0没走过，1是障碍，2是终点，3是走过的
		{0, 1, 1, 1},
		{0, 0, 0, 0},
		{0, 1, 0, 1},
		{0, 1, 0, 2},
	};
	detection(0, 0, s, maze);
	print_stack_back(s);
}