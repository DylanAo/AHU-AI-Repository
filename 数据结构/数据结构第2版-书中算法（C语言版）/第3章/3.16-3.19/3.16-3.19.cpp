/***链队的基本操作***/

#include<iostream>
#include<fstream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef char QElemType;
typedef int Status;
typedef char SElemType;

//- - - - - 队列的链式存储结构- - - - - 
typedef struct QNode {
	QElemType data;
	struct QNode *next;
} QNode, *QueuePtr;
typedef struct {
	QueuePtr front; //队头指针
	QueuePtr rear; //队尾指针
} LinkQueue;

//算法3.16　链队的初始化
Status InitQueue(LinkQueue &Q) {//构造一个空队列Q
	Q.front = Q.rear = new QNode; //生成新结点作为头结点，队头和队尾指针指向此结点
	Q.front->next = NULL; //头结点的指针域置空
	return OK;
}

//算法3.17　链队的入队
Status EnQueue(LinkQueue &Q, QElemType e) {//插入元素e为Q的新的队尾元素
	QueuePtr p;
	p = new QNode; //为入队元素分配结点空间，用指针p指向
	p->data = e; //将新结点数据域置为e
	p->next = NULL;
	Q.rear->next = p; //将新结点插入到队尾
	Q.rear = p; //修改队尾指针
	return OK;
}

//算法3.18　链队的出队
Status DeQueue(LinkQueue &Q, QElemType &e) {//删除Q的队头元素，用e返回其值 
	QueuePtr p;
	if (Q.front == Q.rear)
		return ERROR; //若队列空，则返回ERROR
	p = Q.front->next; //p指向队头元素
	e = p->data; //e保存队头元素的值
	Q.front->next = p->next; //修改头指针
	if (Q.rear == p)
		Q.rear = Q.front; //最后一个元素被删，队尾指针指向头结点
	delete p; //释放原队头元素的空间
	return OK;
}

//算法3.19　取链队的队头元素
SElemType GetHead(LinkQueue Q) {//返回Q的队头元素，不修改队头指针
	if (Q.front != Q.rear) //队列非空
		return Q.front->next->data; //返回队头元素的值，队头指针不变
}

int main() {
	int choose, flag = 0;
	LinkQueue Q;
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