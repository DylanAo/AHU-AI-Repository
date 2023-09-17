#include"gui.h"

void egg() {
	cout << "我看你指定有点大病" << endl;
}

bool Gui_Home() {
	cout << "**** 哈夫曼编解码系统 ****" << endl;
	cout << "您有如下三种选择：" << endl;
	cout << "1.编码并解码，无输出文件" << endl;
	cout << "2.编码，可选择输出编码后文件与密钥" << endl;
	cout << "3.编码，可选择输出解码后文件" << endl;
	cout << "特别提示，请不要输入4！！！" << endl;
	cout << "Write by DylanAo 2023.9.17" << endl;
	cout << "请输入你的选择：" << endl;
	int choice;
	bool out_state;
	char out_choice;
	string file_name;
	string file_name_2;
	cin >> choice;
	switch (choice){
	case 1:
		cout << "请输入要编码的文件名" << endl;
		cin >> file_name;
		En_and_De_Code(file_name);
		break;
	case 2:
		cout << "请输入要编码的文件名" << endl;
		cin >> file_name;
		cout << "是否要输出编码后文件与密钥?(y/n)" << endl;
		cin >> out_choice;
		if (out_choice == 'y') {
			out_state = true;
		}
		else if(out_choice == 'n') {
			out_state = false;
		}
		else{
			cout << "输错了，默认不输出";
			out_state = false;
		}
		EnCode(file_name,out_state);
		break;
	case 3:
		cout << "请输入要解码的文件名" << endl;
		cin >> file_name;
		cout << "请输入对应密钥名" << endl;
		cin >> file_name_2;
		cout << "是否要输出解码后文件?(y/n)" << endl;
		cin >> out_choice;
		if (out_choice == 'y') {
			out_state = true;
		}
		else if (out_choice == 'n') {
			out_state = false;
		}
		else {
			cout << "输错了，默认不输出";
			out_state = false;
		}
		DeCode(file_name, file_name_2, out_state);
		break;
	case 4:
		egg();
		break;
	default:
		cout << "输错了，重开吧" << endl;
		break;
	}
	return true;
}

