#include <stdio.h>
#include <string.h>
char rts[100];//û�뵽�ɣ�����ȫ�ֱ���

int main() {
	int i, n;
	void back(char str[100]);
	char str[100];
	gets(str);
	back(str);
	puts(rts);
}

void back(char str[100]) {
	int i, i2, n;
	n = strlen(str);
	for (i = 0, i2 = n - 1; i < n; i++, i2--)
		rts[i2] = str[i];
}
