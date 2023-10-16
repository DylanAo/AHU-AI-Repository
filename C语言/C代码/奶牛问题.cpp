#include <stdio.h>

int birth(int);
int main() {
	int round, cow, year, num = 1;
	scanf("%d", &year);
	num = birth(year);
	printf("%d", num);
}

int birth(int year) {
	int big = 1, small = 0, a[year] = {0}, now = 1;
	int *p = a, *q = a;
	for (int i = 1; i <= year; i++, now++) {
		if (now >= 4)
			big += *q++;
		*p++ = big;
	}
	for (p -= 1; q <= p; q++)
		small += *q;
	return (big + small);
}