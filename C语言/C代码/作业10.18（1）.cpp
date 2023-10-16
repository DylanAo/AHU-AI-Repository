#include <stdio.h>

//By ChenAo 2021.10.18
int main() {
	char c1 = 'C';
	char c2 = 'h' ;
	char c3 = 'i';
	char c4 = 'n';
	char c5 = 'a';
	c1 += 4;
	c2 += 4;
	c3 += 4;
	c4 += 4;
	c5 += 4;
	putchar(c1);
	putchar(c2);
	putchar(c3);
	putchar(c4);
	putchar(c5);
	putchar('\n');
	printf("%c%c%c%c%c\n", c1, c2, c3, c4, c5);
	return 0;
}