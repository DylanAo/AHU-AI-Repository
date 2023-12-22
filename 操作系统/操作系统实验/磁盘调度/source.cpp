#include <iostream>
#include <list>
#include <cmath>
#include <string>

#define MAX 65535
#define start 100

using namespace std;

list<int> l = {55, 58, 39, 18, 90, 160, 150, 38 ,184};
int setptr = start; //初始寻道位置

int main(){
    
    //函数声明
    void FCFS(list<int> l);
    void SSTP(list<int> l);

    FCFS(l);
    system("pause");
    cout << "============================================================" <<endl;

    setptr = start;
    SSTP(l);
    system("pause");
    return 0;
}
// 先来先服务
void FCFS(list<int> l){

    list<int>::iterator iter; //迭代器
    int sum = 0;
    for(iter = l.begin(); iter != l.end(); iter++){
        static int numptr = 1;
        int temp = abs(*iter - setptr);
        setptr = *iter;
        sum += temp;
        cout << "id: " << numptr << "\tdistance:" << temp << endl;
        numptr++;
    }
    cout << "average distance:" << (float)sum/l.size() << endl;
}
// 最短寻道时间
void SSTP(list<int> l){
    
    int sum = 0;
    int temp = 0; //作比较中间值
    list<int>::iterator iter; //迭代器
    list<int> t; // 中间操作列表

    for(iter = l.begin(); iter != l.end(); iter++){ // 用t代替l进行操作
        t.push_back(*iter);
    }
    
    int ptr=setptr;
    while(!t.empty()){
        static int numptr = 1; // 表定序号
        list<int>::iterator iter_t;
        iter_t = t.begin();
        temp = MAX;

        for(; iter_t != t.end(); iter_t++){
            if(temp > abs(*iter_t - setptr)){ // 更短寻道时间
                temp = abs(*iter_t - setptr);
                ptr = *iter_t;
            }
        }
        sum += temp;
        setptr = ptr;
        cout << "id: " << numptr << "\tposition: " << setptr << "\tdistance:" << temp << endl;
        numptr++;
        t.remove(setptr);
    }

}