#include <stdio.h>
void arvage_1 (int (*p)[6]);
void unpass (int (*p)[6]);
void nb_stu (int (*p)[6]);

int main() {
	int a[4][6] = {{01, 100, 90, 95, 98, 91}, {02, 23, 34, 89, 67, 89}, {03, 70, 69, 65, 78, 87}, {04, 90, 86, 90, 87, 86}};
	arvage_1 (a);
	unpass(a);
	nb_stu(a);
}

void arvage_1 (int (*p)[6]) {
	int sum = 0, i;
	for (i = 0; i < 4; i++)
		sum += *(*(p + i) + 1);
	printf("%5.2f", sum / 4.0);
	putchar('\n');
}

void unpass (int (*p)[6]) {
	int i, i2, i3, j = 0;
	for (i = 0; i < 4; i++) {
		for (i2 = 1; i2 < 6; i2++)
			if ((*(*(p + i) + i2) ) < 60)
				j++;
		if (j >= 2)
			for (i3 = 0; i3 < 6; i3++)
				printf("%d ", *(*(p + i) + i3));
		putchar ('\n');
		j = 0;
	}
}

void nb_stu (int (*p)[6]) {
	int i, i2, i3, j = 0, sum = 0;
	for (i = 0; i < 4; i++) {
		for (i2 = 1; i2 < 6; i2++)
			sum += *(*(p + i) + i2);
		if (sum / 5.0 > 90)
			for (i3 = 0; i3 < 6; i3++)
				printf("%d ", *(*(p + i) + i3));
		putchar ('\n');
		sum = 0;
	}
	for (i = 0; i < 4; i++) {
		for (i2 = 1; i2 < 6; i2++)
			if ((*(*(p + i) + i2) ) > 85)
				j++;
		if (j == 5 )
			for (i3 = 0; i3 < 6; i3++)
				printf("%d ", *(*(p + i) + i3));
		putchar ('\n');
		j = 0;
	}
}