#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string WordsName = "D:\\ʵ��3\\Words.txt"; // ԭʼ�ļ�Words
string DataFileName = "D:\\ʵ��3\\DataFile.txt"; // ͳ������DataFile

// ͳ��
void Stats()
{
	ifstream inFile(WordsName);
	if (!inFile)
	{
		cout << "��������δ�ҵ���Ӧ�ļ���" << endl;
		return;
	}

	int letterCount[27] = { 0 }; // ͳ��26����ĸ�ĸ����������±��1��26�ֱ����a(A)��z(Z), 0��ո�
	char c;
	while (inFile.get(c)) // ��inFile��ȡ������filename�ļ������
	{
		if (c >= 'a' && c <= 'z')
			letterCount[c - 'a' + 1]++; // �����Сд��ĸ�����Ӧ��ĸ��������1
		else if (c >= 'A' && c <= 'Z')
			letterCount[c - 'a' + 27]++; // ����Ǵ�д��ĸ�����ӦСд��ĸ��������1
		else if (c == ' ')
			letterCount[0]++;
	}
	inFile.close();

	cout << "ͳ���ļ� " << WordsName << " �е��ַ�Ƶ��" << endl;

	ofstream outFile(DataFileName);
	if (!outFile)
	{
		cout << "�������󣬴����ļ�ʧ�ܣ�" << endl;
		return;
	}

	for (int i = 0; i < 27; i++)// ����ÿ����ĸ��Ƶ��
		if (i == 0)
			outFile << "SpaceWork  " << letterCount[i] << endl;
		else
			outFile << (char)('a' + i - 1) << "  " << letterCount[i] << endl;
	outFile.close();

	cout << "ͳ�ƽ���ѱ������ļ� " << DataFileName << " �С�" << endl;
}

int main()
{
	Stats();
	return 0;
}