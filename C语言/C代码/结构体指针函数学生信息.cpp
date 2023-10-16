#include <stdio.h>

void input(struct student *);
void print(struct student *);
struct student {
	int num;
	char name[20];
	float socre[3];
} stu[5];

int main() {
	struct student *p;
	for (p = stu; p < stu + 5; p++)
		input (p);
	for (p = stu; p < stu + 5; p++)
		print(p);
}

void input(struct student *p) {
	scanf("%d", &(*p).num);
	scanf("%s", &(*p).name);
	scanf("%f", &(*p).socre[0]);
	scanf("%f", &(*p).socre[1]);
	scanf("%f", &(*p).socre[2]);
}

void print(struct student *p) {
	printf("%d ", (*p).num);
	printf("%s ", (*p).name);
	printf("%3.1f ", (*p).socre[0]);
	printf("%3.1f ", (*p).socre[1]);
	printf("%3.1f\n", (*p).socre[2]);
}