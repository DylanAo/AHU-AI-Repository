#include <stdio.h>

int main () {
	char a[100], *p = a;
	int i = 0, j = 0, sum = 0;
	gets(a);
	while (1)
		if (*p++ == '.')
			goto next;
next:
	for (; *p != '\0'; p++) {
		if (*p != '0') {
			i++;
			i += j;
			j = 0;
		} else
			j++;
	}
	printf("%d", i);
}