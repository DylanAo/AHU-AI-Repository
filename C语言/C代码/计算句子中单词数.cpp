#include <stdio.h>

int main() {
	char a[100];
	char c;
	int i, i2 = 0, i3 = 0;
	gets(a);
	for (i = 0; (c = a[i] ) != '\0'; i++) {
		if (c == ' ')
			i3 = 0;
		else if (i3 == 0) {
			i2++;
			i3++;
		}
	}
	printf ("%d", i2);
}