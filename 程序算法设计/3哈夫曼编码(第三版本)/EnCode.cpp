#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

#define NUM 10000

string DataFileName = "D:\\实验3\\DataFile.txt"; // 统计数据DataFile

string HuffmanTreeName = "D:\\实验3\\HuffmanTree.txt"; // 哈夫曼树文件HuffmanTree
string HcodeName = "D:\\实验3\\Hcode.txt"; // 密码表Hcode

string TextName = "D:\\实验3\\Text.txt"; // 待编码文件Text
string CodeName = "D:\\实验3\\Code.txt"; // 已编码文件Code

string list;
int len;//当前字符串的长度
int flag = 0;//标记是否成功创建哈夫曼树

typedef struct
{
	int weight; // 权重
	int parent, lchild, rchild; // 父节点，左子树，右子树
}HTNode, * HuffmanTree; // 哈夫曼树

typedef struct
{
	char ch;
	char code[NUM];
}HuffmanCode, * Hcode; // 哈夫曼编码

// 寻找最小与次小权值节点
void Select(HuffmanTree HTree, int end, int& s1, int& s2) // 注意传进来的是s1 s2的地址
{
	for (int i = 1; i <= end; i++)
		if (HTree[i].parent == 0)
		{
			s1 = i;
			break;
		}
	for (int i = 1; i <= end; i++)
		if (HTree[i].weight < HTree[s1].weight && HTree[i].parent == 0)
			s1 = i; // 最小权值

	for (int i = 1; i <= end; i++)
		if (HTree[i].parent == 0 && i != s1)
		{
			s2 = i;
			break;
		}
	for (int i = 1; i <= end; i++)
		if (HTree[i].weight < HTree[s2].weight && i != s1 && HTree[i].parent == 0)
			s2 = i; // 次小权值
}

//初始化哈夫曼树
void InitTree(HuffmanTree& HTree)
{
	ifstream inFile(DataFileName.c_str());
	if (!inFile)
	{
		cout << "无法打开文件 " << DataFileName << endl;
		return;
	}
	cout << "读取文件 " << DataFileName << " 结果如下:" << endl;

	vector<string> characters; // 字母向量
	string character;
	vector<int> weights; // 权重向量
	int weight;
	while (inFile >> character >> weight) // 一行一行地读取
	{
		if (character == "SpaceWork")
			character = " ";
		cout << character << ":" << weight << endl;
		characters.push_back(character); // 字母存进characters
		weights.push_back(weight); // 权重存进weights
	}
	inFile.close();

	stringstream SS;
	for (int i = 0; i < characters.size(); i++)
		SS << characters[i]; // 将每个元素追加到SS字符串流中
	list = SS.str();
	cout << endl << "文件中全部字母为:" << list << endl;
	len = list.length();
	cout << "共" << len << "个字符" << endl << endl;
	HTree = new HTNode[2 * len + 1];


	cout << "构建哈夫曼树结果如下:" << endl;
	for (int i = 1; i <= 2 * len - 1; i++) //初始化哈夫曼树
	{
		HTree[i].parent = 0;
		HTree[i].lchild = 0;
		HTree[i].rchild = 0;
	}

	for (int i = 1; i <= 2 * len - 1; i++) //构建哈夫曼树
	{
		if (i <= len) // 1到len的节点权值直接赋予
		{
			HTree[i].weight = weights[i - 1];
			cout << i << " " << HTree[i].weight << " " << HTree[i].lchild << " " << HTree[i].rchild << endl;
		}
		else // len+1到2*len-1的节点权值计算得来
		{
			int s1, s2;
			Select(HTree, i - 1, s1, s2); // 更改s1和s2的值为权值最小与次小节点
			HTree[s1].parent = i;
			HTree[s2].parent = i;
			HTree[i].lchild = s1;
			HTree[i].rchild = s2;
			HTree[i].weight = HTree[s1].weight + HTree[s2].weight;
			cout << i << " " << HTree[i].weight << " " << HTree[i].lchild << " " << HTree[i].rchild << endl;
		}
	}

	//把哈夫曼树保存到文件HaffmanTree中
	ofstream htreefile(HuffmanTreeName.c_str());
	if (!htreefile)
	{
		cout << "无法打开文件 " << HuffmanTreeName << endl;
		return;
	}
	for (int i = 1; i <= 2 * len - 1; i++)
		htreefile << HTree[i].weight << " " << HTree[i].parent << " " << HTree[i].lchild << " " << HTree[i].rchild << endl;
	htreefile.close();

	cout << endl << "哈夫曼树结构结果已保存到文件 " << HuffmanTreeName << " 中" << endl;
	flag = 1;
}

// 对测试文件进行哈夫曼编码
void enCode(HuffmanTree HTree, Hcode& Hcode)
{
	//读取文件Text.txt，将文本编码
	ifstream inFile(TextName);
	if (!inFile)
	{
		cout << "无法打开文件 " << TextName << endl;
		return;
	}
	cout << "对文件 " << TextName << " 进行哈夫曼编码" << endl;

	string Text;
	getline(inFile, Text);
	cout << "读取文件 " << TextName << " :" << Text << endl;
	inFile.close();

	ofstream code(CodeName);
	if (!code)
	{
		cout << "无法打开文件 " << CodeName << endl;
		return;
	}

	for (int i = 0; i < Text.length(); i++)//每一个字符
	{
		int i_index;
		if (list.find(Text[i]) != EOF)
			i_index = list.find(Text[i]) + 1;//对于这个字符，在哈夫曼树中找到这个字符
		else
		{
			cout << "在您构造的哈夫曼树中找不到字符 ‘" << Text[i] << "' !" << endl;
			return;
		}

		cout << "‘" << Text[i] << "’  index:" << i_index << "	" << "code:";
		int j = 0;
		while (Hcode[i_index].code[j] != '\0')
		{
			code << Hcode[i_index].code[j];//将得到的编码写入Code.txt中
			cout << Hcode[i_index].code[j];
			j++;
		}//每一个字符的哈夫曼编码
		cout << endl;
	}
	code.close();

	cout << endl << "编码已成功写入文件 " << CodeName << " 中。" << endl;
}

// 哈夫曼编码
void EnCode(HuffmanTree HTree, Hcode& Hcode)
{
	//逐个求解每个字符的编码
	Hcode = new HuffmanCode[len + 1]; // 动态分配空间存储哈夫曼编码表，包括len + 1个指针
	char* cd = new char[len]; // 分配空间临时存放每个字符的哈夫曼编码的字符数组
	cd[len - 1] = '\0'; // 在最后一个位置上存储一个空字符
	int start, now, father; // 分别表示计算哈夫曼编码过程中的开始位置、当前节点、父节点

	// 第0个指针不用，第1到len个指针存储每个字符的编码
	for (int i = 1; i <= len; i++)
	{
		start = len - 1; // 初始化开始位置
		now = i;
		father = HTree[i].parent;
		// 当前节点从i开始，一直追溯到根节点
		while (father != 0)
		{
			--start;
			// 每一次追溯到父节点时，将当前节点的编码存入cd中
			if (HTree[father].lchild == now)
				cd[start] = '0';
			else
				cd[start] = '1';
			now = father;
			father = HTree[father].parent;
			// 将当前节点的父节点赋给当前节点，向上追溯
		}
		Hcode[i].ch = list[i - 1];
		strcpy(Hcode[i].code, &cd[start]);
	}
	delete cd;// 释放临时编码数组cd的空间

	cout << "编码结果如下:" << endl;
	for (int i = 1; i <= len; i++)
	{
		int j = 0;
		cout << i << " " << list[i - 1] << " ";
		while (Hcode[i].code[j] != '\0')
		{
			cout << Hcode[i].code[j];
			j++;
		}
		cout << endl;
	}
	cout << endl;

	// 将哈夫曼编码结果保存到文件Hcode.txt
	ofstream outFile(HcodeName);
	if (!outFile)
	{
		cout << "无法打开文件 " << HcodeName << endl;
		return;
	}
	for (int i = 1; i <= len; i++)
		outFile << Hcode[i].ch << " " << Hcode[i].code << endl;
	outFile.close();

	cout << "哈夫曼编码结果已保存到文件 " << HcodeName << " 中" << endl << endl;
	enCode(HTree, Hcode);
}

int main()
{
	HuffmanTree hTree = NULL;
	Hcode hCode = NULL;
	int num;
	while (true)
	{
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "---------创建哈夫曼树请选1------------" << endl;
		cout << "-----------进行编码请选2--------------" << endl;
		cout << "-----------结束程序请选3--------------" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "选择：";
		cin >> num;
		switch (num)
		{
		case 1:
		{
			cout << "\n============================================================" << endl;
			InitTree(hTree); // 创建哈夫曼树
			cout << "============================================================\n\n" << endl;
		}
		break;

		case 2:
		{
			if (flag == 0)
			{
				cout << "哈夫曼树尚未创建!" << endl;
				break;
			}
			cout << "\n============================================================" << endl;
			EnCode(hTree, hCode);
			cout << "============================================================\n\n" << endl;
		}
		break;

		case 3:
			exit(0);
			break;
		}
	}
}