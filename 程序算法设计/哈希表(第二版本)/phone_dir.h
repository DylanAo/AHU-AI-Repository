#pragma once

#include <iostream>
#include <cstdio>
#include <string>
#include "file.h"
using namespace std;

#define NOT_FIND -1

struct phone_dir_page{
	string sex;
	string name;
	string address;
	string phone_number;
};

class phone_dir {
private:
	phone_dir_page dictionary[500];
	int hash(string phone_number);
	int hash(int conflit_hash_code);
	bool isEmpty(int index);
public:
	phone_dir();
	bool add(phone_dir_page new_page);
	bool erase(string phon_number);
	bool revise(string phone_number, phone_dir_page new_page);
	int find(string phone_number);
	bool print();
	bool load(string file_name);
	bool out(string file_name);
	bool clear();
	bool display(string phone_bumber);
};