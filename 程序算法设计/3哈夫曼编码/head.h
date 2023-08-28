#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define N 27
#define M 100

typedef int Status;
typedef int WordType;//针对该问题只有26个字母和空格的情况，选择将字符转化为整数处理
typedef int WordNum;//字符数权值

typedef struct DataType{
	WordType word;
	WordNum weight;
}DataMode;//自定义一个结构体存放统计的字符和其权值

typedef struct HTNode{
	struct DataType data;
	HTNode* lchild,* rchild;
}HTNode,*HuffmanTree;