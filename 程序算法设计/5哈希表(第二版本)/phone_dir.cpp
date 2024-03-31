#include"phone_dir.h"

phone_dir::phone_dir() {
	for (int i = 0; i < 500; i++) {
		dictionary[i].address = "";
		dictionary[i].name = "";
		dictionary[i].phone_number = "";
		dictionary[i].sex = "";
	}
}

int phone_dir::hash(string phone_number) {
	// ȡ��һ�ι�ϣֵ
	string mantissa = phone_number.substr(phone_number.length() - 2, 2);  // ȡ��������Ϊβ����׼����ϣ
	int tail = stoi(mantissa);
	return tail % 100;
}

int phone_dir::hash(int conflit_hash_code) {
	// ������ͻ�����ȡ��ϣֵ
	int new_hash_code = 0;
	if (new_hash_code < 500) {
		return  conflit_hash_code + 100;
	}
	else{
		return new_hash_code - 500 + 1;
	}
}

bool phone_dir::isEmpty(int index) {
	if (dictionary[index].address == "") {
		return true;
	}
	else {
		return false;
	}
}

bool phone_dir::add(phone_dir_page new_page) {
	// ��
	int count = 0;
	int hash_code = hash(new_page.phone_number);
	while (!isEmpty(hash_code)){  //�ǿգ��г�ͻ
		hash_code = hash(hash_code);
		count++;
		if (count >= 500) {  // �������ޣ�����false
			return false;
		}
	}
	// �ҵ�����ͻ��λ����,��ӽ�ȥ
	dictionary[hash_code].address = new_page.address;
	dictionary[hash_code].name = new_page.name;
	dictionary[hash_code].phone_number = new_page.phone_number;
	dictionary[hash_code].sex = new_page.sex;
	return true;
}

bool phone_dir::erase(string phone_number) {
	// ɾ
	int hash_code = find(phone_number);
	if (hash_code == NOT_FIND) {
		return false;
	}
	// �ҵ�λ����
	dictionary[hash_code].address = "";
	dictionary[hash_code].name = "";
	dictionary[hash_code].phone_number = "";
	dictionary[hash_code].sex = "";
	return true;
}

bool phone_dir::revise(string phone_number, phone_dir_page new_page) {
	// ��
	if (!erase(phone_number)) {
		return false;
	};
	add(new_page);
	return true;
}

int phone_dir::find(string phone_number) {
	// ��
	int count = 0;
	int hash_code = hash(phone_number);
	while (dictionary[hash_code].phone_number != phone_number) {  //�绰�Ų�һ��
		hash_code = hash(hash_code);
		count++;
		if (count >= 500) {  // �������ޣ�����NOT_FIND
			return NOT_FIND;
		}
	}
	return hash_code;
}

bool phone_dir::print() {
	int count = 0;
	for (int i = 0; i < 500; i++) {
		if (!isEmpty(i)) {
			count++;
			cout << "*** CONTACT " << count << " ***" << endl;
			cout << "name:" + dictionary[i].name << endl;
			cout << "phone number:" + dictionary[i].phone_number << endl;
			cout << "address:" + dictionary[i].address << endl;
			cout << "sex:" + dictionary[i].sex<< endl << endl;
		}
	}
	if (count == 0) {
		return false;
	}
	else{
		return true;
	}
}

bool phone_dir::out(string dir_name) {
	string file_name = dir_name + ".pdir";
	string str;
	File clear_file(file_name);
	clear_file.clear();
	File out_dir(file_name);
	for (int i = 0; i < 500; i++) {
		if (!isEmpty(i)) {
			out_dir.write(dictionary[i].address);
			out_dir.write(dictionary[i].name);
			out_dir.write(dictionary[i].phone_number);
			out_dir.write(dictionary[i].sex);
		}
	}
	cout << "The " + file_name + " file has been generated." << endl;
	return true;
}


bool phone_dir::load(string dir_name) {
	string file_name = dir_name + ".pdir";
	string str;
	string middle_str;
	phone_dir_page* new_page;
	new_page = new phone_dir_page;
	int target = 0;
	File load_dir(file_name);
	str = load_dir.read();
	for (int i = 0; i < str.length(); i++) {
		char c = str[i];
		middle_str += c;
		if (c == '\n') {
			char *middle = new char[middle_str.length()];
			for (int j = 0; j < middle_str.length() - 1; j++) { // ������Ϊ�����
				middle[j] = middle_str[j];
			}
			middle[middle_str.length() - 1] = '\0';
			target++;
			switch (target) {
			case 1:
				new_page->address = middle;
				middle_str = "";
				break;
			case 2:
				new_page->name = middle;
				middle_str = "";
				break;
			case 3:
				new_page->phone_number = middle;
				middle_str = "";
				break;
			case 4:
				new_page->sex = middle;
				middle_str = "";
				target = 0;
				add(*new_page);
				new_page = new phone_dir_page;
			}
		}
	}
	return true;
}

bool phone_dir::clear() {
	for (int i = 0; i < 500; i++) {
		if (!isEmpty(i)) {
			dictionary[i].address = "";
			dictionary[i].name = "";
			dictionary[i].phone_number = "";
			dictionary[i].sex = "";
		}
	}
	return true;
}

bool phone_dir::display(string phone_number) {
	int hash = find(phone_number);
	if (hash < 0) {
		return false;
	}
	else{
		cout << "*** CONTACT ***" << endl;
		cout << "name:" + dictionary[hash].name << endl;
		cout << "phone number:" + dictionary[hash].phone_number << endl;
		cout << "address:" + dictionary[hash].address << endl;
		cout << "sex:" + dictionary[hash].sex << endl << endl;
		return true;
	}
}