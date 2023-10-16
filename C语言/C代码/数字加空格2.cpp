#include <stdio.h>
#include <string.h>

int main() {
	void kg (char str[]);
	char str[100];
	gets(str);
	kg (str);
}

void kg (char str[]) {
	for (int i = 0; i < strlen(str); i++)
		printf ("%c ", str[i]);
}