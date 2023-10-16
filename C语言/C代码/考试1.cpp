#include <stdio.h>

int main() {
	int i;
	char *p;
	char a[5] = {'0'};
	gets(a);
	p = a;

	for (i = 0; a[i] != '\0'; i++);

	printf("%dÎ»Êý\n", i);
	p = p + i - 1;

	while (p >= a)
		printf("%c", *p--);
}