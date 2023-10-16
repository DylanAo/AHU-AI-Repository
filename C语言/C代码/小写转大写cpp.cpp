#include <stdio.h>

int main() {
	char c;
	while (1) {
		c = getchar();
		if (c >= 'a' && c <= 'z')
			putchar(c - 32);
		else if (c >= 'A' && c <= 'Z')
			putchar(c);
		else
			break;
	}
	return 0;
}