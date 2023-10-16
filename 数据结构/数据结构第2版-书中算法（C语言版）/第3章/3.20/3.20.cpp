/***链栈实现数制的转换***/

#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef struct SNode {
	int data;
	struct SNode *next;
} SNode, *LinkStack;

Status InitStack(LinkStack &S) {
	S = NULL;
	return OK;
}
bool StackEmpty(LinkStack S) {
	if (!S)
		return true;
	return false;
}
Status Push(LinkStack &S, int e) {
	LinkStack p;
	p = new SNode;
	if (!p) {
		return OVERFLOW;
	}
	p->data = e;
	p->next = S;
	S = p;
	return OK;
}
Status Pop(LinkStack &S, int &e) {
	LinkStack p;
	if (!S)
		return ERROR;
	e = S->data;
	p = S;
	S = S->next;
	delete p;
	return OK;
}
//算法3.20　数制的转换(链栈实现)
void conversion(int N) {//对于任意一个非负十进制数，打印输出与其等值的八进制数
	int e;
	LinkStack S;
	InitStack(S); //初始化空栈S
	while (N) //当N非零时,循环
	{
		Push(S, N % 8); //把N与8求余得到的八进制数压入栈S
		N = N / 8; //N更新为N与8的商
	}
	while (!StackEmpty(S)) //当栈S非空时，循环
	{
		Pop(S, e); //弹出栈顶元素e
		cout << e; //输出e
	}
}
int main() {//对于输入的任意一个非负十进制数，打印输出与其等值的八进制数
	int n, e;
	cout << "输入一个非负十进制数:" << endl;
	cin >> n;

	conversion(n);
	return 0;
}