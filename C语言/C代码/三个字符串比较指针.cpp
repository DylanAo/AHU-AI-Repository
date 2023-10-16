#include <stdio.h>
#include <string.h>

int main() {
	void swap(char p[], char q[]);
	char a[100], b[100], c[100];
	gets(a);
	gets(b);
	gets(c);
	swap(a, b);
	swap(a, c);
	swap(b, c);
	puts(a);
	puts(b);
	puts(c);
}

void swap(char p[], char q[]) {
	if (strcmp(p, q) > 0) {
		char t[100];
		strcpy(t, p);
		strcpy(p, q);
		strcpy(q, t);
	}
}