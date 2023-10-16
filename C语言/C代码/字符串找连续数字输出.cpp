#include <stdio.h>

int main() {
	char str[100] = { 'a', '1', '2', '3', 'x', 'x', '4', '5', '6', ' ', '1', '7', '9', '6', '?', '3', '0', '2', '\0'};
	int a[20] = {0}, m = 0, j = 0;
	for (int i = 0; * (str + i) != '\0'; i++) {
s:
		if (*(str + i) == '\0')
			break;
		if ((*(str + i) <= '9' ) && (*(str + i) >= '0') ) {
			if (m == 0)
				a[j] = *(str + i) - 48;
			else
				a[j] = a[j] * 10 + *(str + i) - 48;
			m++;
			if ((*(str + i + 1)  <= '9') && (*(str + i + 1) >= '0') ) {
				i++;
				goto s;
			}
			m = 0;
			j++;
		}
	}
	int i = 0;
	for (i = 0; a[i] != 0; i++)
		printf("%d ", a[i]);
	printf("\n%d", i);
}