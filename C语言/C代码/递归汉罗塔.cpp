#include <stdio.h>

int main() {
	void hanoi(int n, char one, char two, char three);
	int m;
	scanf("%d", &m);
	hanoi(m, 'A', 'B', 'C');
}

//1 2 3 座为固定概念，即1为起始座，2为借助座，3为目标座
//注意这里数字与下面英文无关，仅是hanoi函数中char类型位置（第几个）
//起始，目标，借助座与A B C 无关
void hanoi(int n, char one, char two, char three) {
	void move (char x, char y);
	if (n == 1)
		move(one, three);//这是整个大过程最后一步，将起始座转移到目标座
	else {
		hanoi(n - 1, one, three, two);//此时想将原起始座转移到借助座
		move (one, three);//这是中间步骤，起始座还剩最后一块，将他转移到目标座
		hanoi(n - 1, two, one, three);//此时想将原借助座转移到目标座
	}
}

void move(char x, char y) {
	printf("%c-->%c\n", x, y);
}