#ifndef stack__h__
#define stack__h__
#include <stdio.h>
#include <string.h>
typedef struct stack {
	char data ;
	struct stack* next;
}SNode,*LinkStack;
//创建链栈
void create_linkstack(LinkStack& S);
//入栈
int push(LinkStack& S, char ch);
//出栈
int pop(LinkStack& S);
//取栈顶
char get(LinkStack& S);
//打印栈
void print_LinkStack(LinkStack S);
//括号匹配
int match(LinkStack& S, char* st);
//十进制转八进制
void conversion(LinkStack& S, int num);
#endif // !stack__h__

