#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//声明函数
int dis(int hp1, int hp2);
void homepage();
void detail();
void play();
void choice();
void egg_2(int);
int uplock(int hp);
int lwlock(int hp);
//变量声明
int hp1, hp2, x, y, egg1, egg2, r, choice1, endchoice;
int a1, c1; //定义玩家技能，攻击恢复
int a2, b2, c2; //定义电脑技能，攻击恢复
int main() {
	//数据设定
	hp1 = hp2 = 100; //血量100
	a1 = 20; //玩家攻击伤害
	a2 = 25; //电脑暴击伤害
	b2 = 15; //电脑攻击伤害
	c1 = 15;//玩家恢复HP
	c2 = 10; //电脑恢复HP
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

			printf("获胜条件：对方HP为0，你的HP不为0\n");
			goto homepage1;
		}
//彩蛋1
		default: {
			egg1 = egg1 + 1;
			if (egg1 >= 5) {
				printf("恭喜你，发现了彩蛋！\n");
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
		printf("别这样，赶紧选择！！！\n");
	if (egg2 == 2)
		printf("你玩不玩？\n");
	if (egg2 == 5)
		printf("快点！我等不及了！\n");
	if (egg2 == 7)
		printf("行了，给你彩蛋，赶紧玩！\n");
	if (egg2 == 8)
		printf("最后一遍，玩不玩？\n");
	if (egg2 == 9) {
		printf("你tm不用玩了！\n");
		exit(0);
	}
}

void choice() {
	//选择是否再来一局
	egg2 = 0;
	printf("想再来一局吗？\n输入1再来一局，输入2结束游戏\n");
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

//游戏主页
void homepage() {
	printf("**************************\n");
	printf("*****欢迎来到策略游戏*****\n");
	printf("**************************\n");
	printf("*按1开始游戏**按2游戏详情*\n");
	printf("**************************\n");
	printf("******按3查看游戏规则*****\n");
	printf("**************************\n");
}

//关于游戏
void detail() {
	printf("开发者ChenAo   版本号V1.0.0.1    发布时间：2021.11.23\n");
	printf("版本新增\n1.优化程序，采用模块化设计\n2.优化获取随机数\n");
}

//判别输赢
int dis(int hp1, int hp2) {
	if (hp1 <= 0 && hp2 <= 0)
		printf("平局\n");
	else if (hp1 <= 0)
		printf("你输了\n");
	else if (hp2 <= 0)
		printf("你赢了\n");
	choice();
}

//游戏本体
void play() {
	printf("输入数字1为攻击%d点，输入数字2为恢复HP%d点\n", a1, c1);
	printf("注意：请不要输入其他数字，输入后请按回车\n");
	r = 0; //初始化回合数
	hp1 = hp2 = 100; //初始化HP
//游戏主程序
	while (hp1 > 0 && hp2 > 0) {
		r++;
//玩家部分
		scanf("%d", &y);
		switch (y) {
//玩家攻击伤害
			case 1: {
				hp2 -= a1;
				hp2 = lwlock(hp2);
				printf("**第%d回合**\n", r);
				printf("你对方对你造成%d点伤害，你的HP为%d，对方HP为%d\n", a1, hp1, hp2);
				break;
			}
//玩家恢复HP
			case 2: {
				hp1 += c1;
				hp1 = uplock(hp1);
				printf("**第%d回合**\n", r);
				printf("你恢复%d点HP，你的HP为%d，对方HP为%d\n", c1, hp1, hp2);
				break;
				default:
					printf("输入错误，本次默认无行动\n");
				}

		}

//电脑部分
//取随机数
		srand(time(NULL));
		x = rand() % 100;

//电脑暴击伤害
		if (x >= 55) {
			hp1 -= a2;
			hp1 = lwlock(hp1);
			printf("暴击！！对方对你造成%d点伤害，你的HP为%d，对方HP为%d\n", a2, hp1, hp2);
		}
//电脑攻击伤害
		else if (x < 55 && x >= 20) {
			hp1 -= b2;
			hp1 = lwlock(hp1);
			printf("对方对你造成%d点伤害，你的HP为%d，对方HP为%d\n", b2, hp1, hp2);
		}
//电脑恢复HP
		else if (x < 20) {
			hp2 += c2;
			hp2 = uplock(hp2);
			printf("对方恢复%d点HP，你的HP为%d，对方HP为%d\n", c2, hp1, hp2);
		}
	}
	dis(hp1, hp2);//判定输赢
}

//锁血上限
int uplock(int hp) {
	if (hp > 100)
		hp = 100;
	return hp;
}

//锁血下限
int lwlock(int hp) {
	if (hp < 0)
		hp = 0;
	return hp;
}