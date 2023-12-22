#include "head.h"

#define Time_Release 0

using namespace std;


int timeline = 0; //设置整数模拟时间线
int finished[Size_Storge][3]={0}; //记录队列开始结束事件

// 模拟进程执行过程
int main(){
    //函数声明    
    void Init_ProcessQueue(LinkQueue& Q);
    void Init_MemoryQueue(LinkQueue& Q);
    void Init_PCB(LinkQueue& Q);
    void Queue_Print(LinkQueue Q);
    void FCFS_Queue(LinkQueue& Q, LinkQueue& M);
    void MemoryCall_FCFS(LinkQueue& Q, LinkQueue& M);
    void Queue_Sort_ArrivalTime(LinkQueue& Q);

    LinkQueue QueueJob; //声明作业队列
    LinkQueue QueueMemory; //声明内存队列
    
    int T[Size_Memory]={0}; //周转
    int Ts[Size_Memory]={0}; //带权周转
    int T_Aver = 0; //平均周转
    int Ts_Aver = 0; //平均带权周转

    /*
    为保证程序的简洁，做出以下约定
    仅设置一个阻塞队列，即在本题环境下，内存队列在本环境下与就绪队列等同，且第一个进程视为被执行
    约定，外存上存放的进程顺序即为进程的整个外存上用于存储进程被视为阻塞队列；
    仅设置一个就绪队列，即在本题环境下，先后到达顺序
    */

    // 初始化进程队列
    Init_ProcessQueue(QueueJob);
    Init_MemoryQueue(QueueMemory);
    
    for(int i = 0; i < Size_Storge; i++){
        Init_PCB(QueueJob);
        finished[i][2] = QueueJob.tail->data.service_time; //对应作业的实际执行时间
    }
    Queue_Print(QueueJob);
    system("pause");
    system("cls");

    Queue_Sort_ArrivalTime(QueueJob);
    Queue_Print(QueueJob);
    cout << "=====================Sort==Over=====================" << endl;
    system("pause");
    system("cls");
    // FCFS算法
    FCFS_Queue(QueueJob, QueueMemory);

    
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < Size_Storge; i++){
        sum1 += finished[i][1];
        sum2 += finished[i][1]/(finished[i][1]-finished[i][0]);
        cout << "PID: "<< i << "\tArrival_time: " << finished[i][0] << "\tFinished_time: " << finished[i][1]
             << "\tTurnover time: " << finished[i][1] << "\tWeight_Turnover time: " << (float)finished[i][1]/(finished[i][1]-finished[i][0]) << endl;
    }
    cout << "Turnover time_Average: " << (float)sum1/Size_Storge << "\tWeight_Turnover time_Acerage: " << (float)sum2/Size_Storge <<endl;

    cout << "===============================" << endl;

    system("pause");
    return 0;
}

// 初始化外存上的进程队列
void Init_ProcessQueue(LinkQueue& Q){
    Q.head = Q.tail = (node*)malloc(sizeof(node));
    Q.head->next = Q.tail->next = NULL;
    Q.head->data.fin = false;
    Q.head->data.job_id = MAX; //第一个空节点不可访问
    Q.head->data.next = NULL;
    Q.head->data.prior = 0;
    Q.head->data.service_time=0;
    Q.head->data.arrival_time=0;
    Q.head->data.stat = 1;
    Q.count = 0;
}
// 初始化内存队列
void Init_MemoryQueue(LinkQueue& Q) {
    Q.head = Q.tail = (node*)malloc(sizeof(node));
    Q.head->next = Q.tail->next = NULL;
    Q.head->data.fin = false;
    Q.head->data.job_id = MAX; //第一个空节点不可访问
    Q.head->data.next = NULL;
    Q.head->data.prior = 0;
    Q.head->data.service_time=0;
    Q.head->data.arrival_time=0;
    Q.head->data.stat = 1;
    Q.count = 0;
}
// 初始化随机生成1个PCB并插入到就绪队列中
void Init_PCB(LinkQueue& Q){
    Queue_Node* temp;
    temp = (node*)malloc(sizeof(node));
    temp->data.job_id = Q.count;
    temp->data.fin = false; //默认新进程是未执行
    temp->data.prior = (rand() % (max_prior-min_prior+1))+ min_prior;
    temp->data.service_time = (rand() % (max_service-min_service+1))+ min_service;
    temp->data.arrival_time = (rand() % (max_arrival-min_arrival+1))+ min_arrival;
    temp->data.stat = -1; //默认阻塞{用1表示就绪，-1表示阻塞，0表示执行}
    temp->data.next = NULL; //默认新进程其后不跟其他进程
    //入队操作
    Q.tail->next = temp;
    Q.tail = temp;
    temp->next = NULL;//默认最后一个入队的进程其后无其他进程
    Q.count++; //增加一个节点时对队列计数自增
}
// 重载进程比较，比较进程的服务时间长短
bool operator>(const Queue_Node& A, const Queue_Node& B) {
    return A.data.service_time > B.data.service_time;
}
// 打印队列内所有进程
void Queue_Print(LinkQueue Q){
    if(Q.head->next == NULL){
        cout << "The queue is empty";
        exit(0);
    }
    cout << "The size of the waiting queue:" << Q.count << endl;
    node* temp;
    temp = Q.head;
    cout << "The Process in harddesk:" << endl;
    while (temp != NULL) {
    cout << "PID: "<< temp->data.job_id << "\tstat: " << temp->data.stat << "\tarrival_time: " << temp->data.arrival_time <<"\tservice_time: " << temp->data.service_time << endl;
    
    temp = temp->next;
    }//如果指向队尾则结束打印
}
// 进程结束
void Queue_pop(LinkQueue& M) {
    Queue_Node* deleteptr = M.head->next;

    if (M.head->next == nullptr) {
        // 队列为空，不执行任何操作
        return;
    }

    if(deleteptr->next != nullptr){// 队内仍有两个及以上结点
        M.head->next = deleteptr->next;
        finished[static_cast<int>(deleteptr->data.job_id)][1] = timeline;
        free(deleteptr);
        M.count--;
    }
    else{ //仅剩唯一结点需释放
        M.tail = M.head;
        M.tail->next = M.head->next = nullptr;
        finished[static_cast<int>(deleteptr->data.job_id)][1] = timeline;
        free(deleteptr);
        M.count--;
    }
    
}
// FCFS执行
void FCFS_Queue(LinkQueue& Q, LinkQueue& M){
    void MemoryCall_FCFS(LinkQueue& Q, LinkQueue& M);
    void Queue_pop(LinkQueue& M);
    
    while (!(M.count==0 && Q.count==0)){//中止条件
        if (Q.count != 0 && M.count < 5) {
            // 就绪队列未满且进程队列非空，执行调度
            MemoryCall_FCFS(Q, M);
            continue;
        }

        Queue_Node* temp;
        temp = M.head->next; // 从实际第一个进程开始

        while(temp != nullptr){ // 选中第一个进程进行执行
        if(temp->data.service_time != 0){//未执行结束
            temp->data.stat = 0;
            temp->data.service_time -= 1;
            timeline += 1;
            temp->data.stat = 1;
            continue;
        }
        else// 出现进程执行完成
        {
            /*如果该进程具有子进程，且父进程所需部分已执行
            temp->data.fin = 1;
            */
            Queue_pop(M);
            timeline += Time_Release;
            MemoryCall_FCFS(Q, M);
            break;
        }
    }
    }
    cout << "===========All-Process-Finished===========" << endl;
    
    return;
}
// FCFS调度算法
void MemoryCall_FCFS(LinkQueue& Q, LinkQueue& M){

    if(M.count == 5||(M.count!=0 && Q.count == 0)){//内存满载或已经全部调入
    }else
    if(M.count < 5 && Q.count != 0){//内存未满，从外存就绪队列调入进程
        Queue_Node* temp;

        temp = Q.head->next; //保存待转移的进程
        if(timeline >= temp->data.arrival_time){ //检查是否到达
        if(temp->next != NULL){//防止访问越界
            Q.head->next = Q.head->next->next; //阻塞队列头节点后移一位
        } 
        else{
            Q.head = Q.tail;
            Q.head->next = Q.tail->next = NULL;
        }
        M.tail->next = temp;
        M.tail = temp;
        temp->next = NULL;
        // 状态更新
        temp->data.stat = 1;
        Q.count--;
        M.count++;

        finished[(int) temp->data.job_id][0] = timeline;
    }
    else
    {
        timeline += 1; //没有可调度的作业/进程，时间线自走
    }
    }

}
void Queue_Sort_ArrivalTime(LinkQueue& Q){
    
    for(int i = 0; i < Size_Storge - 1; i++){
        node* roundhead = Q.head;
        for(int j = 0; j < i; j++){ //插排定位
            roundhead = roundhead->next;
        }
        node* search = roundhead->next;
        node* temp = roundhead->next;
        while(search != nullptr){// 找最先到达的
            if(temp->data.arrival_time > search->data.arrival_time){
                temp = search;
            }
            search = search->next;
        }
        
        if(temp == roundhead->next)
            continue;
        node* switchptr = roundhead->next;
        
        while(switchptr->next != temp)
            switchptr = switchptr->next;
        if(temp == Q.tail->next){
            switchptr->next = nullptr;
        }
        else{
            switchptr->next = switchptr->next->next;
        }
        temp->next = roundhead->next;
        roundhead->next = temp;
    }
}

