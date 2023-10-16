#include <stdio.h>
#include <string.h>

//By ChenAo 2021.12.1
int main() {
	char a[100];
	gets(a);
	void find (char a[]);
	find (a);
}

void find (char a[]) {
	char c;
	int i, i2, number = 0, length = 0, head = 0, bottom = 0, n = 0, m;
	m = strlen(a);//测量输入长度
find:
	i2 = n;//记录此次单词开头位置
	for (i = n; (c = a[i] != ' ') && i < m; i++);//这里有分号，目的是找出单词
	n = i + 1;//下一次将从n所在位置开始，此时i对应空格，应该加1
	if (length < (i - i2)) {//判断此次单词长度
		length = i - i2;//取最长长度
		head = i2;//存入头的位置
		bottom = i;//存入尾的位置
	}
	if (i < m)//如果没有走到最后，就接着返回，并从n的位置接着走
		goto find;
	for (; head <= bottom; head++)//输出最长单词
		printf("%c", a[head]);//这里的尾可能会是空格，但输出也看不到，所以不影响
}
//注意：有连续空格计算之后长度为0，因此可以解决连续空格问