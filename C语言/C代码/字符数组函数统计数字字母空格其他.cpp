#include <stdio.h>
#include <string.h>

int a = 0, b = 0, c = 0, d = 0;
int main() {
	void find(char str[]);
	char str[100];
	gets(str);
	find (str);
	printf("字母%d\n数字%d\n空格%d\n其他%d\n", a, b, c, d);
}

void find(char str[]) {
	int n, i;
	char e;
	n = strlen(str);
	for (i = 0; i < n; i++) {
		e = str[i];
		if (e >= 'A' && e <= 'z')
			a++;
		else if (e >= '0' && e <= '9')
			b++;
		else if (e == ' ')
			c++;
		else
			d++;
	}
}