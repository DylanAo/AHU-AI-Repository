#include"gui.h"

void egg() {
	cout << "�ҿ���ָ���е��" << endl;
}

bool Gui_Home() {
	cout << "**** �����������ϵͳ ****" << endl;
	cout << "������������ѡ��" << endl;
	cout << "1.���벢���룬������ļ�" << endl;
	cout << "2.���룬��ѡ�����������ļ�����Կ" << endl;
	cout << "3.���룬��ѡ�����������ļ�" << endl;
	cout << "�ر���ʾ���벻Ҫ����4������" << endl;
	cout << "Write by DylanAo 2023.9.17" << endl;
	cout << "���������ѡ��" << endl;
	int choice;
	bool out_state;
	char out_choice;
	string file_name;
	string file_name_2;
	cin >> choice;
	switch (choice){
	case 1:
		cout << "������Ҫ������ļ���" << endl;
		cin >> file_name;
		En_and_De_Code(file_name);
		break;
	case 2:
		cout << "������Ҫ������ļ���" << endl;
		cin >> file_name;
		cout << "�Ƿ�Ҫ���������ļ�����Կ?(y/n)" << endl;
		cin >> out_choice;
		if (out_choice == 'y') {
			out_state = true;
		}
		else if(out_choice == 'n') {
			out_state = false;
		}
		else{
			cout << "����ˣ�Ĭ�ϲ����";
			out_state = false;
		}
		EnCode(file_name,out_state);
		break;
	case 3:
		cout << "������Ҫ������ļ���" << endl;
		cin >> file_name;
		cout << "�������Ӧ��Կ��" << endl;
		cin >> file_name_2;
		cout << "�Ƿ�Ҫ���������ļ�?(y/n)" << endl;
		cin >> out_choice;
		if (out_choice == 'y') {
			out_state = true;
		}
		else if (out_choice == 'n') {
			out_state = false;
		}
		else {
			cout << "����ˣ�Ĭ�ϲ����";
			out_state = false;
		}
		DeCode(file_name, file_name_2, out_state);
		break;
	case 4:
		egg();
		break;
	default:
		cout << "����ˣ��ؿ���" << endl;
		break;
	}
	return true;
}

