#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//��������
int dis(int hp1, int hp2);
void homepage();
void detail();
void play();
void choice();
void egg_2(int);
int uplock(int hp);
int lwlock(int hp);
//��������
int hp1, hp2, x, y, egg1, egg2, r, choice1, endchoice;
int a1, c1; //������Ҽ��ܣ������ָ�
int a2, b2, c2; //������Լ��ܣ������ָ�
int main() {
	//�����趨
	hp1 = hp2 = 100; //Ѫ��100
	a1 = 20; //��ҹ����˺�
	a2 = 25; //���Ա����˺�
	b2 = 15; //���Թ����˺�
	c1 = 15;//��һָ�HP
	c2 = 10; //���Իָ�HP
	egg1 = 0;
	homepage();
homepage1:
	scanf("%d", &choice1);
	switch (choice1) {
		case 1:
			play();

		case 2:
			detail();
			goto homepage1;
		case 3: {

			printf("��ʤ�������Է�HPΪ0�����HP��Ϊ0\n");
			goto homepage1;
		}
//�ʵ�1
		default: {
			egg1 = egg1 + 1;
			if (egg1 >= 5) {
				printf("��ϲ�㣬�����˲ʵ���\n");
				goto homepage1;

			} else
				goto homepage1;


		}
	}
	system("pause");
	return 0;
}

void egg_2(int egg2) {
	if (egg2 == 1)
		printf("���������Ͻ�ѡ�񣡣���\n");
	if (egg2 == 2)
		printf("���治�棿\n");
	if (egg2 == 5)
		printf("��㣡�ҵȲ����ˣ�\n");
	if (egg2 == 7)
		printf("���ˣ�����ʵ����Ͻ��棡\n");
	if (egg2 == 8)
		printf("���һ�飬�治�棿\n");
	if (egg2 == 9) {
		printf("��tm�������ˣ�\n");
		exit(0);
	}
}

void choice() {
	//ѡ���Ƿ�����һ��
	egg2 = 0;
	printf("������һ����\n����1����һ�֣�����2������Ϸ\n");
endchoice:
	scanf("%d", &endchoice);
	switch (endchoice) {
		case 1:
			play();
		case 2:
			exit(0);
		default: {
			egg2++;
			egg_2(egg2);
			goto endchoice;
		}
	}
}

//��Ϸ��ҳ
void homepage() {
	printf("**************************\n");
	printf("*****��ӭ����������Ϸ*****\n");
	printf("**************************\n");
	printf("*��1��ʼ��Ϸ**��2��Ϸ����*\n");
	printf("**************************\n");
	printf("******��3�鿴��Ϸ����*****\n");
	printf("**************************\n");
}

//������Ϸ
void detail() {
	printf("������ChenAo   �汾��V1.0.0.1    ����ʱ�䣺2021.11.23\n");
	printf("�汾����\n1.�Ż����򣬲���ģ�黯���\n2.�Ż���ȡ�����\n");
}

//�б���Ӯ
int dis(int hp1, int hp2) {
	if (hp1 <= 0 && hp2 <= 0)
		printf("ƽ��\n");
	else if (hp1 <= 0)
		printf("������\n");
	else if (hp2 <= 0)
		printf("��Ӯ��\n");
	choice();
}

//��Ϸ����
void play() {
	printf("��������1Ϊ����%d�㣬��������2Ϊ�ָ�HP%d��\n", a1, c1);
	printf("ע�⣺�벻Ҫ�����������֣�������밴�س�\n");
	r = 0; //��ʼ���غ���
	hp1 = hp2 = 100; //��ʼ��HP
//��Ϸ������
	while (hp1 > 0 && hp2 > 0) {
		r++;
//��Ҳ���
		scanf("%d", &y);
		switch (y) {
//��ҹ����˺�
			case 1: {
				hp2 -= a1;
				hp2 = lwlock(hp2);
				printf("**��%d�غ�**\n", r);
				printf("��Է��������%d���˺������HPΪ%d���Է�HPΪ%d\n", a1, hp1, hp2);
				break;
			}
//��һָ�HP
			case 2: {
				hp1 += c1;
				hp1 = uplock(hp1);
				printf("**��%d�غ�**\n", r);
				printf("��ָ�%d��HP�����HPΪ%d���Է�HPΪ%d\n", c1, hp1, hp2);
				break;
				default:
					printf("������󣬱���Ĭ�����ж�\n");
				}

		}

//���Բ���
//ȡ�����
		srand(time(NULL));
		x = rand() % 100;

//���Ա����˺�
		if (x >= 55) {
			hp1 -= a2;
			hp1 = lwlock(hp1);
			printf("���������Է��������%d���˺������HPΪ%d���Է�HPΪ%d\n", a2, hp1, hp2);
		}
//���Թ����˺�
		else if (x < 55 && x >= 20) {
			hp1 -= b2;
			hp1 = lwlock(hp1);
			printf("�Է��������%d���˺������HPΪ%d���Է�HPΪ%d\n", b2, hp1, hp2);
		}
//���Իָ�HP
		else if (x < 20) {
			hp2 += c2;
			hp2 = uplock(hp2);
			printf("�Է��ָ�%d��HP�����HPΪ%d���Է�HPΪ%d\n", c2, hp1, hp2);
		}
	}
	dis(hp1, hp2);//�ж���Ӯ
}

//��Ѫ����
int uplock(int hp) {
	if (hp > 100)
		hp = 100;
	return hp;
}

//��Ѫ����
int lwlock(int hp) {
	if (hp < 0)
		hp = 0;
	return hp;
}