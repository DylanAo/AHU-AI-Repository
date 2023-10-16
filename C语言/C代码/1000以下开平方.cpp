#include <stdio.h>
#include <math.h>

int main() {
	int x;
	while (1) {
		scanf("%d", &x);
		if (x <= 1000 && x >= 0)
			break;
	}
	printf("%f", sqrt(x));
	return 0;
}