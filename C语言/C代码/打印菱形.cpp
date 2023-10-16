#include <stdio.h>

int main() {
	int i, i2, i3;
	for (i = 1; i <= 5; i++) {
		if (i != 1)
			for (i2 = 1; i2 < i; i2++)
				printf(" ");
		for (i3 = 1; i3 <= 5; i3++)
			printf("*");
		printf("\n");
	}
	return 0;
}