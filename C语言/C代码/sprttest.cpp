#include <stdio.h>
void Sort(int* a, int n)
// direct insert sorting
{
    int i, k;

    for (i=1; i<n; i++)   {
        // 请在此添加代码，补全函数DirecInsSort
        /********** Begin *********/
        //太好了，最后一次作业了
        int j = 0;
        if(a[i] < a[i - 1]){
            k = a[i];
            for(j = i; k < a[j - 1] ; j--){
                a[j] = a[j - 1];
            }
            a[j] = k;
        }

        /********** End **********/
    }
}

void SortPrint(int* a, int n)
{
    int i;
    printf("sort result:");
    for (i=0; i<n; i++)
        printf("%d ", a[i]);
    //printf("\n");
}

int main(){
    int a[8] = {89,8,76,4,56,9,55,4};
    Sort( a , 8);
    SortPrint(a ,8);
}