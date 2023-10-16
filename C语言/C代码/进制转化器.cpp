#include <stdio.h>
#include <stdlib.h>
//By ChenAo
int main() {
	int choose;
	//Home Page
	printf("**********欢迎使用进制转换器***********\n");
	printf("***************************************\n");
	printf("*10转8*10转16*8转10*16转10*8转16*16转8*\n");
	printf("***************************************\n");
	printf("**按1***按2****按3****按4***按5***按6**\n");
	printf("***************************************\n");
	scanf("%d", &choose);
	switch (choose) {
		case 1: {
			//10 to 8
			int a;
			printf("请输入一个十进制整数");
			scanf("%d", &a);
			printf("八进制为%o\n", a);
			break;
		}
		case 2: {
			//10 to 16
			int b;
			printf("请输入一个十进制整数");
			scanf("%d", &b);
			printf("十六进制为%x\n", b);
			break;

		}
		case 3: {
			//8 to 10
			int c;
			printf("请输入一个八进制整数");
			scanf("%o", &c);
			printf("八进制为%d\n", c);
			break;

		}
		case 4: {
			//16 to 10
			int d;
			printf("请输入一个十六进制整数");
			scanf("%x", &d);
			printf("十进制为%d\n", d);
			break;
		}
		case 5: {
			//8 to 16
			int e;
			printf("请输入一个八进制整数");
			scanf("%o", &e);
			printf("十六进制为%x\n", e);
			break;
		}
		case 6: {
			//16 to 8
			int f;
			printf("请输入一个十六进制整数");
			scanf("%x", &f);
			printf("八进制为%o\n", f);
			break;
		}


	}
	system("pause");
	return 0;

}