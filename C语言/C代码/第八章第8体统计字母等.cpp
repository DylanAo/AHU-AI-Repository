#include <stdio.h>
#include <string.h>

int main() {
	int a, b, c, d, e;
	a = b = c = d = e = 0;
	char str[100] = {0};
	gets(str);
	char *p = str;
	for (; *p != '\0'; p++) {
		if (*p >= 'A' && *p <= 'Z')
			a++;
		else if (*p >= 'a' && *p <= 'z')
			b++;
		else if (*p >= '0' && *p <= '9')
			c++;
		else if (*p == ' ')
			d++;
		else
			e++;
	}
	printf("%d %d %d %d %d", a, b, c, d, e);
}