#include "detection.h"
#include <iostream>

using namespace std;

Stack detection(int line, int row, Stack &s, int maze[maze_line][maze_row]) {

	//̽���λ���ǲ����յ�
	if (maze[line][row] == 2) {
		s.push(line, row);
		return s;
	}

	// ���յ��ǿ�ƽ���������һ�еݹ�
	if (s.get_head()!= NULL && maze[s.get_line()][s.get_row()] == 2) {
		return s;
	}

	// �ķ�̽��
	if (maze[line][row] == 0) {
		s.push(line, row);  //û�߹�����ջ
		maze[line][row] = 3;  //�߹�����Ϊ3

		// ��
		if (line - 1 >= 0) { // ����Ƿ��±�
			s = detection(line - 1, row, s, maze);
		}
		if (s.get_line() == line && s.get_row() == row) { //��⶯û���ط�
			maze[line][row]++;// û���ط���1
		}

		// ��
		if (line + 1 <= maze_line - 1) {
			s = detection(line + 1, row, s, maze);
		}
		if (s.get_line() == line && s.get_row() == row) { //��⶯û���ط�
			maze[line][row]++;// û���ط���1
		}

		// ��
		if (row - 1 >= 0) {
			s = detection(line, row - 1, s, maze);
		}
		if (s.get_line() == line && s.get_row() == row) { //��⶯û���ط�
			maze[line][row]++;// û���ط���1
		}

		// ��
		if (row + 1 <= maze_row - 1) {
			s = detection(line, row + 1, s, maze);
		}
		if (s.get_line() == line && s.get_row() == row) { //��⶯û���ط�
			maze[line][row]++;// û���ط���1
		}

		// 3 + 4 = 7 4��û���ط�����ջ
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