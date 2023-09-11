#pragma once

#define SERVE_TIME 1
#define ARRIVE_TIME 2

class Customer {

private:
	int ID;
	int arrive_time;
	int serve_time;

public:
	void set(int ID,int t_arrive_limit, int t_serve_limit);
	int get(int mode);
	friend class Customers;
};

class Customers {

private:
	int length;
	Customer cer[300];
	void sout();

public:
	Customers(int l_max, int l_min, int t_arrive_limit, int t_serve_limit);
	Customer get(int index);
};

class Queue {

private:
	struct Node{
		Customer cer;
		struct Node* next;
	};
	Node* front;
	Node* rear;
	int length;

public:
	Queue();
	~Queue();
	bool isEmpty();
	bool En(Customer cer);
	bool De();
	bool clear();
};