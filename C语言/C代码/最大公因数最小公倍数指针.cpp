#include <stdio.h>

int main() {
	int num1 = 0, num2 = 0, y = 1, t;
	int *p1, *p2;
	void change(int *, int *);
	scanf("%d %d", &num1, &num2);
	p1 = &num1;
	p2 = &num2;
	t = *p1 **p2;
	change(p1, p2);
	while (y != 0) {
		y = num1 % num2;
		num1 = num2;
		num2 = y;
	}
	printf("%d %d", num1, t / num1);
}

void change(int *p1, int *p2) {
	int t;
	if (*p1 < *p2) {
		t = *p1;
		*p1 = *p2;
		*p2 = t;
	}
}