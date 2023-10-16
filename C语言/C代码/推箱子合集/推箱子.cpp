#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
void move_switch(char, int (*p)[10]);
void move_up (int (*p)[10]);
void move_down (int (*p)[10]);
void move_left (int (*p)[10]);
void move_right (int (*p)[10]);
void print(int (*p)[10]);
void title();
void map();

int player_x, player_y;
int box_x, box_y;
int ter_x, ter_y;
int obs1_x, obs1_y, obs2_x, obs2_y, obs3_x, obs3_y, obs4_x, obs4_y, obs5_x, obs5_y;
int a[10][10] = {0};

struct data {
	char name[10];
	int round;
} player;

int main() {
	title();
	map();
	print(a);
	printf("1是玩家,2是障碍物,3是箱子,5是终点,请把箱子推到5\n使用“awds”移动(小写),输入后请按回车\n");
	printf("如果发现没有1或3或5,请不要慌,请重开,毕竟概率是百分之9,我不想再写这种小概率情况了\n");
	char ch, str[100];

	while (a[ter_x][ter_y] != 3) {
		ch = getchar();
		gets(str);
		move_switch(ch, a);
		system("cls");
		print(a);
	}

	printf("恭喜你，推到终点了！\n");
	system("pause");
}

void title() {
	char title_1[] = {"* MOVE BOX *"};
	HWND hwnd = GetForegroundWindow();
	SetWindowTextA(hwnd, title_1);
}

void map() {
s:
	srand(time(NULL));
	player_x = rand() % 9;
	player_y = rand() % 9;
	box_x = rand() % 9;
	box_y = rand() % 9;
	ter_x = rand() % 9;
	ter_y = rand() % 9;
	obs1_x = rand() % 9;
	obs1_y = rand() % 9;
	obs2_x = rand() % 9;
	obs2_y = rand() % 9;
	obs3_x = rand() % 9;
	obs3_y = rand() % 9;
	obs4_x = rand() % 9;
	obs4_y = rand() % 9;
	obs5_x = rand() % 9;
	obs5_y = rand() % 9;

	if (box_x == 0 || box_x == 9 || box_y == 0 || box_y == 9)
		goto s;

	a[obs1_x][obs1_y] = 2;
	a[obs2_x][obs2_y] = 2;
	a[obs3_x][obs3_y] = 2;
	a[obs4_x][obs4_y] = 2;
	a[obs5_x][obs5_y] = 2;
	a[player_x][player_y] = 1;
	a[box_x][box_y] = 3;
	a[ter_x][ter_y] = 5;
	player.round = 0;
}

void print(int (*p)[10]) {
	int i, i2;

	for (i = 0; i <= 9; i++) {
		for (i2 = 0; i2 <= 9; i2++)
			printf("%d ", *((*(p + i)) + i2));

		putchar('\n');
	}
}

void move_switch(char ch, int (*p)[10]) {
	switch (ch) {
		case ('w'):
			if ((player_x - 1 < 0) || ((player_x - 2 < 0) && *(*(p + player_x - 1) + player_y) == 3))
				break;

			move_up(a);
			break;

		case ('s'):
			if ((player_x + 1 > 9) || ((player_x + 2 > 9) && *(*(p + player_x + 1) + player_y) == 3))
				break;

			move_down(a);
			break;

		case ('a'):
			if ((player_y - 1  < 0) || ((player_y - 2 < 0) && *(*(p + player_x) + player_y - 1) == 3))
				break;

			move_left(a);
			break;

		case ('d'):
			if ((player_y + 1 > 9) || ((player_y + 2 > 9) && *(*(p + player_x) + player_y + 1) == 3))
				break;

			move_right(a);
			break;
	}
}

void move_up(int (*p)[10]) {
	if (*(*(p + player_x - 1) + player_y) == 0 ) {
		*(*(p + player_x - 1) + player_y) = 1;
		*(*(p + player_x) + player_y) = 0;
		player_x--;
	} else if ((*(*(p + player_x - 1) + player_y) == 3 ) && (*(*(p + player_x - 2) + player_y) != 2 )) {
		*(*(p + player_x - 1) + player_y) = 1;
		*(*(p + player_x - 2) + player_y) = 3;
		*(*(p + player_x) + player_y) = 0;
		player_x--;
	}
}

void move_down(int (*p)[10]) {
	if (*(*(p + player_x + 1) + player_y) == 0 ) {
		*(*(p + player_x + 1) + player_y) = 1;
		*(*(p + player_x) + player_y) = 0;
		player_x++;
	} else if ((*(*(p + player_x + 1) + player_y) == 3 ) && (*(*(p + player_x + 2) + player_y) != 2 ) ) {
		*(*(p + player_x + 1) +	player_y) = 1;
		*(*(p + player_x + 2) + player_y) = 3;
		*(*(p + player_x) + player_y) = 0;
		player_x++;
	}
}

void move_left(int (*p)[10]) {
	if (*(*(p + player_x ) + player_y - 1) == 0 ) {
		*(*(p + player_x ) + player_y - 1) = 1;
		*(*(p + player_x) + player_y) = 0;
		player_y--;
	} else if ((*(*(p + player_x ) + player_y - 1) == 3 ) && (*(*(p + player_x) + player_y - 2) != 2 )) {
		*(*(p + player_x ) + player_y - 1) = 1;
		*(*(p + player_x ) + player_y - 2) = 3;
		*(*(p + player_x) + player_y) = 0;
		player_y--;
	}
}

void move_right(int (*p)[10]) {
	if (*(*(p + player_x ) + player_y + 1) == 0 ) {
		*(*(p + player_x ) + player_y + 1) = 1;
		*(*(p + player_x) + player_y) = 0;
		player_y++;
	} else if ((*(*(p + player_x ) + player_y + 1) == 3 ) && (*(*(p + player_x) + player_y + 2) != 2 )) {
		*(*(p + player_x ) + player_y + 1) = 1;
		*(*(p + player_x ) + player_y + 2) = 3;
		*(*(p + player_x) + player_y) = 0;
		player_y++;
	}
}