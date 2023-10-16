#include <stdio.h>

int main() {
	int n, m;
	scanf("%d", &n);
	char str1[20] = {"Fuck you man!!!"};
	char str2[20] = {'a'};
	char *p = str1, *q = str2;
	m = sizeof (str1);
	for (int i = n - 1; i < m; i++)
		*(q++) = *(str1 + i);
	printf("%s", str2);
}