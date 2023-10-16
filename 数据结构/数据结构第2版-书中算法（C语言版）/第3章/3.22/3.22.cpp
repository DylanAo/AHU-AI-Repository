#include"3.22.h"

int menu() {
	int c;
	cout << "0-9以内的多项式计算" << endl;
	cout << "1.计算" << endl;
	cout << "0.退出\n" << endl;
	cout << "选择：";
	cin >> c;
	return c;
}

void main() {
	while (1) {
		switch (menu()) {
		case 1: {
			cout << "请输入要计算的表达式（操作数和结果都在0-9的范围内，以#结束）：" << endl;
			char res = EvaluateExpression();//算法3.22　表达式求值
			cout << "计算结果为" << res - 48 << endl << endl;
		}
			break;
		case 0:
			cout << "退出成功\n" << endl;
			exit(0);
		default:
			break;
		}
	}
}