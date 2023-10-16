#include <stdio.h>
void Isort(int *a, int n){
    int i = 2, j = 0;
    for(i = 2;i <= n; i++){
        if(a[i] < a[i - 1]){
            a[0] = a[i];
            for (j = i -1;a[0] < a[j]; j--){
                a[j + 1] = a[j];
            }
            a[j + 1] = a[0];
        }
    }
}
int main(){
    int i = 0;
    int a[8] = {0,13,25,12,14,16,14,90};
    Isort(a, 7);
    for (i = 1;i <= 7; i++){
        printf("%d ",a[i]);
    }
}