#include <stdio.h>

struct date {
	int year;
	int month;
	int day;
} da[1];
int days (struct date *);
int rn(struct date *);
int bigmonth(struct date *);

int main() {
	struct date *p;
	p = da;
	scanf("%d %d %d", &(*p).year, &(*p).month, &(*p).day);
	printf("%d", days (p));
}

int days (struct date *p) {
	return bigmonth(p) + ((*p).month - 1) * 30 + (*p).day + rn(p) - 2; //-2修正二月28天
}

int rn(struct date *p) {
	int a = 0;
	if ((((*p).year % 4) == 0) && (((*p).year % 100) != 0))
		a = 1;
	if ((*p).year % 400 == 0)
		a = 1;
	return a;
}

int bigmonth(struct date *p) {
	int a = 0;
	switch ((*p).month) {
		case 12:
			a = 6;
			break;
		case 11:
			a = 6;
			break;
		case 10:
			a = 5;
			break;
		case 9:
			a = 5;
			break;
		case 8:
			a = 4;
			break;
		case 7:
			a = 3;
			break;
		case 6:
			a = 3;
			break;
		case 5:
			a = 2;
			break;
		case 4:
			a = 2;
			break;
		case 3:
			a = 1;
			break;
		case 2:
			a = 1;
			break;
		case 1:
			a = 0;
			break;
	}
	return a;
}