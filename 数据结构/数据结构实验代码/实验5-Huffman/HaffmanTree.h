#ifndef HaffmanTree_H_
#define HaffmanTree_H_
#include <stdio.h>
#include <string.h>
typedef struct {
	int weight;
	int parent, lchild, rchild;
}*HTree, HNode;

typedef char** HuffmanCode;
//������������
void createHTree(HTree& H, char* str, int* rate);
//��������������
void creatrHCode(HTree H, HuffmanCode& HC, int *rate);
//��ӡȫ��
void print_all(int* rate, HuffmanCode& HC);
//����Ƶ��
void collect(char* str, int* rate);
#endif
