#include <stdio.h>

int main() {
	void put (int *);
	void get (int *);
	void find (int *);
	int a[10];
	get (a);
	find (a);
	put (a);
}

void get(int *p) {
	int i;
	for (i = 0; i <= 9; i++)
		scanf("%d", p++);
}

void put (int *p) {
	int i;
	for (i = 0; i <= 9; i++)
		printf("%d ", *p++);
}

void find (int *p) {
	int *max, *min;
	int i, t;
	max = p + 9;
	min = p;
	for (i = 0; i <= 9; i++) {
		if (*max < * (p + i)) {
			t = *max;
			*max = *(p + i);
			*(p + i) = t;
		}
		if (*min > *(p + i)) {
			t = *min;
			*min = *(p + i);
			*(p + i) = t;
		}
	}
}