#include <stdio.h>

void Qsort(int *a,int low,int high){
    int k1 = low, k2 = high, middle = a[low];
    while (low < high){
        while (low < high && middle <= a[high]) high--;
        a[low] = a[high];
        while (low < high && middle >= a[low]) low++;
        a[high] = a[low];
    }
    a[low] = middle;
    if(k1 < low -1) Qsort(a, k1,low-1);
    if(high + 1 < k2) Qsort(a, high + 1, k2);
}


int main(){
    int i = 0;
    int a[8] = {0,13,25,12,14,16,14,90};
    Qsort(a, 1, 7);
    for (i = 1;i <= 7; i++){
        printf("%d ",a[i]);
    }
}