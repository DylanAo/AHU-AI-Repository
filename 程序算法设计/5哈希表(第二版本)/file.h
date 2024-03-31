#pragma once

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class File {
private:
	string name;

public:
	File(string name);
	bool print();
	string read();
	bool write(string str);
	bool clear();
};