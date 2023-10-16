#include <stdio.h>

//By ChenAo 2021.10.27
int main() {
	int f, s, t, i; //first,second,third,i
	for (i = 100, f = s = t = 0; i <= 999; i++)
//注意看啊，下面我要开大了
	{
		f = i % 10; //取余算出第一位
		t = i - f; //t变成三位数，以0结尾，可以被10整除
		t /= 10; //t变成两位数,记住这个t变量，一会要考的
		s = t % 10; //取余，s为第二位
		t -= s; //t知识点来了，t两位数，以0结尾，可以被10整除
		t /= 10; //t变成一位数，为第三位
		if (i != f * f * f + s * s * s + t * t * t)//水仙花数判断
			continue;
		else
			printf("%d ", i);//细节，这里带空格的
	}
}
//够简洁吧
//不愧是我，才能想出来如此绝妙方法
