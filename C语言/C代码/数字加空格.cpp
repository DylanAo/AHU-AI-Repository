#include <stdio.h>//头文件 

int main() { //主函数
	void convert(int n);//函数声明
	int number;//定义整型变量
	printf("输入一个整数：");//提示语句
	scanf("%d", &number); //键盘输入
	printf("输出结构：");//提示语句
	if (number < 0) {
		putchar('-'); //先输出一个-号
		putchar(' '); //再输出一个空格
		number = -number;
	}
	convert(number);//调用自定义的转换方法
	printf("\n");//换行
	return 0;//主函数返回值为0
}

void convert(int n) { //自定义的转换方法
	int i;//定义整型变量
	if ((i = n / 10) != 0) { //递归
		convert(i);
	}
	putchar(n % 10 + '0');
	putchar(32);
}