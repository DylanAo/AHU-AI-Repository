#include<iostream>
#include<fstream>
#include<string>
#define MAXQSIZE 100//队列可能达到的最大长度
#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;

typedef struct {
	char name[20]; //姓名
	char sex; //性别，'F'表示女性，'M'表示男性
} Person;

//- - - - - 队列的顺序存储结构- - - - - 
typedef struct {
	Person *base; //队列中数据元素类型为Person
	int front; //头指针
	int rear; //尾指针
} SqQueue;

SqQueue Mdancers, Fdancers; //分别存放男士和女士入队者队列

int InitQueue(SqQueue &Q) {//构造一个空队列Q
	Q.base = new Person[MAXQSIZE]; //为队列分配一个最大容量为MAXSIZE的数组空间
	if (!Q.base)
		exit( OVERFLOW); //存储分配失败
	Q.front = Q.rear = 0; //头指针和尾指针置为零，队列为空
	return OK;
}

int EnQueue(SqQueue &Q, Person e) {//插入元素e为Q的新的队尾元素
	if ((Q.rear + 1) % MAXQSIZE == Q.front) //尾指针在循环意义上加1后等于头指针，表明队满
		return ERROR;
	Q.base[Q.rear] = e; //新元素插入队尾
	Q.rear = (Q.rear + 1) % MAXQSIZE; //队尾指针加1
	return OK;
}

int QueueEmpty(SqQueue &Q) {
	if (Q.front == Q.rear) //队空
		return OK;
	else
		return ERROR;
}

int DeQueue(SqQueue &Q, Person &e)//删除Q的队头元素，用e返回其值
{
	if (Q.front == Q.rear)
		return ERROR; //队空
	e = Q.base[Q.front]; //保存队头元素
	Q.front = (Q.front + 1) % MAXQSIZE; //队头指针加1
	return OK;
}

Person GetHead(SqQueue Q) {//返回Q的队头元素，不修改队头指针
	if (Q.front != Q.rear) //队列非空
		return Q.base[Q.front]; //返回队头元素的值，队头指针不变
}

//算法3.23　舞伴问题
void DancePartner(Person dancer[], int num) {//结构数组dancer中存放跳舞的男女，num是跳舞的人数。
	InitQueue(Mdancers); //男士队列初始化
	InitQueue(Fdancers); //女士队列初始化
	Person p;
	for (int i = 0; i < num; i++) //依次将跳舞者根据其性别入队
	{
		p = dancer[i];
		if (p.sex == 'F')
			EnQueue(Fdancers, p); //插入女队
		else
			EnQueue(Mdancers, p); //插入男队
	}
	cout << "The dancing partners are:" << endl;
	while (!QueueEmpty(Fdancers) && !QueueEmpty(Mdancers)) {//依次输出男女舞伴的姓名
		DeQueue(Fdancers, p); //女士出队
		cout << p.name << "  "; //输出出队女士姓名
		DeQueue(Mdancers, p); //男士出队
		cout << p.name << endl; //输出出队男士姓名
	}
	if (!QueueEmpty(Fdancers)) { //女士队列非空，输出队头女士的姓名
		p = GetHead(Fdancers); //取女士队头
		cout << "The first man to get a partner is: " << endl;
		cout << p.name << endl;
	} else if (!QueueEmpty(Mdancers)) { //男士队列非空，输出队头男士的姓名
		p = GetHead(Mdancers); //取男士队头
		cout << "The first woman to get a partner is: " << p.name << endl;
	}
}