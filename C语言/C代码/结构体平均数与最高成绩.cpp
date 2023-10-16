#include <stdio.h>

void input(struct student *);
void average (struct student *);
void nb_stu (struct student *);
struct student {
	int num;
	char name[20];
	float socre[3];
} stu[10];

int main() {
	struct student *p;
	for (p = stu; p < stu + 10; p++)
		input (p);
	average (stu);
	nb_stu(stu);
}

void input(struct student *p) {
	scanf("%d", &(*p).num);
	scanf("%s", &(*p).name);
	scanf("%f", &(*p).socre[0]);
	scanf("%f", &(*p).socre[1]);
	scanf("%f", &(*p).socre[2]);
}

void average (struct student *p) {
	int i, i2;
	float sum = 0;
	for (i = 0; i <= 2; i++) {
		for (i2 = 0; i2 <= 9; i2++)
			sum += (*(p + i2)).socre[i];
		printf("%5.2f\n", sum / 10.0);
	}
}

void nb_stu(struct student *p) {
	int i, i2;
	float max;
	struct student *a = p, *b = p;
	for (i = 0; i <= 2; i++) {
		p = a;
		max = (*p).socre [i];
		for (i2 = 0; i2 <= 8; i2++) {
			if ((*p).socre[i] < (*(p + 1)).socre[i]) {
				max = (*(p + 1)).socre[i];
				b = p + 1;
			}
		}
		printf ("%f %d %s\n", max, (*b).num, (*b).name);
	}
}