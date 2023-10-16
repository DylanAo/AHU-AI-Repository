#include <stdio.h> 
#include<stdlib.h>
#include <limits.h> 
#include <time.h>
#include<windows.h>//高精度计时器

// 定义矩阵数量
#define N 100

// 求解矩阵连乘
int MatrixChainOrder(int p[], int n) { 
    int m[N][N];
    int i, l, j, k, q;

    for (i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    for (l = 2; l <= n; l++) { 
        for (i = 1; i <= n - l + 1; i++) { 
            j = i + l - 1; 
            m[i][j] = INT_MAX; 
            for (k = i; k <= j - 1; k++) { 
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]; 
                if (q < m[i][j]) { 
                    m[i][j] = q; 
                } 
            } 
        } 
    } 
    return m[1][n]; 
} 

int main() { 
    int i;
    int matr[N]; // 存储矩阵的阶数
    int n = N - 1; // 矩阵数量为 N-1

    // 随机生成 N 个矩阵的阶数
    srand((unsigned)time(NULL));
    for(i=0;i<N;i++) {
        matr[i] = rand()%100 + 1;
    }

    LARGE_INTEGER t1,t2,tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);
    
    printf("Minimum number of multiplications is %d\n", MatrixChainOrder(matr, n));

    QueryPerformanceCounter(&t2);
    double time=(double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart; 

    // 输出运行时间
    printf("Running time is: %f ms\n",time);

    return 0; 
}
