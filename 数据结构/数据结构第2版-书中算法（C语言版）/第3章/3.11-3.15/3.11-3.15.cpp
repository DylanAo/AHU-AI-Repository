/***循环队列基本操作***/

#include<iostream>
#include<fstream>
using namespace std;

#define MAXQSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef char QElemType;
typedef char SElemType;
typedef int Status;

typedef struct {
	QElemType *base;//初始化时动态分配存储空间
	int front;//头指针
	int rear;//尾指针
} SqQueue;

//算法3.11　循环队列的初始化
Status InitQueue(SqQueue &Q) {//构造一个空队列Q
	Q.base = new QElemType[MAXQSIZE]; //为队列分配一个最大容量为MAXSIZE的数组空间
	if (!Q.base)
		exit(OVERFLOW); //存储分配失败
	Q.front = Q.rear = 0; //头指针和尾指针置为零，队列为空
	return OK;
}

//算法3.12　求循环队列的长度
int QueueLength(SqQueue Q) {//返回Q的元素个数，即队列的长度
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

//算法3.13　循环队列的入队
Status EnQueue(SqQueue &Q, QElemType e) {//插入元素e为Q的新的队尾元素
	if ((Q.rear + 1) % MAXQSIZE == Q.front) //尾指针在循环意义上加1后等于头指针，表明队满
		return ERROR;
	Q.base[Q.rear] = e; //新元素插入队尾
	Q.rear = (Q.rear + 1) % MAXQSIZE; //队尾指针加1
	return OK;
}

//算法3.14　循环队列的出队
Status DeQueue(SqQueue &Q, QElemType &e) {//删除Q的队头元素，用e返回其值
	if (Q.front == Q.rear)
		return ERROR; //队空
	e = Q.base[Q.front]; //保存队头元素
	Q.front = (Q.front + 1) % MAXQSIZE; //队头指针加1
	return OK;
}

//算法3.15　取循环队列的队头元素
SElemType GetHead(SqQueue Q) {//返回Q的队头元素，不修改队头指针
	if (Q.front != Q.rear) //队列非空
		return Q.base[Q.front]; //返回队头元素的值，队头指针不变
}

int main() {
	int choose, flag = 0;
	SqQueue Q;
	QElemType e, j;
	cout << "1.初始化\n";
	cout << "2.入队\n";
	cout << "3.读队头元素\n";
	cout << "4.出队\n";
	cout << "0.退出\n\n";

	choose = -1;
	while (choose != 0) {
		cout << "请选择:";
		cin >> choose;
		switch (choose) {
		case 1://算法3.16　链队的初始化
			if (InitQueue(Q)) {
				flag = 1;
				cout << "成功对队列进行初始化\n\n";
			} else
				cout << "初始化队列失败\n\n";
			break;
		case 2: {//算法3.17　链队的入队
			fstream file;
			file.open("QNode.txt");
			if (!file) {
				cout << "错误！未找到文件！\n\n" << endl;
				exit(ERROR);
			}
			if (flag) {
				flag = 1;
				cout << "入队的元素依次为：\n";
				while (!file.eof()) {
					file >> j;
					if (file.fail())
						break;
					else {
						EnQueue(Q, j);
						cout << j << "  ";
					}
				}
				cout << endl << endl;
			} else
				cout << "队列未建立，请重新选择\n\n";
			file.close();
		}
			break;
		case 3://算法3.19　取链队的队头元素
			if (flag != -1 && flag != 0)
				cout << "队头元素为：\n" << GetHead(Q) << endl << endl;
			else
				cout << "队列中无元素，请重新选择\n" << endl;
			break;
		case 4://算法3.18　链队的出队
			cout << "依次弹出的队头元素为:\n";
			while (DeQueue(Q, e)) {
				flag = -1;
				cout << e << "  ";
			}
			cout << endl << endl;
			break;
		}
	}
	return 0;
}