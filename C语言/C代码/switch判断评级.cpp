#include <stdio.h>

int main() {
	int grade, n;
	scanf("%d", &grade);
	n = grade / 10;
	switch (n) {
		case 10:
		case 9:
			printf("A\n");
			break;
		case 8:
			printf("B\n");
			break;
		case 7:
			printf("C\n");
			break;
		case 6:
			printf("D\n");
			break;
		default :
			printf("E\n");
			break;
	}
}