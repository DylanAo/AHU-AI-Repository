/***顺序栈的实现***/

#include<iostream>
#include<fstream>
using namespace std;

//顺序栈定义
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE  100//顺序栈存储空间的初始分配量
typedef int Status;
typedef char SElemType;

typedef struct {
	SElemType *base;//栈底指针
	SElemType *top;//栈顶指针
	int stacksize;//栈可用的最大容量
} SqStack;

//算法3.1　顺序栈的初始化
Status InitStack(SqStack &S) {
	//构造一个空栈S
	S.base = new SElemType[MAXSIZE];//为顺序栈动态分配一个最大容量为MAXSIZE的数组空间
	if (!S.base)
		exit(OVERFLOW); //存储分配失败
	S.top = S.base; //top初始为base，空栈
	S.stacksize = MAXSIZE; //stacksize置为栈的最大容量MAXSIZE
	return OK;
}
//算法3.2　顺序栈的入栈
Status Push(SqStack &S, SElemType e) {
	// 插入元素e为新的栈顶元素
	if (S.top - S.base == S.stacksize)
		return ERROR; //栈满
	*(S.top++) = e; //元素e压入栈顶，栈顶指针加1
	return OK;
}
//算法3.3　顺序栈的出栈
Status Pop(SqStack &S, SElemType &e) {
	//删除S的栈顶元素，用e返回其值	
	if (S.base == S.top)
		return ERROR;//栈空
	e = *(--S.top); //栈顶指针减1，将栈顶元素赋给e
	return OK;
}
//算法3.4　取顺序栈的栈顶元素
char GetTop(SqStack S) {//返回S的栈顶元素，不修改栈顶指针
	if (S.top != S.base) //栈非空
		return *(S.top - 1); //返回栈顶元素的值，栈顶指针不变
}

int main() {
	SqStack s;
	int choose, flag = 0;
	SElemType j, e, t;
	cout << "1.初始化\n";
	cout << "2.入栈\n";
	cout << "3.读栈顶元素\n";
	cout << "4.出栈\n";
	cout << "0.退出\n\n";

	choose = -1;
	while (choose != 0) {
		cout << "请选择:";
		cin >> choose;
		switch (choose) {
		case 1://算法3.1　顺序栈的初始化
			if (InitStack(s)) {
				flag = 1;
				cout << "成功对栈进行初始化\n\n";
			} else
				cout << "初始化栈失败\n\n";
			break;
		case 2: {//算法3.2　顺序栈的入栈
			fstream file;
			file.open("SqStack.txt");//
			if (!file) {
				cout << "错误！未找到文件！\n\n" << endl;
				exit(ERROR);
			}
			if (flag) {
				flag = 1;
				cout << "进栈元素依次为：\n";
				while (!file.eof()) {
					file >> j;
					if (file.fail())
						break;
					else {
						Push(s, j);
						cout << j << "  ";
					}
				}
				cout << endl << endl;
			} else
				cout << "栈未建立，请重新选择\n\n";
			file.close();
		}
			break;
		case 3://算法3.3　顺序栈的出栈
			if(flag != -1 && flag != 0)
				cout << "栈顶元素为：\n" << GetTop(s) << endl << endl;
			else
				cout << "栈中无元素，请重新选择\n" << endl;
			break;
		case 4://算法3.4　取顺序栈的栈顶元素
			cout << "依次弹出的栈顶元素为:\n";
			while (Pop(s, t)){
				flag = -1;
				cout << t << "  ";
			}
			cout << endl << endl;
			break;
		}
	}
	return 0;
}
