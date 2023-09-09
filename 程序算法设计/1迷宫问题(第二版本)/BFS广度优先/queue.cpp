#include"queue.h"
#include<iostream>

using namespace std;

Queue::Queue() {
	head = 0;
	rear = 0;
}

void point::set(int line, int row, int index) {
	x = line;
	y = row;
	last_index = index;
}

point Queue::De() {
	if (head + 1 > rear) {
		cout << "Empty!" << endl;
	}
	else{
		int last = head;
		head++;
		return node[last];
	}
}
void Queue::En(int x, int y, int index) {
	node[rear].set(x, y, index);
	rear++;
}

void point::print() {
	cout << x << " " << y << " " << last_index << " " << endl;
}

void Queue::print() {
	int now = 0;
	for (now = head; now < rear; now++) {
		node[now].print();
	}
}

int Queue::get_index() {
	return rear - 1;
}

bool Queue::detection_break(int maze[maze_line][maze_row]) {
	if (node[rear - 1].x == 0 && node[rear - 1].y == 0) {
		return true;
	}
	else{
		return false;
	}
}

void Queue::print(int now) {
	while (now != -1){
		node[now].print();
		now = node[now].last_index;
	}
}

int Queue::get_line(int index) {
	return node[index].x;
}

int Queue::get_row(int index) {
	return node[index].y;
}

