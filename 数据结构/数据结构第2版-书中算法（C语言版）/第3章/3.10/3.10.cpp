/***Hanoi塔问题***/

#include"3.10.h"

int main() {
	int n;
	char a, b, c;
	a = '1';
	b = '2';
	c = '3';
	cout << "请输入初始第一个柱子上的圆盘个数：" << endl;
	cin >> n;
	cout << "将第一个柱子上的圆盘全部移动到第三个柱子上的过程为：" << endl;
	Hanoi(n, a, b, c);
	return 0;
}
