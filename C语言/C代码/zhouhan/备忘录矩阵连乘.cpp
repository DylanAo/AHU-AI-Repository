#include<stdio.h> 
#include<stdlib.h> 
#include<limits.h>
#include<time.h>
#include<windows.h>//高精度计时器

// 定义矩阵数量
#define N 100

// 查找最优解并存储在备忘录中
int LookupChain(int m[][N], int p[], int i, int j) { 
    if (m[i][j] < INT_MAX) {
        return m[i][j]; 
    } 

    if (i == j) {
        m[i][j] = 0; 
    } else { 
        int k; 
        for (k = i; k <= j-1; k++) { 
            int q = LookupChain(m, p, i, k) + LookupChain(m, p, k+1, j) + p[i-1]*p[k]*p[j]; 
            if (q < m[i][j]) { 
                m[i][j] = q; 
            } 
        } 
    } 
    
    return m[i][j]; 
} 
// 备忘录法求解矩阵连乘的最小代价
int MemoizedMatrixChain(int p[], int n, int m[][N]) { 
    int i, j; 

    for (i = 1; i <= n; i++) {
        for (j = i; j <= n; j++) {
            m[i][j] = INT_MAX;
        }
    }

    return LookupChain(m, p, 1, n); 
}



int main() { 
    int i;
    int matr[N]; // 存储矩阵的阶数
    int n = N - 1; // 矩阵数量为 N-1

    // 随机生成 10000 个矩阵的阶数
    srand((unsigned)time(NULL));
    for(i=0;i<N;i++) {
        matr[i] = rand()%100 + 1;
    }

    int m[N][N]; 
    
    LARGE_INTEGER t1,t2,tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);
    
    printf("Minimum number of multiplications is %d\n", MemoizedMatrixChain(matr, n, m)); 

    QueryPerformanceCounter(&t2);
    double time=(double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart; 

    // 输出运行时间
    printf("Running time is: %f s\n",time);

    return 0; 
} 
