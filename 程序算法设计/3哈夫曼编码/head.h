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
typedef int WordType;//��Ը�����ֻ��26����ĸ�Ϳո�������ѡ���ַ�ת��Ϊ��������
typedef int WordNum;//�ַ���Ȩֵ

typedef struct DataType{
	WordType word;
	WordNum weight;
}DataMode;//�Զ���һ���ṹ����ͳ�Ƶ��ַ�����Ȩֵ

typedef struct HTNode{
	struct DataType data;
	HTNode* lchild,* rchild;
}HTNode,*HuffmanTree;