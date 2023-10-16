#include <stdio.h>
#define PI 3.1415926

//By ChenAo 2021.10.18
int main() {
	double a, b, c, d, e, r, h;
	printf("请输入圆的半径和圆柱高分别为");
	scanf("%lf %lf", &r, &h);
	a = 2 * PI * r;    //圆的周长
	b = PI * r * r;    //圆的面积
	c = 4 * PI * r * r; //球的体积
	d = 4 / 3.0  * PI * r * r * r; //球的表面积
	e = b * h;        //圆柱的体积
	printf("圆的周长为%5.2lf\n圆面积为%5.2lf\n", a, b);
	printf("球的体积为%5.2lf\n球的表面积为%5.2lf\n", c, d);
	printf("圆柱的体积为%5.2lf\n", e);
	return 0;
}