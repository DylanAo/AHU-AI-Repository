#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 100
#define CAPACITY 500

int weights[N];
int values[N];
int maxProfit = 0;
int bestSolution[N];

void backtrack(int currentWeight, int currentValue, int currentIndex) {
    if (currentIndex == N) {
        if (currentWeight <= CAPACITY && currentValue > maxProfit) {
            maxProfit = currentValue;
            for (int i = 0; i < N; i++) {
                bestSolution[i] = values[i];
            }
        }
        return;
    }

    // 不选择当前物品
    backtrack(currentWeight, currentValue, currentIndex + 1);

    // 选择当前物品
    int weight = weights[currentIndex];
    int value = values[currentIndex];
    if (currentWeight + weight <= CAPACITY) {
        currentValue += value;
        currentWeight += weight;
        backtrack(currentWeight, currentValue, currentIndex + 1);
        currentValue -= value;
        currentWeight -= weight;
    }
}

int main() {
    srand(time(NULL));
  
    // 生成物品的重量和价值
    for (int i = 0; i < N; i++) {
        int weight = rand() % 246 + 10;
        weights[i] = weight;

        int random = rand() % 8 + 1;
        int valueOption = rand() % 2;
        switch (valueOption) {
            case 0: // 重量加上1-8的某个随机数
                values[i] = weight + random;
                break;
            case 1: // 重量减去1-8的某个随机数
                values[i] = weight - random;
                break;
        }
    }

    backtrack(0, 0, 0);


    printf("All items:\n");
    for (int i = 0; i < N; i++) {
        if (bestSolution[i]) {
            printf("Item %d - Weight: %d, Value: %d\n", i + 1, weights[i], bestSolution[i]);
        }
    }
    printf("Total weight: %d\n", CAPACITY);
    printf("Maximum value: %d\n", maxProfit);
    return 0;
}