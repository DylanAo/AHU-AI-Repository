#include <stdio.h>
#include <windows.h>

int main() {
	char a[18];
	int sum, z = 0;
	int quan[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
	gets(a);

	for (int i = 0; i <= 16; i++)
		sum += (a[i] - 48) * quan[i];

	z = sum / 17 % 11;

	switch (z) {
		case (0):
			if (a[17] != '1')
				goto de;
			else
				goto ys;

		case (1):
			if (a[17] != '0')
				goto de;
			else
				goto ys;

		case (2):
			if (a[17] != 'x')
				goto de;
			else
				goto ys;

		case (3):
			if (a[17] != '9')
				goto de;
			else
				goto ys;

		case (4):
			if (a[17] != '8')
				goto de;
			else
				goto ys;

		case (5):
			if (a[17] != '7')
				goto de;
			else
				goto ys;

		case (6):
			if (a[17] != '6')
				goto de;
			else
				goto ys;

de:

		default:
			printf("不对劲\n");
			system("pause");
	}

ys:
	printf("对劲了");
}