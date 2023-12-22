#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define Process_Num 5
#define Source_Num 3

using namespace std;

bool Finish[Process_Num] = {0};
int Cpu[Source_Num] = {10, 5, 7}; // Cpu所有的资源总量
int MAX[Process_Num][Source_Num] = {{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}}; // 每个进程所需要的单项资源最大要求量
int Allocation[Process_Num][Source_Num] = {{0,1,0},{2,0,0},{3,2,0},{2,1,1},{0,0,2}}; // 已分配给各个进程对应资源的数量
int Need[Process_Num][Source_Num] = {0}; // 每个进程为保持完成仍需要的资源量
int Available[Source_Num] = {0}; // 当前环境下每个资源的保有量
int Work[Source_Num] = {0};
int Request[Source_Num]; // 请求向量

int main(){
    //函数声明
    void bankal();
    bool Safty_Check(queue<int>& q);
    void Init_Distribute();
    void viewer();
/*
// 如果使用自定义输入矩阵
    void Input_Arr(int A[]);

    cout << "plz input the source number of CPU: " << endl;
    for(int i = 0 ;i < Source_Num; i++){
        cin << Cpu[i];
    }
    cout << "plz input the Max Array(use space to sperate the number): " << endl;
    Input_Arr(MAX);
    cout << "plz input the Alloc Array(use space to sperate the number): " << endl;
    Input_Arr(Alloc);
*/
    // 银行家算法
    Init_Distribute(); // 初始化求Available_i
    viewer();
    system("pause");
    while(true){
        system("cls");
        cout << "1. REquest." << endl;
        cout << "2. Check safty." << endl;
        cout << "0. quit" << endl;
        while(true){
            int opt;
            cin >> opt;
            if(opt < 0 || opt > 2){
                cout << "input error, invaild operator number! " << endl;
                system("pause");
            }
            else{
                if (opt == 0) exit(0);
                else if( opt == 1){
                    viewer();
                    bankal();
                    system("pause");
                }
                else if (opt == 2){
                    
                    queue<int> q;
                    if (Safty_Check(q)){
						cout << "Safty" << endl;
						cout << "one of safty queue is: ";
						bool mark = false;
						while (q.size())
						{
							if (mark) cout << "->";
							cout << q.front();q.pop();
							mark = true;
						}
						cout << endl;
                    }
                    else{
                        cout << "unsafty now, maybe deathlock happened;";
                    }
                    system("pause");
                }
            }
            break;
        }
    }
    return 0;
}
void viewer(){
    cout << "MAX\tAlloc\tNeed\t" << endl;
    for(int i = 0; i < Process_Num; i++){
        for(int j = 0; j < Source_Num; j++){
            cout << MAX[i][j] <<'\0';
        }
        cout << '\t';
        for(int j = 0; j < Source_Num; j++){
            cout << Allocation[i][j] <<'\0';
        }
        cout << '\t';
        for(int j = 0; j < Source_Num; j++){
            cout << Need[i][j] <<'\0';
        }
        cout << endl;
    }
}

// 初始化分配
void Init_Distribute(){
    int* arr_sub(int A[], int B[]);
    int* arr_copy(int A[], int B[]);
    int temp[Source_Num];
    int temp_1[Source_Num];
    arr_copy(temp,  Cpu);
    
    for(int i = 0; i < Process_Num; i++){
        arr_copy(temp_1, MAX[i]);
        arr_sub(temp, Allocation[i]);
        arr_sub(temp_1, Allocation[i]);
        arr_copy(Need[i], temp_1);
    }
    arr_copy(Available, temp);
}
// 向量复制
int* arr_copy(int A[], int B[]){

    for(int i = 0; i < Source_Num; i++){
        A[i] = B[i];
    }
    return A;
}

// 打印当前数组
void Print_Arr(int A[Source_Num]){
    int size = Source_Num;
    for(int i; i < size; i++){
        cout << A[i] <<'\0';
    }
    cout << endl << "==============Print==Over==============" << endl;
}
bool Distribute_test(int Request[Source_Num],int Need[Source_Num]){
    bool flag = true;
    for(int i = 0; i < Source_Num; i++)
        if(Request[i] > Need[i]){
            flag = false;
        }
    return flag;
}
// 数组向量相减
int* arr_sub(int A[],int B[]){
    int length = Source_Num;
    for(int i = 0; i < length; i++){
        A[i] -= B[i];
    }
    return A;
}
// 比较Need和Work
bool cmp_NW(int k){
    bool flag = true;
    for(int i = 0; i < Source_Num; i++){
        if(Need[k][i] > Work[i]){
            flag = false;
            break;
        }
    }
    return flag;
}
// 安全性检测算法
bool Safty_Check(queue<int>& q){
    arr_copy(Work, Available);
    for(int i = 0; i < Process_Num; i++){
        Finish[i] = false;
    }
    for(int i = 0; i < Process_Num; i++){ // 判断是否所有的进程都能被分配
        bool flag = false;
        for(int k = 0; k < Process_Num; k++){
            if(!Finish[k] && cmp_NW(k)){ // 判断进程中能否找到一个满足下述条件的进程(跳过已经检查可以的进程)
                flag = true;
                q.push(k);
                for (int j = 0;j < Source_Num; j++){ // 当前检查进程可分配，置work+=alloc向量
		            Work[j] += Allocation[k][j];
	            }
	            Finish[k] = true;
                break;
            }
        }
        if (!flag) return false; // 一个能分配的都找不到，不安全
    }
    return true;
}
// 分配函数
void Alloc(int k){
    for(int i = 0; i < Source_Num; i++){
        Allocation[k][i] += Request[i];
        Need[k][i] -= Request[i];
        Available[i] -= Request[i];
    }
}
// 分配恢复
void REcover(int k){
    for(int i = 0; i < Source_Num; i++){
        Allocation[k][i] -= Request[i];
        Need[k][i] += Request[i];
        Available[i] += Request[i];
    }
}
void bankal(){
    int ID;
    cout << "input the ID of Process: " << endl;
    cin >> ID;
    cout << "input the source("<< Source_Num <<") of the process's request: " << endl;
    for (int i = 0; i < Source_Num; i++)
        cin >> Request[i];
    for(int i = 0; i < Source_Num; i++){
        if(Request[i] > Need[ID][i]){
            cout << "error, the number of Sources' request is larger than Need" << endl;
            return;
        }
        else if(Request[i] > Available[i]){
            cout << "The process can't get enough source. Keep waitting." << endl;
            return;
        }
    }
    Alloc(ID);
    queue<int> q;
    if(Safty_Check(q)){
        cout << "Alloc success" << endl;
        cout << "one of safty queue is: " ;
        bool mark = false; // 格式控制
        while(q.size()){
            if (mark) cout << "->";
            cout << q.front();
            q.pop();
            mark = true;
        }
        cout << endl;
    }
    else{
        cout << "can't alloc! " << endl;
        REcover(ID); // 无法分配，执行回复
    }
}
/*
void Input_Arr(int A[]){
    for(int i = 0; i < Process_Num; i++){
        cin >> A[0] >> A[1] >> A[2];
    }
}
*/