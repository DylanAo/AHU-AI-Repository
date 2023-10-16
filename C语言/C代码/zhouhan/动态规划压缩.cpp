#include <stdio.h>
#include <stdlib.h>

#define INF 0x3f3f3f3f // 无穷大

int prefix_sum[100]; // 前缀和数组，用于快速计算cost
int f[100];         // 记录状态的最优解
int pre[100];       // 记录每个状态的决策
int n;              // 序列的长度
int ans;            // 最小解

// 获得将区间 [l, r] 合并为一个数所需的最小位数
int get_cost(int l, int r)
{
    int sum = prefix_sum[r] - prefix_sum[l - 1];
    int cnt = 0;
    while (sum) {
        sum >>= 1;
        cnt++;
    }
    return cnt;
}

// 递归回溯，输出最优决策
void print_segment(int i)
{
    if (i == 0) {
        return;
    }
    int j = pre[i];
    printf("(%d,%d) ", j + 1, i);
    print_segment(j);
}

int main()
{
    int a[] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, 31, 30, 29, 28, 127, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 232, 221, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 236};
    n = sizeof(a) / sizeof(a[0]);

    prefix_sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i - 1];
    }

    // 初始化
    f[0] = 0;

    // 动态规划
    for (int i = 1; i <= n; i++) {
        f[i] = INF; // 初始化为无穷大
        for (int j = 0; j < i; j++) {
            int cost = get_cost(j + 1, i);
            if (f[j] != INF && f[j] + cost < f[i]) {
                f[i] = f[j] + cost;
                pre[i] = j;
            }
        }
    }

    ans = f[n]; // 最小解

    // 输出结果
    printf("最小比特位数为：%d\n", ans);
    printf("分段方案为：");
    print_segment(n);
    printf("\n");

    return 0;
}