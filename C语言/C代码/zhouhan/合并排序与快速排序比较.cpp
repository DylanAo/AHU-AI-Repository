#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include <windows.h>//高精度计时器

#define numCount 252979//259868
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    //创建临时数组
    int L[n1], R[n2];

    //把数据分到两个子数组中
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    //合并两个子数组
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    //将剩余的元素复制到数组
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int mergemergeSort() {
    string fileName="addsort"; // 文件名
    srand(time(NULL)); // 初始化随机数种子

    ofstream outFile(fileName.c_str()); // 创建输出文件流

    if (!outFile) { // 判断是否创建成功
        cerr << "无法创建文件" << fileName << endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numCount; i++) {
        int randomNum = rand()%10000+1; // 生成一个1-10000范围内的随机数
        outFile << randomNum <<endl; // 将该随机数输入到文件中
    }

    outFile.close(); // 关闭输出文件流

    ifstream inFile(fileName.c_str());  // 创建输入文件流

    if (!inFile) { // 判断是否读取成功
        cerr << "无法读取文件" << fileName << endl;
        exit(EXIT_FAILURE);
    }

    int numArray[numCount];

    for (int i = 0; i < numCount; i++) {
        inFile >> numArray[i];
    }

    inFile.close(); //关闭输入文件流

    LARGE_INTEGER t1,t2,tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);
    
    mergeSort(numArray, 0, numCount - 1);

    QueryPerformanceCounter(&t2);
    double time=(double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart; 
    cout<<"mergesort time = "<<time<<" s"<<endl;  //输出时间（单位：ｓ）
    
    return 0;
}

// 交换函数
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// 快速排序函数
int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j <= right - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return i + 1;
}

void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pivot_index = partition(arr, left, right);
        quickSort(arr, left, pivot_index - 1);
        quickSort(arr, pivot_index + 1, right);
    }
}

int quickquickSort() {
    string fileName="addsort"; // 文件名
    srand(time(NULL)); // 初始化随机数种子

    ofstream outFile(fileName.c_str()); // 创建输出文件流

    if (!outFile) { // 判断是否创建成功
        cerr << "无法创建文件" << fileName << endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numCount; i++) {
        int randomNum = rand()%10000+1; // 生成一个1-10000范围内的随机数
        outFile << randomNum <<endl; // 将该随机数输入到文件中
    }

    outFile.close(); // 关闭输出文件流

    ifstream inFile(fileName.c_str());  // 创建输入文件流

    if (!inFile) { // 判断是否读取成功
        cerr << "无法读取文件" << fileName << endl;
        exit(EXIT_FAILURE);
    }

    int numArray[numCount];

    for (int i = 0; i < numCount; i++) {
        inFile >> numArray[i];
    }

    inFile.close(); //关闭输入文件流

    LARGE_INTEGER t1,t2,tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);
    
    quickSort(numArray, 0, numCount - 1);

    QueryPerformanceCounter(&t2);
    double time=(double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart; 
    cout<<"quicksort time = "<<time<<" s"<<endl;  //输出时间（单位：ｓ）

    return 0;
}

int main()
{
	mergemergeSort();
	quickquickSort();
}