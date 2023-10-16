#include <stdio.h>

int main() {
	void change (char *, char *);
	char str1[] = {"I do not want to do homework!"};
	char str2[] = {"So do I."};
	change (str1, str2);
}

void change (char *a, char *b) {
	int m;
	char *c = a;
	scanf("%d", &m);
	a += m - 1;
	char *d = a;
	for (; a <= d + 9;)
		*a++ = *b++;
	for (; (*c) != '\0';)
		printf("%c", *c++);
}
