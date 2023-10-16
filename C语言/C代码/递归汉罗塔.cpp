#include <stdio.h>

int main() {
	void hanoi(int n, char one, char two, char three);
	int m;
	scanf("%d", &m);
	hanoi(m, 'A', 'B', 'C');
}

//1 2 3 ��Ϊ�̶������1Ϊ��ʼ����2Ϊ��������3ΪĿ����
//ע����������������Ӣ���޹أ�����hanoi������char����λ�ã��ڼ�����
//��ʼ��Ŀ�꣬��������A B C �޹�
void hanoi(int n, char one, char two, char three) {
	void move (char x, char y);
	if (n == 1)
		move(one, three);//����������������һ��������ʼ��ת�Ƶ�Ŀ����
	else {
		hanoi(n - 1, one, three, two);//��ʱ�뽫ԭ��ʼ��ת�Ƶ�������
		move (one, three);//�����м䲽�裬��ʼ����ʣ���һ�飬����ת�Ƶ�Ŀ����
		hanoi(n - 1, two, one, three);//��ʱ�뽫ԭ������ת�Ƶ�Ŀ����
	}
}

void move(char x, char y) {
	printf("%c-->%c\n", x, y);
}