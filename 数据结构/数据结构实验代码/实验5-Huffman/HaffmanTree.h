#ifndef HaffmanTree_H_
#define HaffmanTree_H_
#include <stdio.h>
#include <string.h>
typedef struct {
	int weight;
	int parent, lchild, rchild;
}*HTree, HNode;

typedef char** HuffmanCode;
//构建哈夫曼树
void createHTree(HTree& H, char* str, int* rate);
//构建哈夫曼编码
void creatrHCode(HTree H, HuffmanCode& HC, int *rate);
//打印全部
void print_all(int* rate, HuffmanCode& HC);
//计算频率
void collect(char* str, int* rate);
#endif
