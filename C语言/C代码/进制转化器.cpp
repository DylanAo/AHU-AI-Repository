#include <stdio.h>
#include <stdlib.h>
//By ChenAo
int main() {
	int choose;
	//Home Page
	printf("**********��ӭʹ�ý���ת����***********\n");
	printf("***************************************\n");
	printf("*10ת8*10ת16*8ת10*16ת10*8ת16*16ת8*\n");
	printf("***************************************\n");
	printf("**��1***��2****��3****��4***��5***��6**\n");
	printf("***************************************\n");
	scanf("%d", &choose);
	switch (choose) {
		case 1: {
			//10 to 8
			int a;
			printf("������һ��ʮ��������");
			scanf("%d", &a);
			printf("�˽���Ϊ%o\n", a);
			break;
		}
		case 2: {
			//10 to 16
			int b;
			printf("������һ��ʮ��������");
			scanf("%d", &b);
			printf("ʮ������Ϊ%x\n", b);
			break;

		}
		case 3: {
			//8 to 10
			int c;
			printf("������һ���˽�������");
			scanf("%o", &c);
			printf("�˽���Ϊ%d\n", c);
			break;

		}
		case 4: {
			//16 to 10
			int d;
			printf("������һ��ʮ����������");
			scanf("%x", &d);
			printf("ʮ����Ϊ%d\n", d);
			break;
		}
		case 5: {
			//8 to 16
			int e;
			printf("������һ���˽�������");
			scanf("%o", &e);
			printf("ʮ������Ϊ%x\n", e);
			break;
		}
		case 6: {
			//16 to 8
			int f;
			printf("������һ��ʮ����������");
			scanf("%x", &f);
			printf("�˽���Ϊ%o\n", f);
			break;
		}


	}
	system("pause");
	return 0;

}