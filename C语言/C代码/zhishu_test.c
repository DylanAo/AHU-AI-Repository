#include <stdio.h>

int main(){
    int i = 0, k = 0;
    for(i = 2; i <= 100; i++){
        for(k = 2; k <=i/2; k++){
            if (i % k == 0) {
                break;
            }
        }
    if (k == i/2 + 1) {
        printf("%d是质数\n",i);
            }
    }
}