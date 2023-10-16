#include <stdio.h>
#include <string.h>

int main() {
	void kg (char str[]);
	char str[4];
	gets(str);
	kg (str);
}

void kg (char str[]) {
	int i;
	for (i = 0; i <= 3; i++)
		printf ("%c ", str[i]);
}