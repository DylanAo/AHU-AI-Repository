#include <stdio.h>
#include <string.h>

int main() {
	void find (char str[100]);
	char str[100];
	gets (str);
	find (str);
}

void find (char str	[100]) {
	char str2[100] = {0};
	int i, i2 = 0, n;
	n = strlen(str);
	for (i = 0; i < n; i++)
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E'
		        || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
			str2[i2] = str[i];
			i2++;
		}
	puts(str2);
}