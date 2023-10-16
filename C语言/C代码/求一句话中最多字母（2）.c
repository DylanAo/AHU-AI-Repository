#include <stdio.h>
#include <string.h>

int main() {
	char str[100];
	char word[20];
	void judge(char str[], char word[]);
	puts("输入一行字符，我们将输出其中最长的字母");
	gets(str);
	judge(str, word);
	puts(word);
	return 0;
}

void judge(char str[], char word[]) {
	int len = strlen(str);
	int i, flag, lenth = 0, begin = 0, end = 0, j, n = 0;
	for (i = 0; i <= len; i++)
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
			flag = i;
			lenth ++;
		} else {
			if (n < lenth) {
				begin = flag - lenth + 1 ;
				end   = flag;
				n = lenth;
				lenth = 0;
			} else
				continue;
		}
	for (i = begin, j = 0; i <= end; j++, i++)
		word[j] = str[i];
	word[j] = '\0';
}




