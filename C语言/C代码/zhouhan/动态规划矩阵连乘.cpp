#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>//高精度计时器

// 定义矩阵数量 (MAX:2400-2600)
#define N 100

int m[N][N];

// 计算最小代价和最优解的位置
void MatrixChainOrder(int p[], int n) {
    int i, j, k, L, q;
    for(i=1; i<=n; i++) {
        m[i][i] = 0;
    }
    for(L=2; L<=n; L++) {
        for(i=1; i<=n-L+1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for(k=i; k<=j-1; k++) {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }
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
    LARGE_INTEGER a1,a2,a3;
    QueryPerformanceFrequency(&a3);
    QueryPerformanceCounter(&a1);
    
    MatrixChainOrder(matr, n);

    QueryPerformanceCounter(&a2);
    double time1=(double)(a2.QuadPart-a1.QuadPart)/(double)a3.QuadPart; 

    // 输出结果和运行时间
    printf("Minimum number of multiplications is: %d\n",m[1][n]);
    printf("Running time is: %f s\n",time1);
    return 0;
}
