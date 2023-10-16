#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXN 20
#define MAXC 500

int w[MAXN + 1], v[MAXN + 1];
int dp[MAXN + 1][MAXC + 1]; // 动态规划数组

int main() {
    srand(time(NULL)); // 随机数种子

    printf("物品重量: ");
    for (int i = 1; i <= MAXN; i++) {
        w[i] = rand() % 51; // 随机生成0-50的整数
        printf("%d ", w[i]);
    }
    printf("\n");

    printf("物品价值: ");
    for (int i = 1; i <= MAXN; i++) {
        v[i] = rand() % 31 + 10; // 随机生成10-40的整数
        printf("%d ", v[i]);
    }
    printf("\n");
    
    // 动态规划求解
    for (int i = 1; i <= MAXN; i++) {
        for (int j = 0; j <= MAXC; j++) {
            if (j < w[i]) { // 背包容量不足以装下第i个物品
                dp[i][j] = dp[i - 1][j];
            } else { // 可以选择装或不装第i个物品
                dp[i][j] = dp[i - 1][j];
                if (dp[i - 1][j - w[i]] + v[i] > dp[i][j]) { // 选择装第i个物品
                    dp[i][j] = dp[i - 1][j - w[i]] + v[i];
                }
            }
        }
    }

    // 输出最优解和方案
    printf("最优解：%d\n", dp[MAXN][MAXC]);

    printf("装包方案：\n");
    int j = MAXC;
    for (int i = MAXN; i >= 1; i--) {
        if (dp[i][j] != dp[i - 1][j]) { // 第i件物品被放入背包
            printf("物品 %d, 重量 %d, 价值 %d\n", i, w[i], v[i]);
            j -= w[i];
        }
    }

    return 0;
}