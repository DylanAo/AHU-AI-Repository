#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void hanoi(int n, char a, char b, char c)
{
    if (n == 1) {
        printf("%c --> %c\n", a, c);
        return;
    }
    hanoi(n - 1, a, c, b);
    printf("%c --> %c\n", a, c);
    hanoi(n - 1, b, a, c);
}
int main()
{
    int n;
	printf("please input the plies:");
	scanf("%d",&n);
    //n = rand() % 10 + 1;
    printf("汉诺塔层数：%d\n", n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}