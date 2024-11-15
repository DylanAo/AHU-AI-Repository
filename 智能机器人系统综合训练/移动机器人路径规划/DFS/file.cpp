#include "file.h"

File::File(string name) {
	this->name = name;
}

bool File::print() {
	ifstream file;
	file.open(name.c_str());
	char c;
	while ((c = file.get()) != EOF){
		cout << c;
	}
	cout << endl;
	return true;
}

string File::read() {
	ifstream file;
	string str;
	file.open(name.c_str());
	char c;
	while ((c = file.get()) != EOF){
		str.push_back(c);
	}
	return str;
}

bool File::write(string str) {
	ofstream file(name.c_str(),ios_base::app);
	file << str;
	return true;
}

bool File::matrix_out2file(int matrix[MATRIX_LINE][MATRIX_ROW]) {
	for (int i = 0; i < MATRIX_LINE; i++) {
		for (int j = 0; j < MATRIX_ROW; j++) {
			write(to_string(matrix[i][j]) + ",");
		}
		write("\n");
	}
	return true;
}

