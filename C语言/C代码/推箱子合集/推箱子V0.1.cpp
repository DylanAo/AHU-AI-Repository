#include <stdio.h>
#include <windows.h>
void move_switch(char);
void move_up (int (*p)[10]);
void move_down (int (*p)[10]);
void move_left (int (*p)[10]);
void move_right (int (*p)[10]);
void print(int (*p)[10]);

int player_x = 2, player_y = 3;
int a[10][10] = {0};

int main() {
	a[2][3] = 1;
	a[4][5] = 3;
	a[9][9] = 5;
	print(a);
	char ch, enter;
	while (a[9][9] != 3) {
		ch = getchar();
		enter = getchar();//消化回车
		move_switch(ch);
		system("cls");
		print(a);
	}
	printf("恭喜你，把箱子推到终点了！");
}

void print(int (*p)[10]) {
	int i, i2;
	for (i = 0; i <= 9; i++) {
		for (i2 = 0; i2 <= 9; i2++)
			printf("%d ", *((*(p + i)) + i2));
		putchar('\n');
	}
}

void move_switch(char ch) {
	switch (ch) {
		case ('w'):
			move_up(a);
			break;
		case ('s'):
			move_down(a);
			break;
		case ('a'):
			move_left(a);
			break;
		case ('d'):
			move_right(a);
			break;
	}
}

void move_up(int (*p)[10]) {
	if (*(*(p + player_x - 1) + player_y) == 0 ) {
		*(*(p + player_x - 1) + player_y) = 1;
		*(*(p + player_x) + player_y) = 0;
		player_x--;
	}
	if (*(*(p + player_x - 1) + player_y) == 3 ) {
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
	}
	if (*(*(p + player_x + 1) + player_y) == 3 ) {
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
	}
	if (*(*(p + player_x ) + player_y - 1) == 3 ) {
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
	}
	if (*(*(p + player_x ) + player_y + 1) == 3 ) {
		*(*(p + player_x ) + player_y + 1) = 1;
		*(*(p + player_x ) + player_y + 2) = 3;
		*(*(p + player_x) + player_y) = 0;
		player_y++;
	}
}