#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

void longest_common_substring(char* a, char* b, char* res) {
    int len_a = strlen(a), len_b = strlen(b);
    int len_table[len_a+1][len_b+1]; // 存储LCS长度的二维数组
    memset(len_table, 0, sizeof(len_table)); // 初始化为0

    // 求解LCS长度
    int max_len = 0; // 最长公共子串的长度
    int end_index = 0; // 最长公共子串在a数组中结束位置的索引值
    for(int i=1; i<=len_a; i++) {
        for(int j=1; j<=len_b; j++) {
            if(a[i-1] == b[j-1]) {
                len_table[i][j] = len_table[i-1][j-1] + 1;
                if(len_table[i][j] > max_len) {
                    max_len = len_table[i][j];
                    end_index = i-1; //最终答案有可能在a和b中选一个都可以
                }
            }
        }
    }

    // 如果最长公共子串不存在，则返回空字符串
    if (max_len == 0) {
        res[0] = '\0';
        return;
    }
    
    // 根据最长公共子串的结束位置索引及长度，截取出最长公共子串并输出
    for(int i=0; i<max_len; i++) {
        res[i] = a[end_index-max_len+i+1];
    }
    res[max_len] = '\0';
}

int main() {
    // 生成两个长度为MAX_LEN的随机数字字母混合子串
    char a[MAX_LEN+1], b[MAX_LEN+1], lcs[MAX_LEN+1];
    for(int i=0; i<MAX_LEN; i++) {
        a[i] = rand()%26 + 'a'; // 随机生成a-z的某个字母
        b[i] = rand()%26 + 'a'; // 随机生成a-z的某个字母
    }
    a[MAX_LEN] = '\0';
    b[MAX_LEN] = '\0';

    // 输出子串a和b，并调用函数计算它们的最长公共子串
    printf("a: %s\n", a);
    printf("b: %s\n", b);
    longest_common_substring(a, b, lcs);
    printf("the lcs is: %s\n", lcs);
    return 0;
}
