#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string WordsName = "D:\\实验3\\Words.txt"; // 原始文件Words
string DataFileName = "D:\\实验3\\DataFile.txt"; // 统计数据DataFile

// 统计
void Stats()
{
	ifstream inFile(WordsName);
	if (!inFile)
	{
		cout << "输入有误，未找到对应文件！" << endl;
		return;
	}

	int letterCount[27] = { 0 }; // 统计26个字母的个数，数组下标从1到26分别代表a(A)到z(Z), 0存空格
	char c;
	while (inFile.get(c)) // 当inFile读取完整个filename文件后结束
	{
		if (c >= 'a' && c <= 'z')
			letterCount[c - 'a' + 1]++; // 如果是小写字母，则对应字母计数器加1
		else if (c >= 'A' && c <= 'Z')
			letterCount[c - 'a' + 27]++; // 如果是大写字母，则对应小写字母计数器加1
		else if (c == ' ')
			letterCount[0]++;
	}
	inFile.close();

	cout << "统计文件 " << WordsName << " 中的字符频率" << endl;

	ofstream outFile(DataFileName);
	if (!outFile)
	{
		cout << "输入有误，创建文件失败！" << endl;
		return;
	}

	for (int i = 0; i < 27; i++)// 保存每个字母的频率
		if (i == 0)
			outFile << "SpaceWork  " << letterCount[i] << endl;
		else
			outFile << (char)('a' + i - 1) << "  " << letterCount[i] << endl;
	outFile.close();

	cout << "统计结果已保存在文件 " << DataFileName << " 中。" << endl;
}

int main()
{
	Stats();
	return 0;
}