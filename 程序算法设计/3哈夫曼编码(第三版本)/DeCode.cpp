#include <iostream>
#include <fstream>
#include <vector>
#include <vector>
#include <sstream>
using namespace std;

string HuffmanTreeName = "D:\\实验3\\HuffmanTree.txt"; // 哈夫曼树文件HuffmanTree
string HcodeName = "D:\\实验3\\Hcode.txt"; // 密码表Hcode

string CodeFileName = "D:\\实验3\\CodeFile.txt"; // 待解码文件CodeFile
string TextFileName = "D:\\实验3\\TextFile.txt"; // 已解码文件TextFile

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

// 将读取HuffmanTree.txt文件的代码封装成函数
vector<HuffmanTreeNode> readHuffmanData()
{
    vector<HuffmanTreeNode> nodes;  // 存放Huffman树节点的结构体数组
    ifstream inFile(HuffmanTreeName);
    if (!inFile)
        cout << "无法打开文件 " << HuffmanTreeName << endl;

    // 读取文件中的每一行，并将数据存入结构体中
    int weight, parent, lchild, rchild;
    while (inFile >> weight >> parent >> lchild >> rchild)
    {
        HuffmanTreeNode node = { weight, parent, lchild, rchild };
        nodes.push_back(node);
    }
    inFile.close();  // 关闭文件

    return nodes;
}

// 将读取Hcode.txt文件的代码封装成函数
vector<HuffManCode> readHuffmanCode()
{
    vector<HuffManCode> codes;  // 存放哈夫曼编码的结构体数组
    ifstream inFile(HcodeName);  // 打开Hcode.txt文件
    if (!inFile)
        cout << "无法打开文件 " << HcodeName << endl;

    // 读取文件中的每一行，并将数据存入结构体中
    string ch;
    int code;

    inFile >> code; // 第一行的空格无法正常读取
    HuffManCode hc = { " ", code };
    codes.push_back(hc);

    while (inFile >> ch >> code)
    {
        HuffManCode hc = { ch, code };
        codes.push_back(hc);
    }
    inFile.close();  // 关闭文件

    return codes;
}

int main() 
{
    int  len;
    vector<HuffmanTreeNode> nodes = readHuffmanData(); // 读取HuffmanTree.txt文件并将内容存入nodes中
    // 输出结构体数组中存储的数据
    for (int i = 0; i < nodes.size(); ++i) {
        cout << "weight: " << nodes[i].weight << ", parent: " << nodes[i].parent
            << ", lchild: " << nodes[i].lchild << ", rchild: " << nodes[i].rchild << endl;
    }
    cout << endl;

    vector<HuffManCode> codes = readHuffmanCode(); // 读取Hcode.txt文件并将内容存入codes中
    // 输出结构体数组中存储的数据
    for (int i = 0; i < codes.size(); ++i)
        cout << "ch: " << codes[i].ch << ", code: " << codes[i].code << endl;
    cout << endl;

    string str;
    ifstream inFile(CodeFileName); // 打开名为CodeFile.txt的文件
    if (!inFile)
    {
        cout << "无法打开文件 " << CodeFileName << endl;
    }
    getline(inFile, str); // 从文件中读取到字符串str中
    inFile.close();

    cout << "读取CodeFile.txt:" << str << endl << endl; // 输出读取到的字符串

    ofstream outFile(TextFileName); // 创建名为TextFile.txt的文件
    if (!outFile)
        cout << "无法打开文件 " << TextFileName << endl;

    cout << "译码结果为:";
    len = nodes.size();
    int q = len;// 表示根节点的下标
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == '0')
            q = nodes[q - 1].lchild; // 如果该字符为'0'，进入左子树
        else if (str[i] == '1')
            q = nodes[q - 1].rchild; // 如果该字符为'1'，进入右子树

        if (nodes[q - 1].lchild == 0 && nodes[q - 1].rchild == 0) // 当该节点为叶子节点时
        {
            outFile << codes[q - 1].code; // 将该叶子节点对应的字符写入到Textfile.txt中
            cout << codes[q - 1].ch;  // 输出该叶子节点对应的字符
            q = len;   // 将q重置为根节点的下标
        }
    }
    outFile.close();

    cout << endl << "译码结果已保存在文件 " << TextFileName << " 中！" << endl;
}