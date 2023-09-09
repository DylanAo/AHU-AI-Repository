#pragma once

#define NULL 0

#define maze_line 7
#define maze_row 7
class point
{
public:
	point();
	friend class Stack;
	
private:
	int line;
	int row;
	point* next;
};

class Stack{
public:
	Stack();
	void push(int line, int row);
	point* pop();
	void print();
	int get_line();
	int get_line(int Key);
	int get_row();
	int get_row(int Key);
	point* get_head();
	point* get_head_next();
	void move();
	void print(Stack s);
private:
	point* head;
};
