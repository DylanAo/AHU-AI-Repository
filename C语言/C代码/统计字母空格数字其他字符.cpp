#include <stdio.h>

int main() {
	char e;
	int a, b, c, d;
	a = b = c = d = 0;
	while (e = (getchar() ) != '\n') {
		if (e >= 'A' && e <= 'z')
			a++;
		else if (e >= '0' && e <= '9')
			b++;
		else if (e == ' ')
			c++;
		else
			d++;
	}
	printf("%d,%d,%d,%d\n", a, b, c, d);
}