#include <stdio.h>
#define PI 3.1415926

//By ChenAo 2021.10.18
int main() {
	double a, b, c, d, e, r, h;
	printf("������Բ�İ뾶��Բ���߷ֱ�Ϊ");
	scanf("%lf %lf", &r, &h);
	a = 2 * PI * r;    //Բ���ܳ�
	b = PI * r * r;    //Բ�����
	c = 4 * PI * r * r; //������
	d = 4 / 3.0  * PI * r * r * r; //��ı����
	e = b * h;        //Բ�������
	printf("Բ���ܳ�Ϊ%5.2lf\nԲ���Ϊ%5.2lf\n", a, b);
	printf("������Ϊ%5.2lf\n��ı����Ϊ%5.2lf\n", c, d);
	printf("Բ�������Ϊ%5.2lf\n", e);
	return 0;
}