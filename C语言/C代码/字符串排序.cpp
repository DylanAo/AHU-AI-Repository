#include <stdio.h>
#include <string.h>
void swap (char (*p)[5]);

int main() {
	char a[10][5];
	int i;
	for (i = 0; i <= 9; i++)
		scanf("%s", a[i]);
	putchar ('\n');
	swap (a);
	for (i = 0; i <= 9; i++) {
		printf("%s", a[i]);
		putchar('\n');
	}
}

void swap (char (*p)[5]) {
	int i, j;
	char t[5];
	for (i = 0; i < 9; i++)
		for (j = 0; j < 9 - i; j++)
			if (strcmp(p[j], p[j + 1] ) > 0) {
				strcpy(t, p[j]);
				strcpy(p[j], p[j + 1]);
				strcpy(p[j + 1], t);
			}
}