#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
	int i, j;
	int x = 5;
	int y = 10;
	char input;
	int isFire = 0;

	while (1) {
		system("cls");   // ��������

		if (isFire == 0) { // ����ɻ�����Ŀ���
			for (i = 0; i < x; i++)
				printf("\n");
		} else { // ����ɻ�����ļ�������
			for (i = 0; i < x; i++) {
				for (j = 0; j < y; j++)
					printf(" ");

				printf("  |\n");
			}

			isFire = 0;
		}

		// �������һ�����ӵķɻ�ͼ��
		for (j = 0; j < y; j++)
			printf(" ");

		printf("  *\n");

		for (j = 0; j < y; j++)
			printf(" ");

		printf("*****\n");

		for (j = 0; j < y; j++)
			printf(" ");

		printf(" * * \n");


		if (kbhit()) { // �ж��Ƿ�������
			input = getch();  // �����û��Ĳ�ͬ�������ƶ�����������س�

			if (input == 'a')
				y--;  // λ������

			if (input == 'd')
				y++;  // λ������

			if (input == 'w')
				x--;  // λ������

			if (input == 's')
				x++;  // λ������

			if (input == ' ')
				isFire = 1;
		}
	}
}
