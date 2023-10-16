#include <stdio.h>

int main() {
	int i;
	char month[12][5] = {"ja", "fe", "qw"};
	char (*p)[5] = month;
	scanf("%d", &i);
	printf("%s", *(p + i - 1));
}