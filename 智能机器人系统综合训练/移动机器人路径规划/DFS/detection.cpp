#include "detection.h"
#include <iostream>

using namespace std;

Stack detection(int line, int row, Stack &s, int maze[maze_line][maze_row]) {

	//探测该位置是不是终点
	if (maze[line][row] == 2) {
		s.push(line, row);
		return s;
	}

	// 是终点的强制结束，结束一切递归
	if (s.get_head()!= NULL && maze[s.get_line()][s.get_row()] == 2) {
		return s;
	}

	// 四方探测
	if (maze[line][row] == 0) {
		s.push(line, row);  //没走过，入栈
		maze[line][row] = 3;  //走过设置为3

		// 上
		if (line - 1 >= 0) { // 检查是否超下标
			s = detection(line - 1, row, s, maze);
		}
		if (s.get_line() == line && s.get_row() == row) { //检测动没动地方
			maze[line][row]++;// 没动地方加1
		}

		// 下
		if (line + 1 <= maze_line - 1) {
			s = detection(line + 1, row, s, maze);
		}
		if (s.get_line() == line && s.get_row() == row) { //检测动没动地方
			maze[line][row]++;// 没动地方加1
		}

		// 左
		if (row - 1 >= 0) {
			s = detection(line, row - 1, s, maze);
		}
		if (s.get_line() == line && s.get_row() == row) { //检测动没动地方
			maze[line][row]++;// 没动地方加1
		}

		// 右
		if (row + 1 <= maze_row - 1) {
			s = detection(line, row + 1, s, maze);
		}
		if (s.get_line() == line && s.get_row() == row) { //检测动没动地方
			maze[line][row]++;// 没动地方加1
		}

		// 3 + 4 = 7 4次没动地方，出栈
		if (maze[line][row] == 7) {
			s.pop();
		}
	}
	return s;
}



void print(int maze[maze_line][maze_row], Stack s) {
	while (s.get_head()!= NULL) {
		maze[s.get_line()][s.get_row()] = 9;
		s.move();
	}
	int line = 0, row = 0;
	for (line = 0; line < maze_line; line++) {
		for (row = 0; row < maze_row; row++) {
			cout << maze[line][row] << "  ";
		}
		cout << endl;
	}
}