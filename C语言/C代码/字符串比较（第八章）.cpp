
#include <stdio.h>
#include <string.h>

int main() {
	int strcmp (char *, char *);
	char s1[100], s2[100];
	gets(s1);
	gets(s2);
	printf("%d", strcmp(s1, s2));
}

int strcmp(char *p1, char *p2) {
	int a = strlen(p1);
	int b = strlen(p2);
	int c, d, e = 0, i;
	if (a == b)
		c = 0;
	else
		c = 1;
	switch (c) {
		case 0:
			d = *(p1 + 1) - *(p2 + 1);
			for (i = 0; i < a; i++)
				if ((*p1++) != (*p2++))
					e = 1;
			if (e == 1)
				return (d);
			else
				return (0);
			break;
		case 1:
			return (*++p1 - *++p2);
	}
}