#include <stdio.h>
#include <string.h>

int main() {
	void connect(char str1[100], char str2[50]);
	char str1[100];
	char str2[50];
	gets(str1);
	gets(str2);
	connect(str1, str2);
}

void connect(char str1[100], char str2[50]) {
	printf("%s", strcat(str1, str2));
}