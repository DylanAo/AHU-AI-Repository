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
	m = strlen(a);//�������볤��
find:
	i2 = n;//��¼�˴ε��ʿ�ͷλ��
	for (i = n; (c = a[i] != ' ') && i < m; i++);//�����зֺţ�Ŀ�����ҳ�����
	n = i + 1;//��һ�ν���n����λ�ÿ�ʼ����ʱi��Ӧ�ո�Ӧ�ü�1
	if (length < (i - i2)) {//�жϴ˴ε��ʳ���
		length = i - i2;//ȡ�����
		head = i2;//����ͷ��λ��
		bottom = i;//����β��λ��
	}
	if (i < m)//���û���ߵ���󣬾ͽ��ŷ��أ�����n��λ�ý�����
		goto find;
	for (; head <= bottom; head++)//��������
		printf("%c", a[head]);//�����β���ܻ��ǿո񣬵����Ҳ�����������Բ�Ӱ��
}
//ע�⣺�������ո����֮�󳤶�Ϊ0����˿��Խ�������ո���