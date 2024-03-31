#include <iostream>
#include <fstream>
#include <vector>
#include <vector>
#include <sstream>
using namespace std;

string HuffmanTreeName = "D:\\ʵ��3\\HuffmanTree.txt"; // ���������ļ�HuffmanTree
string HcodeName = "D:\\ʵ��3\\Hcode.txt"; // �����Hcode

string CodeFileName = "D:\\ʵ��3\\CodeFile.txt"; // �������ļ�CodeFile
string TextFileName = "D:\\ʵ��3\\TextFile.txt"; // �ѽ����ļ�TextFile

struct HuffmanTreeNode
{
    int weight;
    int parent, lchild, rchild;
};

struct HuffManCode
{
    string ch;
    int  code;
};

// ����ȡHuffmanTree.txt�ļ��Ĵ����װ�ɺ���
vector<HuffmanTreeNode> readHuffmanData()
{
    vector<HuffmanTreeNode> nodes;  // ���Huffman���ڵ�Ľṹ������
    ifstream inFile(HuffmanTreeName);
    if (!inFile)
        cout << "�޷����ļ� " << HuffmanTreeName << endl;

    // ��ȡ�ļ��е�ÿһ�У��������ݴ���ṹ����
    int weight, parent, lchild, rchild;
    while (inFile >> weight >> parent >> lchild >> rchild)
    {
        HuffmanTreeNode node = { weight, parent, lchild, rchild };
        nodes.push_back(node);
    }
    inFile.close();  // �ر��ļ�

    return nodes;
}

// ����ȡHcode.txt�ļ��Ĵ����װ�ɺ���
vector<HuffManCode> readHuffmanCode()
{
    vector<HuffManCode> codes;  // ��Ź���������Ľṹ������
    ifstream inFile(HcodeName);  // ��Hcode.txt�ļ�
    if (!inFile)
        cout << "�޷����ļ� " << HcodeName << endl;

    // ��ȡ�ļ��е�ÿһ�У��������ݴ���ṹ����
    string ch;
    int code;

    inFile >> code; // ��һ�еĿո��޷�������ȡ
    HuffManCode hc = { " ", code };
    codes.push_back(hc);

    while (inFile >> ch >> code)
    {
        HuffManCode hc = { ch, code };
        codes.push_back(hc);
    }
    inFile.close();  // �ر��ļ�

    return codes;
}

int main() 
{
    int  len;
    vector<HuffmanTreeNode> nodes = readHuffmanData(); // ��ȡHuffmanTree.txt�ļ��������ݴ���nodes��
    // ����ṹ�������д洢������
    for (int i = 0; i < nodes.size(); ++i) {
        cout << "weight: " << nodes[i].weight << ", parent: " << nodes[i].parent
            << ", lchild: " << nodes[i].lchild << ", rchild: " << nodes[i].rchild << endl;
    }
    cout << endl;

    vector<HuffManCode> codes = readHuffmanCode(); // ��ȡHcode.txt�ļ��������ݴ���codes��
    // ����ṹ�������д洢������
    for (int i = 0; i < codes.size(); ++i)
        cout << "ch: " << codes[i].ch << ", code: " << codes[i].code << endl;
    cout << endl;

    string str;
    ifstream inFile(CodeFileName); // ����ΪCodeFile.txt���ļ�
    if (!inFile)
    {
        cout << "�޷����ļ� " << CodeFileName << endl;
    }
    getline(inFile, str); // ���ļ��ж�ȡ���ַ���str��
    inFile.close();

    cout << "��ȡCodeFile.txt:" << str << endl << endl; // �����ȡ�����ַ���

    ofstream outFile(TextFileName); // ������ΪTextFile.txt���ļ�
    if (!outFile)
        cout << "�޷����ļ� " << TextFileName << endl;

    cout << "������Ϊ:";
    len = nodes.size();
    int q = len;// ��ʾ���ڵ���±�
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == '0')
            q = nodes[q - 1].lchild; // ������ַ�Ϊ'0'������������
        else if (str[i] == '1')
            q = nodes[q - 1].rchild; // ������ַ�Ϊ'1'������������

        if (nodes[q - 1].lchild == 0 && nodes[q - 1].rchild == 0) // ���ýڵ�ΪҶ�ӽڵ�ʱ
        {
            outFile << codes[q - 1].code; // ����Ҷ�ӽڵ��Ӧ���ַ�д�뵽Textfile.txt��
            cout << codes[q - 1].ch;  // �����Ҷ�ӽڵ��Ӧ���ַ�
            q = len;   // ��q����Ϊ���ڵ���±�
        }
    }
    outFile.close();

    cout << endl << "�������ѱ������ļ� " << TextFileName << " �У�" << endl;
}