#pragma once

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define MATRIX_LINE 7 
#define MATRIX_ROW 7 

class File {
private:
	string name;

public:
	File(string name);
	bool print();
	string read();
	bool write(string str);
	bool matrix_out2file(int matrix[MATRIX_LINE][MATRIX_ROW]);
};