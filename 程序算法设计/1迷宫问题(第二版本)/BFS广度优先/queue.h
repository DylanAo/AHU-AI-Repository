#pragma once

#define NULL 0
#define maze_line 7
#define maze_row 7

class point {
private:
	int x;
	int y;
	int last_index;

public:
	friend class Queue;
	void set(int line,int row, int index);
	void print();
};

class Queue {
private:
	int head;
	int rear;
	point node[100];  //  累了，不想写链队列了，整个顺序的吧

public:
	Queue();
	point De();
	void En(int x, int y, int index);
	void print();
	void print(int now);
	int get_index();
	bool detection_break(int maze[maze_line][maze_row]);
	int get_line(int index);
	int get_row(int index);
	
};