#include <stdio.h>
int sum (int *, int);

int main() {
	void out (int *, int);
	int n, i;
	scanf("%d", &n);
	int a[n];
	for (i = 0; i < n; i++)
		a[i] = i + 1;
	out (a, n);
}

void out (int *a, int n) {
	int j = 1, i;
	for (i = 0; ; i++) {
		if ((j == 3) && ((*(a + i)) != 0)) {
			*(a + i) = 0;
			j = 1;
		}
		if (*(a + i) != 0)
			j++;
		if ((sum(a, n) == *(a + i) ) && ((*(a + i)) != 0))
			break;
		if (i == n - 1)
			i = -1;
	}
	printf("%d", i + 1);
}

int sum (int *a, int n) {
	int sum_1 = 0, i;
	for (i = 0; i < n; i++)
		sum_1 += *(a + i);
	return (sum_1);
}