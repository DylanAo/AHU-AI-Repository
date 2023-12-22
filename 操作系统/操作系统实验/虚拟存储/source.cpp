#include <iostream>
#include <string>
#include <queue>
#include <stack>

#define JobNum 12
#define MemorySize 3

using namespace std;

int JobQueue[12] = {1, 3, 4, 1, 2, 5, 1, 4, 2, 1, 4, 5};

int main(){
    
    //函数声明
    void FIFO(queue<int> q);
    void LRU(queue<int> q);    
    // 预定义
    queue<int> q;
    cout << "The situlation in FIFO: " << endl;
    FIFO(q);
    system("pause");
    system("cls");

    cout << "The situlation in LRU: " << endl;
    LRU(q);
    system("pause");
    
    return 0;
}

// 检查是否需要调度(检查新页面是否已经装入在内存中)
bool check_FIFO(queue<int> q, int k){
    bool flag = true; // 默认需要调度
    int size = q.size();
    for(int i = 0; i < size; i++){
        int temp = q.front();
        q.push(temp);
        q.pop();
        if(temp == k){
            flag = false; // 内存存有该页面，无需调度
        }
    }
    return flag;
}
// 检索该元素是否该压入栈
bool check_LRU(stack<int> s, int k){
    bool flag = true;
    if(s.empty()) //栈为空
        return flag;
    stack<int> temp; //建立一个中间栈维护原始栈内元素
    while (!s.empty()){ // 检查该页面在栈内是否已经存在
        if(s.top() == k){
            flag = false;
        }
        int out;
        out = s.top();
        temp.push(out);
        s.pop();
    }
    while(!temp.empty()){//将属于栈内的元素压回
        int in;
        in = temp.top();
        temp.pop();
        s.push(in);
    }
    return flag;
}
// 先入先出调度
void FIFO(queue<int> q){
    for(int i = 0; i < JobNum; i++) //建立一个队列将作业预先存入
        q.push(JobQueue[i]);

    queue<int> m; // 定义内存队列
    while(!(q.empty()) || !(m.empty())){
        if(m.size() < MemorySize){ //内存队列仍有空间
            m.push(q.front()); // 调度作业入队
            cout << "in: " << q.front() << endl;
            q.pop();
            continue;
        }
        if(q.empty()) // 如果后备队列已空，针对该问题的调度已经结束了
            break;
        if(check_FIFO(m , q.front())){
            cout << "out:\0" << m.front();
            cout << "\tin:\0" << q.front() << endl;
            m.pop();
            m.push(q.front());
        }
        q.pop(); // 检查下一个页面
    }
}
// LRU调度算法
void LRU(queue<int> q){
    for(int i = 0; i < JobNum; i++) //建立一个队列将作业预先存入
        q.push(JobQueue[i]);
    queue<int> m; // 定义内存队列
    
    static int count = -1; // 定位伪指针
    while(!(q.empty()) || !(m.empty())){
        if(m.size() < MemorySize){ //内存队列仍有空间
            m.push(q.front()); // 调度作业入队
            cout << "in: " << q.front() << endl;
            q.pop();
            count++;
            continue;
        }
        if(q.empty()) // 如果后备队列已空，针对该问题的调度已经结束了
            break;
        int temp = count;
        if(check_FIFO(m , q.front())){
            cout << "in:\0" << q.front();
            stack<int> s; //建栈用于查找需要调入的页面
            while(s.size() < MemorySize){ // 栈未压满
                if(check_LRU(s, JobQueue[temp])){ // 满足不重复压栈
                    s.push(JobQueue[temp]);
                }
                temp--; // 往回检索遍历temp--
            }
            cout << "\tout:\0" << s.top() << endl; //栈顶即为最近最久未使用的页面
            int temp_pop = s.top();
            for(int j = 0; j < MemorySize; j++){
                if(temp_pop == m.front()){
                    m.pop();
                    m.push(q.front());
                }else{
                    m.push(m.front());
                    m.pop();
                }
            }
        }
        count++;
        q.pop(); // 检查下一个页面
    }
}