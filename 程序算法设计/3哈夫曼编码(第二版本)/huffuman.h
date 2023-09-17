#pragma once
#include"weight.h"
#include<iostream>
#include"file.h"

using namespace std;

#define LEAVE 1
#define TOTAL_NODE 2
#define PARENT 1
#define LCHILD 4
#define RCHILD 3
#define CHAR 2
#define WEI 5
#define OFF 0
#define ON 1
#define CODE 1
#define KEY 2
#define IN 1
#define OUT 2
#define DECODE 3

struct HTNode {
	Weight_node node;
	int parent;
	int left_child;
	int right_child;
};

class Huffman_tree {
private:
	int leave_node;
	int total_node;
	HTNode tree[513];
	bool select(int max_index, int& min_weight_1, int& min_weight_2);
public:
	Huffman_tree(Weight data);
	int get(int mode);
	int get(int index, int mode);
};

struct HCNode{
	Weight_node char_node;
	char* code;
};

class Huffman_code {
private:
	int total_char;
	HCNode Code_table[257];
	bool sout();
public:
	Huffman_code(Huffman_tree tree);
	Huffman_code(string file_name);
	bool print();
	string Encode(string str);
	string Decode(string str_code, int mode);
	bool out_key(string file_name);
};

bool EnCode(string file_name, int out_state);
bool DeCode(string code_name, string key_name, bool OUT_State);
bool En_and_De_Code(string file_name);