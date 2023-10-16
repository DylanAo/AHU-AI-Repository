#include <stdio.h>

//By ChenAo 2021.11.1
int main() {
	char l;
	int a, b, c, d;
	a = b = c = d = 0;
	while ((l = getchar()) != '\n') {
		if ((l >= 'A' && l <= 'Z' ) || (l >= 'a' && l <= 'z'))
			a++;
		else if (l == ' ')
			b++;
		else if (l >= '0' && l <= '9')
			c++;
		else
			d++;
	}
	printf("%d %d %d %d", a, b, c, d);
	return 0;
}