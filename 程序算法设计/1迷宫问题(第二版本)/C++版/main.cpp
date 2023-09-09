#include <iostream>
#include"stack.h"
#include"detection.h"

using namespace std;

int main(){
    Stack s;
	int maze[maze_line][maze_row]{ // 0没走过，1是障碍，2是终点，3是走过的
		{2, 1, 0, 0, 0, 0, 0},//起点是2，2
		{0, 0, 0, 0, 1, 0, 1},
		{0, 1, 0, 1, 1, 0, 1},
		{0, 1, 0, 0, 1, 0, 1},
		{0, 1, 0, 1, 0, 0, 0},
		{0, 1, 0, 0, 0, 1, 0},//终点是5，6
		{0, 1, 0, 1, 0, 1, 1},
	};
	cout << "第一列是行，第二列是列，第三列代表方向，顺时针方向，从左开始从1到4，0代表结束不走了" << endl;
	detection(5, 6, s, maze);//从后往前走
	s.print(s);
	cout << " 0没走过的空气，1是障碍，2是终点，9是路径" << endl;
	print(maze, s);
}