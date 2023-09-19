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
	file << '\n';
	return true;
}

bool File::clear() {
	ofstream file_writer(name, ios_base::out);
	return true;
}