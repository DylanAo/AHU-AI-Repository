#pragma once
#include<cstdio>
#include<iostream>
#include<cstdlib>

using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MaxSize 7

typedef int ElemType;
typedef int Status;
typedef struct StackNode
{
	ElemType dataX;
	ElemType dataY;
	struct StackNode* next;
}StackNode,*LinkStack;