#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

//打印数组
void arry_print(int arry[8][8])
{
    int j = 0;
    int k = 0;
    for (j = 0; j < 8; j++)
    {
        for (k = 0; k < 8; k++)
        {
            printf("%2d", arry[j][k]);
        }
        printf("\n");
    }
}

//创建随机数组
void arry_create(int b[8][8])
{
    srand((unsigned)time(NULL));
    int a[64], i, j, k,m;
    do
    {
        m = 0;
        for (i = 0; i <= 63; i++)
        {
            a[i] = rand() % 2;
            if (a[i])
                m++;
        }
    } while (m != 20);
    int n = 0;
    for (j = 0; j < 8; j++)
    {
        for (k = 0; k < 8; k++)
        {
            b[j][k] = a[n];
            n++;
        }
    }
}

int main()
{
    /*int arry[8][8] = //这是测试数组
    {
        {1, 1, 1, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 1, 1, 0},
        {0, 0, 0, 1, 1, 1, 1, 1},
        {0, 1, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 0, 1, 1, 1},
        {0, 1, 0, 0, 1, 0, 0, 0},

    };*/
    int arry[8][8];
    int line = 0, row = 0;
    arry_create(arry);  //创建随机数组
    printf("随机生成的数组为：\n");
    arry_print(arry);  //打印随机数组
    //先查找每行有三个以上连着的
    //行查找简单，没限制，主要是因为没有2这个数存在
    for (line = 0; line <= 7; line++)  //每行都遍历
    {
        for (row = 1; row <= 6; row++)  //1到6列遍历(一共是0-7列)
        {
            if(arry[line][row])  //所遍历的格子有东西(!0)
            {
                if(arry[line][row - 1] + arry[line][row + 1] >= 2) //看这个格子左边和右边的格子，要么 1+1=2，要么2+1=3，要么2+0=2
                {
                    arry[line][row] = 2;
                      arry[line][row - 1] = 2;
                    if(arry[line][row + 1])  //右边格子为0不改，为1改
                    {
                        arry[line][row + 1] = 2;
                    }
                }
            }
        }
    }
     //再查找每列有三个以上连着的
    for (row = 0; row <= 7; row++)  //每列都遍历
    {
        for (line = 1; line <= 6; line++)  //1到6行遍历(一共是0-7行)
        {
            if(arry[line][row] && arry[line][row] != 2)  //所遍历的格子有东西(!0)
            {
                if(arry[line - 1][row] + arry[line + 1][row] >= 2) //看这个格子左边和右边的格子，要么 1+1=2，要么2+1=3，要么2+0=2
                {
                     if(arry[line - 1][row])  //上边格子为0不改，为1改
                    {
                        arry[line - 1][row] = 2;
                    }
                    if(arry[line + 1][row])  //下边格子为0不改，为1改
                    {
                        arry[line + 1][row] = 2;
                    }
                    if(arry[line - 1][row] && arry [line - 2][row] || arry[line + 1][row] && arry [line + 2][row])
                    {    // 上下连着两个都不是0,我才改本身的格子，适用于三个以上和该数字在头或尾
                        arry[line][row] = 2;
                    }
                    if(arry[line + 1][row] && arry [line - 1][row]) // 上下两个都是有数的(1或2),适用于该数字在三个中间
                    {
                        arry[line][row] = 2;
                    }
                    
                }
            }
        }
    }
    printf("后来数组\n");
    arry_print(arry);
    return 0;
}