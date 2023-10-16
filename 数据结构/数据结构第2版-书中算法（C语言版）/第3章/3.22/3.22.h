/***链栈实现表达式求值***/

#include<iostream>
using namespace std;

const char oper[7] = { '+', '-', '*', '/', '(', ')', '#' };
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef char SElemType;
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
Status Push(LinkStack &S, SElemType e) {
	SNode *p = new SNode;
	if (!p) {
		return OVERFLOW;
	}
	p->data = e;
	p->next = S;
	S = p;
	return OK;
}
Status Pop(LinkStack &S, SElemType &e) {
	SNode *p;
	if (!S)
		return ERROR;
	e = S->data;
	p = S;
	S = S->next;
	delete p;
	return OK;
}
Status GetTop(LinkStack &S) {
	if (!S)
		return ERROR;

	return S->data;
}
bool In(char ch) {//判断ch是否为运算符
	for (int i = 0; i < 7; i++) {
		if (ch == oper[i]) {
			return true;
		}
	}
	return false;
}
char Precede(char theta1, char theta2) {//判断运算符优先级
	if ((theta1 == '(' && theta2 == ')') || (theta1 == '#' && theta2 == '#')) {
		return '=';
	} else if (theta1 == '(' || theta1 == '#' || theta2 == '(' || (theta1
			== '+' || theta1 == '-') && (theta2 == '*' || theta2 == '/')) {
		return '<';
	} else
		return '>';
}
char Operate(char first, char theta, char second) {//计算两数运算结果
	switch (theta) {
	case '+':
		return (first - '0') + (second - '0') + 48;
	case '-':
		return (first - '0') - (second - '0') + 48;
	case '*':
		return (first - '0') * (second - '0') + 48;
	case '/':
		return (first - '0') / (second - '0') + 48;
	}
	return 0;
}

//算法3.22　表达式求值
char EvaluateExpression() {//算术表达式求值的算符优先算法，设OPTR和OPND分别为运算符栈和操作数栈
	LinkStack OPTR, OPND;
	char ch, theta, a, b, x, top;
	InitStack(OPND); //初始化OPND栈
	InitStack(OPTR); //初始化OPTR栈
	Push(OPTR, '#'); //将表达式起始符“#”压入OPTR栈
	cin >> ch;
	while (ch != '#' || (GetTop(OPTR) != '#')) //表达式没有扫描完毕或OPTR的栈顶元素不为“#”
	{
		if (!In(ch)) {
			Push(OPND, ch);
			cin >> ch;
		} //ch不是运算符则进OPND栈
		else
			switch (Precede(GetTop(OPTR), ch)) //比较OPTR的栈顶元素和ch的优先级
			{
			case '<':
				Push(OPTR, ch);
				cin >> ch; //当前字符ch压入OPTR栈，读入下一字符ch
				break;
			case '>':
				Pop(OPTR, theta); //弹出OPTR栈顶的运算符
				Pop(OPND, b);
				Pop(OPND, a); //弹出OPND栈顶的两个运算数
				Push(OPND, Operate(a, theta, b)); //将运算结果压入OPND栈
				break;
			case '=': //OPTR的栈顶元素是“(”且ch是“)”
				Pop(OPTR, x);
				cin >> ch; //弹出OPTR栈顶的“(”，读入下一字符ch
				break;
			} //switch
	} //while
	return GetTop(OPND); //OPND栈顶元素即为表达式求值结果
}