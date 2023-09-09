#include"queue.h"


int detection(int line, int row, Queue& q, int maze[maze_line][maze_row]) {
	int now_line = line;
	int now_row = row;
	int now_index = 0;
	int back_index = 0;
	int middle_index = 0;

	q.En(now_line, now_row, -1);  //起点，入队
	maze[now_line][now_row] = 3;  //走过设置为3
	back_index = 0;

	while (true) {

		//BFS
		// 上
		if (now_line - 1 >= 0 && maze[now_line - 1][now_row] == 0) {
			q.En(now_line - 1, now_row, back_index);
			maze[now_line - 1][now_row] = 3;
		}
		if (q.detection_break(maze)) {
			break;
		}

		// 下
		if (now_line + 1 <= maze_line - 1 && maze[now_line + 1][now_row] == 0) {
			q.En(now_line + 1, now_row, back_index);
			maze[now_line + 1][now_row] = 3;
		}
		if (q.detection_break(maze)) {
			break;
		}

		// 左
		if (now_row - 1 >= 0 && maze[now_line][now_row - 1] == 0) {
			q.En(now_line, now_row - 1, back_index);
			maze[now_line][now_row - 1] = 3;
		}
		if (q.detection_break(maze)) {
			break;
		}

		// 右
		if (now_row + 1 <= maze_row - 1 && maze[now_line][now_row + 1] == 0) {
			q.En(now_line, now_row + 1, back_index);
			maze[now_line][now_row + 1] = 3;
		}
		if (q.detection_break(maze)) {
			break;
		}
		
		
		now_index++;
		back_index = now_index;
		now_line = q.get_line(now_index);
		now_row = q.get_row(now_index);
	}
	return 1;
}




int main() {
	Queue q;

	int maze[maze_line][maze_row]{ // 0没走过，1是障碍，2是终点，3是走过的
		{0, 1, 0, 0, 0, 0, 0},//起点是0,0
		{0, 0, 0, 0, 1, 0, 1},
		{0, 1, 0, 1, 1, 0, 1},
		{0, 1, 0, 0, 1, 0, 1},
		{0, 1, 0, 1, 0, 0, 0},
		{0, 1, 0, 0, 0, 1, 0},//终点是5,6
		{0, 1, 0, 1, 0, 1, 1},
	};

	detection(5, 6, q, maze);
	q.print(q.get_index());
}