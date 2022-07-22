#ifndef stack__h__
#define stack__h__
#include <stdio.h>
#include <string.h>
typedef struct stack {
	char data ;
	struct stack* next;
}SNode,*LinkStack;
//������ջ
void create_linkstack(LinkStack& S);
//��ջ
int push(LinkStack& S, char ch);
//��ջ
int pop(LinkStack& S);
//ȡջ��
char get(LinkStack& S);
//��ӡջ
void print_LinkStack(LinkStack S);
//����ƥ��
int match(LinkStack& S, char* st);
//ʮ����ת�˽���
void conversion(LinkStack& S, int num);
#endif // !stack__h__

