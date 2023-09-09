#include"stack.h"
#include<iostream>

using namespace std;

point::point(){
	next = NULL;
	line = 0;
	row = 0;
}


Stack::Stack() {
	head = NULL;
}

void Stack::push(int line, int row) {
	point* p = new point;
	p->line = line;
	p->row = row;
	p->next = head;
	head = p;
}

point* Stack::pop() {
	point* p = head;
	if (head != NULL) {
		head = head->next;
	}
	return p;
}

void Stack::print() {
	point* p = head;
	while (p != NULL) {
		cout <<p->line <<" " <<p->row <<endl;
		p = p->next;
	}
	cout << endl;
}

int Stack::get_line() {
	return head->line;
}

int Stack::get_line(int Key) {
	return head->next->line;
}

int Stack::get_row() {
	return head->row;
}

int Stack::get_row(int Key) {
	return head->next->row;
}

point* Stack::get_head() {
	return head;
}

point* Stack::get_head_next() {
	return head->next;
}

void Stack::move() {
	head = head->next;
}

void Stack::print(Stack s) {
	while (s.get_head() != NULL) {
		int de = 0; // жу╣Ц
		if (s.get_head_next() != NULL) {
			if (s.get_line() > s.get_line(1)) { // вС
				de = 1;
			}
			if (s.get_line() < s.get_line(1)) { // ср
				de = 3;
			}
			if (s.get_row() > s.get_row(1)) { // ио
				de = 2;
			}
			if (s.get_row() < s.get_row(1)) { // об
				de = 4;
			}
		}
		cout << s.get_line()<<" " << s.get_row()<<" " << de << endl;
		s.move();
	}
	cout << endl;
}