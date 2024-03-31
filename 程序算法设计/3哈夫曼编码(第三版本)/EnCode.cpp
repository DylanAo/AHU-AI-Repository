#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

#define NUM 10000

string DataFileName = "D:\\ʵ��3\\DataFile.txt"; // ͳ������DataFile

string HuffmanTreeName = "D:\\ʵ��3\\HuffmanTree.txt"; // ���������ļ�HuffmanTree
string HcodeName = "D:\\ʵ��3\\Hcode.txt"; // �����Hcode

string TextName = "D:\\ʵ��3\\Text.txt"; // �������ļ�Text
string CodeName = "D:\\ʵ��3\\Code.txt"; // �ѱ����ļ�Code

string list;
int len;//��ǰ�ַ����ĳ���
int flag = 0;//����Ƿ�ɹ�������������

typedef struct
{
	int weight; // Ȩ��
	int parent, lchild, rchild; // ���ڵ㣬��������������
}HTNode, * HuffmanTree; // ��������

typedef struct
{
	char ch;
	char code[NUM];
}HuffmanCode, * Hcode; // ����������

// Ѱ����С���СȨֵ�ڵ�
void Select(HuffmanTree HTree, int end, int& s1, int& s2) // ע�⴫��������s1 s2�ĵ�ַ
{
	for (int i = 1; i <= end; i++)
		if (HTree[i].parent == 0)
		{
			s1 = i;
			break;
		}
	for (int i = 1; i <= end; i++)
		if (HTree[i].weight < HTree[s1].weight && HTree[i].parent == 0)
			s1 = i; // ��СȨֵ

	for (int i = 1; i <= end; i++)
		if (HTree[i].parent == 0 && i != s1)
		{
			s2 = i;
			break;
		}
	for (int i = 1; i <= end; i++)
		if (HTree[i].weight < HTree[s2].weight && i != s1 && HTree[i].parent == 0)
			s2 = i; // ��СȨֵ
}

//��ʼ����������
void InitTree(HuffmanTree& HTree)
{
	ifstream inFile(DataFileName.c_str());
	if (!inFile)
	{
		cout << "�޷����ļ� " << DataFileName << endl;
		return;
	}
	cout << "��ȡ�ļ� " << DataFileName << " �������:" << endl;

	vector<string> characters; // ��ĸ����
	string character;
	vector<int> weights; // Ȩ������
	int weight;
	while (inFile >> character >> weight) // һ��һ�еض�ȡ
	{
		if (character == "SpaceWork")
			character = " ";
		cout << character << ":" << weight << endl;
		characters.push_back(character); // ��ĸ���characters
		weights.push_back(weight); // Ȩ�ش��weights
	}
	inFile.close();

	stringstream SS;
	for (int i = 0; i < characters.size(); i++)
		SS << characters[i]; // ��ÿ��Ԫ��׷�ӵ�SS�ַ�������
	list = SS.str();
	cout << endl << "�ļ���ȫ����ĸΪ:" << list << endl;
	len = list.length();
	cout << "��" << len << "���ַ�" << endl << endl;
	HTree = new HTNode[2 * len + 1];


	cout << "�������������������:" << endl;
	for (int i = 1; i <= 2 * len - 1; i++) //��ʼ����������
	{
		HTree[i].parent = 0;
		HTree[i].lchild = 0;
		HTree[i].rchild = 0;
	}

	for (int i = 1; i <= 2 * len - 1; i++) //������������
	{
		if (i <= len) // 1��len�Ľڵ�Ȩֱֵ�Ӹ���
		{
			HTree[i].weight = weights[i - 1];
			cout << i << " " << HTree[i].weight << " " << HTree[i].lchild << " " << HTree[i].rchild << endl;
		}
		else // len+1��2*len-1�Ľڵ�Ȩֵ�������
		{
			int s1, s2;
			Select(HTree, i - 1, s1, s2); // ����s1��s2��ֵΪȨֵ��С���С�ڵ�
			HTree[s1].parent = i;
			HTree[s2].parent = i;
			HTree[i].lchild = s1;
			HTree[i].rchild = s2;
			HTree[i].weight = HTree[s1].weight + HTree[s2].weight;
			cout << i << " " << HTree[i].weight << " " << HTree[i].lchild << " " << HTree[i].rchild << endl;
		}
	}

	//�ѹ����������浽�ļ�HaffmanTree��
	ofstream htreefile(HuffmanTreeName.c_str());
	if (!htreefile)
	{
		cout << "�޷����ļ� " << HuffmanTreeName << endl;
		return;
	}
	for (int i = 1; i <= 2 * len - 1; i++)
		htreefile << HTree[i].weight << " " << HTree[i].parent << " " << HTree[i].lchild << " " << HTree[i].rchild << endl;
	htreefile.close();

	cout << endl << "���������ṹ����ѱ��浽�ļ� " << HuffmanTreeName << " ��" << endl;
	flag = 1;
}

// �Բ����ļ����й���������
void enCode(HuffmanTree HTree, Hcode& Hcode)
{
	//��ȡ�ļ�Text.txt�����ı�����
	ifstream inFile(TextName);
	if (!inFile)
	{
		cout << "�޷����ļ� " << TextName << endl;
		return;
	}
	cout << "���ļ� " << TextName << " ���й���������" << endl;

	string Text;
	getline(inFile, Text);
	cout << "��ȡ�ļ� " << TextName << " :" << Text << endl;
	inFile.close();

	ofstream code(CodeName);
	if (!code)
	{
		cout << "�޷����ļ� " << CodeName << endl;
		return;
	}

	for (int i = 0; i < Text.length(); i++)//ÿһ���ַ�
	{
		int i_index;
		if (list.find(Text[i]) != EOF)
			i_index = list.find(Text[i]) + 1;//��������ַ����ڹ����������ҵ�����ַ�
		else
		{
			cout << "��������Ĺ����������Ҳ����ַ� ��" << Text[i] << "' !" << endl;
			return;
		}

		cout << "��" << Text[i] << "��  index:" << i_index << "	" << "code:";
		int j = 0;
		while (Hcode[i_index].code[j] != '\0')
		{
			code << Hcode[i_index].code[j];//���õ��ı���д��Code.txt��
			cout << Hcode[i_index].code[j];
			j++;
		}//ÿһ���ַ��Ĺ���������
		cout << endl;
	}
	code.close();

	cout << endl << "�����ѳɹ�д���ļ� " << CodeName << " �С�" << endl;
}

// ����������
void EnCode(HuffmanTree HTree, Hcode& Hcode)
{
	//������ÿ���ַ��ı���
	Hcode = new HuffmanCode[len + 1]; // ��̬����ռ�洢���������������len + 1��ָ��
	char* cd = new char[len]; // ����ռ���ʱ���ÿ���ַ��Ĺ�����������ַ�����
	cd[len - 1] = '\0'; // �����һ��λ���ϴ洢һ�����ַ�
	int start, now, father; // �ֱ��ʾ�����������������еĿ�ʼλ�á���ǰ�ڵ㡢���ڵ�

	// ��0��ָ�벻�ã���1��len��ָ��洢ÿ���ַ��ı���
	for (int i = 1; i <= len; i++)
	{
		start = len - 1; // ��ʼ����ʼλ��
		now = i;
		father = HTree[i].parent;
		// ��ǰ�ڵ��i��ʼ��һֱ׷�ݵ����ڵ�
		while (father != 0)
		{
			--start;
			// ÿһ��׷�ݵ����ڵ�ʱ������ǰ�ڵ�ı������cd��
			if (HTree[father].lchild == now)
				cd[start] = '0';
			else
				cd[start] = '1';
			now = father;
			father = HTree[father].parent;
			// ����ǰ�ڵ�ĸ��ڵ㸳����ǰ�ڵ㣬����׷��
		}
		Hcode[i].ch = list[i - 1];
		strcpy(Hcode[i].code, &cd[start]);
	}
	delete cd;// �ͷ���ʱ��������cd�Ŀռ�

	cout << "����������:" << endl;
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

	// �����������������浽�ļ�Hcode.txt
	ofstream outFile(HcodeName);
	if (!outFile)
	{
		cout << "�޷����ļ� " << HcodeName << endl;
		return;
	}
	for (int i = 1; i <= len; i++)
		outFile << Hcode[i].ch << " " << Hcode[i].code << endl;
	outFile.close();

	cout << "�������������ѱ��浽�ļ� " << HcodeName << " ��" << endl << endl;
	enCode(HTree, Hcode);
}

int main()
{
	HuffmanTree hTree = NULL;
	Hcode hCode = NULL;
	int num;
	while (true)
	{
		cout << "����������������������������������������������������������������������������" << endl;
		cout << "---------��������������ѡ1------------" << endl;
		cout << "-----------���б�����ѡ2--------------" << endl;
		cout << "-----------����������ѡ3--------------" << endl;
		cout << "����������������������������������������������������������������������������" << endl;
		cout << "ѡ��";
		cin >> num;
		switch (num)
		{
		case 1:
		{
			cout << "\n============================================================" << endl;
			InitTree(hTree); // ������������
			cout << "============================================================\n\n" << endl;
		}
		break;

		case 2:
		{
			if (flag == 0)
			{
				cout << "����������δ����!" << endl;
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