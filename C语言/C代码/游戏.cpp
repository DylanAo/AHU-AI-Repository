#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//By ChenAO
int main() {
//��������
	int dis(int hp1, int hp2);
//�����趨
	int hp1, hp2, x, y, egg1, r, choice, endchoice;
	hp1 = hp2 = 100; //����Ѫ��100
	int a1, c1; //������Ҽ��ܣ������ָ�
	int a2, b2, c2; //������Լ��ܣ������ָ�
	a1 = 20; //��ҹ����˺�
	a2 = 25; //���Ա����˺�
	b2 = 15; //���Թ����˺�
	c1 = 15;//��һָ�HP
	c2 = 10; //���Իָ�HP
	egg1 = 0;
//��Ϸ��ҳ
homepage:
	printf("**************************\n");
	printf("*****��ӭ����������Ϸ*****\n");
	printf("**************************\n");
	printf("*��1��ʼ��Ϸ**��2��Ϸ����*\n");
	printf("**************************\n");
	printf("******��3�鿴��Ϸ����*****\n");
	printf("**************************\n");
homepage1:
	scanf("%d", &choice);
	switch (choice) {
		case 1:
			goto play;
		case 2:
			goto detail;
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
//������Ϸ
detail :
	printf("������ChenAo   �汾��V1.0.0.1    ����ʱ�䣺2021.11.23\n");
	printf("�汾����\n1.������\n2.�Ż���������\n3.���ӻغϲ���\n4.��Ӳʵ�\n");
	goto homepage1;
//��ʼ��Ϸ
play :
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
				if (hp2 < 0)//��Ѫ
					hp2 = 0;
				else ;
				printf("**��%d�غ�**\n", r);
				printf("��Է��������%d���˺������HPΪ%d���Է�HPΪ%d\n", a1, hp1, hp2);
				break;
			}
//��һָ�HP
			case 2: {
				hp1 += c1;
				if (hp1 > 100)//��Ѫ
					hp1 = 100;
				else ;
				printf("**��%d�غ�**\n", r);
				printf("��ָ�%d��HP�����HPΪ%d���Է�HPΪ%d\n", c1, hp1, hp2);
				break;
				default:
					printf("������󣬱���Ĭ�����ж�\n");
				}

		}

//���Բ���
//ȡ�����
		x = rand() % 100;

//���Ա����˺�
		if (x >= 55) {
			hp1 -= a2;
			if (hp1 < 0)//��Ѫ
				hp1 = 0;
			else ;
			printf("���������Է��������%d���˺������HPΪ%d���Է�HPΪ%d\n", a2, hp1, hp2);
		}
//���Թ����˺�
		else if (x < 55 && x >= 20) {
			hp1 -= b2;
			if (hp1 < 0)//��Ѫ
				hp1 = 0;
			else ;
			printf("�Է��������%d���˺������HPΪ%d���Է�HPΪ%d\n", b2, hp1, hp2);
		}
//���Իָ�HP
		else if (x < 20) {
			hp2 += c2;
			if (hp2 > 100) //��Ѫ
				hp2 = 100;
			else ;
			printf("�Է��ָ�%d��HP�����HPΪ%d���Է�HPΪ%d\n", c2, hp1, hp2);
		}
		dis(hp1, hp2);//�ж���Ӯ
	}
//ѡ���Ƿ�����һ��
	printf("������һ����\n����1����һ�֣�����2������Ϸ\n");
endchoice:
	scanf("%d", &endchoice);
	switch (endchoice) {
		case 1:
			goto play;
		case 2:
			goto end;
		default: {
			printf("���������Ͻ�ѡ�񣡣���\n");
			goto endchoice;
		}
	}
	system("pause");
end:
	return 0;
}

//�б���Ӯ
int dis(int hp1, int hp2) {
	if (hp1 <= 0 && hp2 <= 0)
		printf("ƽ��\n");
	else if (hp1 <= 0)
		printf("������\n");
	else if (hp2 <= 0)
		printf("��Ӯ��\n");
	else ;
}




