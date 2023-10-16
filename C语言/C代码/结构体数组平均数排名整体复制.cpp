#include <stdio.h>
#include <string.h>

struct student {
	char name;
	int socre[3];
	int ave;
} stu[3], t;

int main() {
	int sum = 0;

	for (int i = 0; i <= 2; i++) {
		scanf("%s", stu[i].name);

		for (int j = 0; j <= 2; j++)
			scanf("%d", stu[i].socre[j]);
	}

	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++)
			sum += stu[i].socre[j];

		stu[i].ave = sum / 3;
	}

	for (int i = 1; i <= 2; i++)
		for (int j = 0; j <= 3 - i; j++) {
			if (stu[j].ave < stu[j + 1].ave) {
				memcpy(t, stu[j], sizeof(student), 20);
				memcpy(stu[j], stu[j + 1]);
				memcpy(stu[j + 1], t);
			}
		}

	for (int i = 0; i <= 2; i++)
		printf("%s", stu[i].name);

}