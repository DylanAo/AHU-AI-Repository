#include <stdio.h>

int main() {
	int i, i2;
	float peach;
	for (i2 = 1;; i2++) {
		peach = i2;
		for (i = 1; i <= 9; i++) {
			peach = peach / 2 - 1;
		}
		if (peach == 1)
			printf("%d\n", i2);
	}
}