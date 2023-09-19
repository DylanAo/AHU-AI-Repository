#include "gui.h"

void home() {
	int choice;
	cout << "*** PHONE DIRECTORY ***" << endl;
	cout << "Write by DylanAo 2023.9.18" << endl;
	cout << "You have 2 choices" << endl;
	cout << "1. create a new phone directory" << endl;
	cout << "2. load a phone directory" << endl;
	cout << "Enter your choice:";
	cin >> choice;
}

void wrong_choice() {
	cout << "Wrong choice, Enter a new number " << endl;
	cout << "Or enter 0 to exit" << endl;
	int choice;
	cin >> choice;
	if (choice == 0) {
		system("pause");
	}
	if (choice < 3) {
		switch_mode(choice);
	}
	else{
		wrong_choice();
	}
}

void switch_mode(int mode) {
	string name;
	phone_dir dir;
	switch (mode){
	case 1:
		cout << "Enter a new phone directory name" << endl;
		cin >> name;
		BIOS(dir, name);
		break;
	case 2:
		cout << "Enter the phone directory name" << endl;
		cin >> name;
		dir.load(name);
		cout << "The load is complete" << endl;
		BIOS(dir, name);
		break;
	default:
		wrong_choice();
		break;
	}
}

void BIOS(phone_dir &dir, string name) {
	cout << "You have 7 choice" << endl;
	cout << "0. Save and exit" << endl;
	cout << "1. Add a contact" << endl;
	cout << "2. Delete a contact" << endl;
	cout << "3. Revise a contact" << endl;
	cout << "4. Find a contact" << endl;
	cout << "5. Clear the phone directory" << endl;
	cout << "6. Print the phone directory" << endl;
	int choice;
	cin >> choice;
	phone_dir_page new_page;
	string phone_number;
	switch (choice){
	case 0:
		dir.out(name);
		system("pause");
		break;
	case 1:
		cout << "Enter name" << endl;
		cin >> new_page.name;
		cout << endl;
		cout << "Enter adress" << endl;
		cin >> new_page.address;
		cout << endl;
		cout << "Enter phone number" << endl;
		cin >> new_page.phone_number;
		cout << endl;
		cout << "Enter sex" << endl;
		cin >> new_page.sex;
		cout << endl;
		dir.add(new_page);
		cout << "already add" << endl;
		BIOS(dir, name);
		break;
	case 2:
		cout << "Enter phone number" << endl;
		cin >> phone_number;
		cout << endl;
		if (dir.erase(phone_number)) {
			cout << "already delete" << endl;
		}
		else{
			cout << "Not find the contact" << endl;
		}
		BIOS(dir, name);
		break;
	case 3:
		cout << "Enter the old phone number" << endl;
		cin >> phone_number;
		cout << endl;
		cout << "Enter name" << endl;
		cin >> new_page.name;
		cout << endl;
		cout << "Enter adress" << endl;
		cin >> new_page.address;
		cout << endl;
		cout << "Enter phone number" << endl;
		cin >> new_page.phone_number;
		cout << endl;
		cout << "Enter sex" << endl;
		cin >> new_page.sex;
		cout << endl;
		if (dir.revise(phone_number, new_page)) {
			cout << "already revise" << endl;
		}
		else{
			cout << "Not find the contact" << endl;
		}
		BIOS(dir, name);
		break;
	case 4:
		cout << "Enter phone number" << endl;
		cin >> phone_number;
		cout << endl;
		if (!dir.display(phone_number)) {
			cout << "Not find the contact" << endl;
		}
		BIOS(dir, name);
		break;
	case 5:
		dir.clear();
		cout << "already clear";
		break;
	default:
		BIOS(dir, name);
		break;
	}
}