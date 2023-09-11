#include"queue.h"
#include<stdlib.h>

void Customer::set(int ID, int t_arrive_limit, int t_serve_limit) {
	this->ID = ID;
	arrive_time = rand() % (t_arrive_limit + 1);
	serve_time = rand() % (t_serve_limit - 5 + 1) + 5; //ื๎ตอ5min
}

int Customer::get(int mode) {
	if (mode == 1) {
		return serve_time;
	}
	if (mode == 2) {
		return arrive_time;
	}
	return 0;
}

Customers::Customers(int l_max, int l_min, int t_arrive_limit, int t_serve_limit) {
	length = (rand() % (l_max - l_min + 1)) + l_min;
	for (int i = 1; i <= length; i++) {
		cer[i].set(i, t_arrive_limit, t_serve_limit);
	}
	sout();
}

Customer Customers::get(int index) {
	return cer[index];
}

void Customers::sout() {
	int j = 0;
	for (int i = 2; i <= length; i++) {
		if (cer[i].arrive_time < cer[i - 1].arrive_time) {
			cer[0] = cer[i];
			cer[i] =cer[i - 1];
			for (j = i - 2; cer[0].arrive_time < cer[j].arrive_time && j > 0; j--) {
				cer[j + 1] = cer[j];
			}
			cer[j + 1] = cer[0];
		}
	}
}

Queue::Queue() {
	front = rear = NULL;
	length = 0;
}

Queue::~Queue() {
	Node* p;
	while (front != NULL){
		p = front;
		front = front->next;
		delete p;
	}
}

bool Queue::isEmpty() {
	return length == 0;
}

bool Queue::En(Customer cer) {
	Node* p = new Node;
	p->cer = cer;
	p->next = NULL;
	length++;
	if (front == NULL) {
		front = p;
	}
	else{
		rear->next = p;
	}
	rear = p;
	return true;
}

bool Queue::De() {
	if (isEmpty()) {
		return false;
	}
	length--;
	Node* p = front;
	front = front->next;
	delete p;
	if (isEmpty()) {
		rear = NULL;
	}
	return true;
}

bool Queue::clear() {
	Node* p;
	while (front != NULL) {
		p = front;
		front = front->next;
		delete p;
	}
	return true;
}
