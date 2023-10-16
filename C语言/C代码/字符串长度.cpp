#include <stdio.h>
#include <string.h>

int main() {
	int len (char *);
	char str[100];
	scanf("%s", str);
	printf("%d\n", len(str));
}

int len (char *p) {
	int i;
	for (i = 0; (*p++) != '\0'; i++);
	return (i);
}