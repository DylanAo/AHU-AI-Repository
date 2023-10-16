#include <stdio.h>
void Bsort(int *a, int n){
    int length = n - 1, j = 0, flag = 1;
    while (flag && length > 0){
        flag = 0;
        for (j = 1; j <= length; j++){
            if(a[j] > a[j+1]){
                flag = 1;
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
        length--;
    }
}

int main(){
    int i = 0;
    int a[8] = {0,13,25,12,14,16,14,90};
    Bsort(a, 7);
    for (i = 1;i <= 7; i++){
        printf("%d ",a[i]);
    }
}