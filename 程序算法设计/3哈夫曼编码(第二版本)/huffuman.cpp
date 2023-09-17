#include"huffuman.h"

Huffman_tree::Huffman_tree(Weight data) {
	// 初始化
	leave_node = data.length();
	total_node = 2 * leave_node - 1;
	for (int i = 1; i < 513; i++) {  // 注意，第一个节点我没用
		tree[i].parent = 0;
		tree[i].left_child = 0;
		tree[i].right_child = 0;
		tree[i].node.character = 0;
		tree[i].node.weight = 0;
	}
	for (int i = 1; i <= leave_node; i++) {  // 开始把权值赋值进去
		tree[i].node.character = (char)data.get(i - 1, CHAR);
		tree[i].node.weight = data.get(i - 1, WEIGHT);
	}
	// 构建哈夫曼树
	for (int i = data.length() + 1; i <= total_node; i++) {
		int min_index_1 = 0;
		int min_index_2 = 0;
		select(i - 1, min_index_1, min_index_2);
		tree[min_index_1].parent = i;
		tree[min_index_2].parent = i;
		tree[i].left_child = min_index_1;
		tree[i].right_child = min_index_2;
		tree[i].node.weight = tree[min_index_1].node.weight + tree[min_index_2].node.weight;
	}
}

bool Huffman_tree::select(int max_index, int& min_weight_1, int& min_weight_2) {
	// 感谢我自己在1年前写好了哈夫曼的代码，让我能够快速上手
	// 我发现我当时真的是天才啊
	for (int i = 1; i <= max_index; i++) {  // 找到双亲是0节点，初始化1
		if (tree[i].parent == 0) {
			min_weight_1 = i;
			break;
		}
	}
	for (int i = 1; i <= max_index; i++) {  // 找最小的双亲给1
		if (tree[i].parent == 0 && tree[i].node.weight < tree[min_weight_1].node.weight) {
			min_weight_1 = i;
		}
	}

	tree[min_weight_1].parent = 1;  // 暂时赋值，不让他选上

	for (int i = 1; i <= max_index; i++) {  // 找到双亲是0节点，初始化2
		if (tree[i].parent == 0) {
			min_weight_2 = i;
			break;
		}
	}
	for (int i = 1; i <= max_index; i++) {  // 找最小的双亲给1
		if (tree[i].parent == 0 && tree[i].node.weight < tree[min_weight_2].node.weight) {
			min_weight_2 = i;
		}
	}

	tree[min_weight_1].parent = 0;  // 赋值回来

	return true;
}

int Huffman_tree::get(int mode) {
	if (mode == LEAVE) {
		return leave_node;
	}
	else if(mode == TOTAL_NODE) {
		return total_node;
	}
	else {
		return 0;
	}
}

int Huffman_tree::get(int index, int mode) {
	switch (mode){
	case PARENT:
		return tree[index].parent;
		break;
	case LCHILD:
		return tree[index].left_child;
		break;
	case RCHILD:
		return tree[index].right_child;
		break;
	case CHAR:
		return tree[index].node.character;
		break;
	case WEI:
		return tree[index].node.weight;
		break;
	default:
		return 0;
		break;
	}
}

Huffman_code::Huffman_code(Huffman_tree tree) {
	total_char = tree.get(LEAVE);
	char* code;
	for (int i = 1; i <= total_char; i++) {
		code = new char[total_char];
		code[total_char - 1] = '\0';
		int start = total_char - 1;
		int now_index = i;
		int now_parent_index = tree.get(now_index, PARENT);
		Code_table[i].char_node.character = tree.get(now_index, CHAR);
		Code_table[i].char_node.weight = tree.get(now_index, WEI);
		while (now_parent_index != 0){
			start--;
			if (tree.get(now_parent_index, LCHILD) == now_index) {
				code[start] = '0';
			}
			else {
				code[start] = '1';
			}
			now_index = now_parent_index;
			now_parent_index = tree.get(now_index, PARENT);
		}
		Code_table[i].code = &code[start];
	}
	sout();
}

bool Huffman_code::sout() {
	int j = 0;
	for (int i = 2; i <= total_char; i++) {
		if (Code_table[i].char_node.weight > Code_table[i - 1].char_node.weight) {
			Code_table[0] = Code_table[i];
			Code_table[i] = Code_table[i - 1];
			for (j = i - 2; Code_table[0].char_node.weight > Code_table[j].char_node.weight && j > 0; j--) {
				Code_table[j + 1] = Code_table[j];
			}
			Code_table[j + 1] = Code_table[0];
		}
	}
	return true;
}

bool Huffman_code::print() {
	for (int i = 1; i <= total_char; i++) {
		cout << "Char:" << Code_table[i].char_node.character << " ";
		cout << "Weight:" << Code_table[i].char_node.weight << " ";
		cout << "Code:" << Code_table[i].code << endl;
	}
	return true;
}

string Huffman_code::Encode(string str) {
	string code_str;
	for (int i = 0; i <= str.length(); i++) {
		for (int j = 1; j <= total_char; j++) {
			if (str[i] == Code_table[j].char_node.character) {
				code_str += Code_table[j].code;
				break;
			}
		}
	}
	return code_str;
}

string Huffman_code::Decode(string str_code, int mode) {
	if (mode == IN) {
		string now_decode_str = "";
		string total_decode_str = "";
		for (int index = 0; index < str_code.length(); index++) {
			now_decode_str += str_code[index];
			for (int i = 1; i <= total_char; i++) {
				if (now_decode_str == Code_table[i].code) {
					total_decode_str += Code_table[i].char_node.character;
					//cout << Code_table[i].char_node.character;
					now_decode_str = "";
					break;
				}
			}
		}
		return total_decode_str;
	}
	else {
		string now_decode_str = "";
		string total_decode_str = "";
		for (int index = 0; index < str_code.length(); index++) {
			now_decode_str += str_code[index];
			for (int i = 1; i <= total_char; i++) {
				int mesh_num = 0;
				for (int j = 0; j < now_decode_str.length(); j++) {
					if (now_decode_str[j] != Code_table[i].code[j]) {
						break;
					}
					else {
						mesh_num++;
					}
				}
				int now_keycode_length = 0;
				for (int j = 0; Code_table[i].code[j] != '\0'; j++) {
					now_keycode_length++;
				}
				now_keycode_length--;
				if (mesh_num == now_keycode_length) {
					total_decode_str += Code_table[i].char_node.character;
					now_decode_str = "";
					break;
				}
			}
		}
		return total_decode_str;
	}
}

string split(string str, char target) {
	int index = 0;
	string target_str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == target) {
			index = i;
			break;
		}
	}
	for (int i = 0; i < index; i++) {
		target_str += str[i];
	}
	return target_str;
}

string get_file_name(string file_name, int mode) {
	string front_name;
	front_name = split(file_name, '.');
	if (mode == CODE) {
		return front_name + ".hcode";
	}
	if (mode == KEY) {
		return front_name + ".hkey";
	}
	if (mode == DECODE) {
		return front_name + "_decode.txt";
	}
}


bool EnCode(string file_name, int out_state) {
	File paper(file_name);
	cout << "当前文件内容为：" << endl;
	paper.print();
	Weight paper_weight(paper.read());
	Huffman_tree tree(paper_weight);
	Huffman_code code(tree);
	cout << "当前文件编码为：" << endl;
	code.print();
	string Hcode = code.Encode(paper.read());
	cout << "当前文件的哈夫曼编码为：" << endl;
	cout << Hcode << endl;
	if (out_state) {
		code.out_key(file_name);
		File paper_code(get_file_name(file_name, CODE));
		paper_code.write(Hcode);
		cout << "已生成文件" + get_file_name(file_name, CODE) + "和" + get_file_name(file_name, KEY) << endl;
	}
	return true;
}

bool Huffman_code::out_key(string file_name) {
	string str;
	File key(get_file_name(file_name, KEY));
	for (int i = 1; i <= total_char; i++) {
		//str = Code_table[i].char_node.character + Code_table[i].char_node.weight + " ";
		str = Code_table[i].char_node.character;
		key.write(str);
		str = to_string(Code_table[i].char_node.weight);
		key.write(str);
		key.write(Code_table[i].code);
	}
	return true;
}

Huffman_code::Huffman_code(string file_name) {
	total_char = 0;
	string str;
	File code(file_name);
	str = code.read();
	int target = 0;
	int index = 1;
	int number = 0;
	string middle_str = "";
	char* middle_code;
	for (int i = 0; i < str.length(); i++) {
		char c = str[i];
		middle_str += c;
		if (c == '\n') {
			target++;
			switch (target){
			case 1:
				Code_table[index].char_node.character = middle_str[0];
				middle_str = "";
				break;
			case 2:
				for (int i = 0; i < middle_str.length() - 1; i++) {
					number = number * 10 + middle_str[i] - 48;
				}
				Code_table[index].char_node.weight = number;
				middle_str = "";
				number = 0;
				break;
			case 3:
				middle_code = new char[middle_str.length()];
				for (int i = 0; i < middle_str.length() - 1; i++) {
					middle_code[i] = middle_str[i];
				}
				middle_code[middle_str.length()] = '\0';
				Code_table[index].code = middle_code;
				middle_str = "";
				index ++;
				target = 0;
				total_char++;
				break;
			}
		}
	}
}

bool DeCode(string code_name, string key_name, bool OUT_State) {
	Huffman_code code(key_name);
	cout << "输入的文件编码为：" << endl;
	code.print();
	File paper(code_name);
	string paper_code = paper.read();
	cout << "输入的哈夫曼编码为：" << endl;
	cout << paper_code;
	cout << "根据输入的文件编码进行解码后为：" << endl;
	string paper_decode = code.Decode(paper_code, OUT);
	cout << paper_decode << endl;
	if (OUT_State == true) {
		File paper_code(get_file_name(code_name, DECODE));
		paper_code.write(paper_decode);
		cout << "已生成文件" + get_file_name(code_name, DECODE)<< endl;
	}
	return true;
}

bool En_and_De_Code(string file_name) {
	File paper(file_name);
	cout << "当前文件内容为：" << endl;
	paper.print();
	Weight paper_weight(paper.read());
	Huffman_tree tree(paper_weight);
	Huffman_code code(tree);
	cout << "当前文件编码为：" << endl;
	code.print();
	string Hcode = code.Encode(paper.read());
	cout << "当前文件的哈夫曼编码为：" << endl;
	cout << Hcode << endl;
	cout << "当前文件的解码后为：" << endl;
	cout << code.Decode(Hcode, IN);
	return true;
}