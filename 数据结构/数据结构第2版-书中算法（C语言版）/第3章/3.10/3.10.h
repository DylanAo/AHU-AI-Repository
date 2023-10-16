#include<iostream>
using namespace std;

int m = 0;//（m是初值为0的全局变量，对搬动计数）
void move(char A, int n, char C) // 搬动操作
{
	cout << "第" << ++m << "步," << "将编号为" << n << "的圆盘从第" << A << "个柱子上移到第" << C
			<< "个柱子上" << endl;
}

//算法3.10　Hanoi塔问题的递归算法
void Hanoi(int n, char A, char B, char C) {//将塔座A上的n个圆盘按规则搬到C上，B做辅助塔
	if (n == 1)
		move(A, 1, C); //将编号为1的圆盘从A移到C
	else {
		Hanoi(n - 1, A, C, B); //将A上编号为1至n-1的圆盘移到B，C做辅助塔
		move(A, n, C);//将编号为n的圆盘从A移到C
		Hanoi(n - 1, B, A, C); //将B上编号为1至n-1的圆盘移到C，A做辅助塔
	}
}