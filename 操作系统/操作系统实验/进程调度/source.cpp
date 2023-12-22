#include "head.h"

int t = 0; //设置整数模拟时间线
int finished[Size_Memory][2]={0}; //记录队列开始结束事件

// 模拟进程执行过程
int main(){
    //函数声明    
    void Init_ProcessQueue(LinkQueue& Q);
    void Init_MemoryQueue(LinkQueue& Q);
    void Init_PCB(LinkQueue& Q);
    bool cmp_prior(Queue_Node& A, Queue_Node& B);
    void Queue_Print(LinkQueue Q);
    void PR_Queue(LinkQueue& Q, LinkQueue& M);
    void MemoryCall_FCFS(LinkQueue& Q, LinkQueue& M);
    void MemoryCall_PriorityScheduling(LinkQueue& Q, LinkQueue& M);

    LinkQueue QueueProcess; //声明进程队列
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
    Init_ProcessQueue(QueueProcess);
    Init_MemoryQueue(QueueMemory);
    
    for(int i = 0;i < Size_Storge; i++){
        Init_PCB(QueueProcess);
    }
    Queue_Print(QueueProcess);

    // RR轮转算法
    PR_Queue(QueueProcess, QueueMemory);
    
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

    LinkQueue QueueProcess_1; //声明进程队列
    LinkQueue QueueMemory_1; //声明内存队列
    Init_ProcessQueue(QueueProcess_1);
    Init_MemoryQueue(QueueMemory_1);
    for(int i = 0;i < Size_Storge; i++){
        Init_PCB(QueueProcess_1);
    }
    //优先级调度算法
    MemoryCall_PriorityScheduling(QueueProcess_1,QueueMemory_1);

    system("pause");
    return 0;
}

// 初始化外存上的进程队列
void Init_ProcessQueue(LinkQueue& Q){
    Q.head = Q.tail = (node*)malloc(sizeof(node));
    Q.head->next = Q.tail->next = NULL;
    Q.head->data.Fin = false;
    Q.head->data.process_id = MAX; //第一个空节点不可访问
    Q.head->data.next = NULL;
    Q.head->data.prior = 0;
    Q.head->data.service_time=0;
    Q.head->data.stat = 1;
    Q.count = 0;
}
// 初始化内存队列
void Init_MemoryQueue(LinkQueue& Q) {
    Q.head = Q.tail = (node*)malloc(sizeof(node));
    Q.head->next = Q.tail->next = NULL;
    Q.head->data.Fin = false;
    Q.head->data.process_id = MAX; //第一个空节点不可访问
    Q.head->data.next = NULL;
    Q.head->data.prior = 0;
    Q.head->data.service_time=0;
    Q.head->data.stat = 1;
    Q.count = 0;
}
// 初始化随机生成1个PCB并插入到就绪队列中
void Init_PCB(LinkQueue& Q){
    Queue_Node* temp;
    temp = (node*)malloc(sizeof(node));
    temp->data.process_id = Q.count;
    temp->data.Fin = false; //默认新进程是未执行
    temp->data.prior = (rand() % (max_prior-min_prior+1))+ min_prior;
    temp->data.service_time = (rand() % (max_service-min_service+1))+ min_service;
    temp->data.stat = -1; //默认阻塞{用1表示就绪，-1表示阻塞，0表示执行}
    temp->data.next = NULL; //默认新进程其后不跟其他进程
    //入队操作
    Q.tail->next = temp;
    Q.tail = temp;
    temp->next = NULL;//默认最后一个入队的进程其后无其他进程
    Q.count++; //增加一个节点时对队列计数自增
}
// 重载进程比较，比较进程的优先级大小
bool operator<(const Queue_Node& A, const Queue_Node& B) {
    return A.data.prior < B.data.prior;
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
    cout << "PID: "<< temp->data.process_id << "\tstat: " << temp->data.stat << "\tservice_time: " << temp->data.service_time << endl;
    
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
        finished[static_cast<int>(deleteptr->data.process_id)][1] = t + deleteptr->data.service_time;
        free(deleteptr);
        M.count--;
    }
    else{ //仅剩唯一结点需释放
        M.tail = M.head;
        M.tail->next = M.head->next = nullptr;
        finished[static_cast<int>(deleteptr->data.process_id)][1] = t + deleteptr->data.service_time;
        free(deleteptr);
        M.count--;
    }
    
}
// PR时间片轮转
void PR_Queue(LinkQueue& Q, LinkQueue& M){
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

        while(temp != nullptr){ // 重复检查第一个进程是否可以一个时间片内执行结束
        if(temp->data.service_time > TimePiece){
            temp->data.stat = 0;
            temp->data.service_time -= TimePiece;
            temp->data.stat = 1;
            // 一个时间片结束，当前进程一轮未结束，进程转入队尾
            if(temp->next != nullptr){//确保进程不为最后一个
                M.head->next = temp->next;
                M.tail->next = temp;
                M.tail = temp;
                M.tail->next = nullptr;
            }
            else{ //恰好为最后一个进程，无需修改队列指针，下次仍是队首进程（唯一进程）
            }
            t += TimePiece;
            continue;
        }
        else if(temp->data.service_time <= TimePiece) // 出现进程执行完成
        {
            /*如果该进程具有子进程，且父进程所需部分已执行
            temp->data.Fin = 1;
            */
            if (temp->next != nullptr) { // 防止恰巧为内存中最后一个进程，防止指针越界
                int temp_time = temp->data.service_time;// 注意需要提前保存动态的时间片，防止指针移动丢失数据，也不能提前增在时间线，因为逻辑上该进程尚未执行，防止重复加和
                Queue_pop(M);
                t += temp_time;
                MemoryCall_FCFS(Q, M);
                break;
            } 
            else { //如果执行结束的刚好是内存中最后一个进程，则可以直接结束
                int temp_time = temp->data.service_time;
                Queue_pop(M);
                t += temp_time;
                MemoryCall_FCFS(Q, M);
                break;  
            }
        }
    }
    t += TimePiece;
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

        finished[(int) temp->data.process_id][0] = t;
    }

}
// 进程排序（按照优先数升序）
void SortByPriority(LinkQueue& Q) {
    LinkQueue Q_copy;
    Init_ProcessQueue(Q_copy);
    for(int i = 0;i < Size_Storge; i++){
        Init_PCB(Q_copy);
    }
    for(int i = 0; i < Size_Storge; i++){
        node* temp = Q_copy;
        while(temp->next != nullptr){

        }
    }
}

// 优先级调度算法
void MemoryCall_PriorityScheduling(LinkQueue& Q, LinkQueue& M) {
    t = 0;
    // 按照优先数升序排序外存中的队列
    SortByPriority(Q);
    Queue_Print(Q);

    while (!(M.count == 0 && Q.count == 0)) {
        if (Q.count != 0 && M.count < 5) {
            // 就绪队列未满且进程队列非空，执行调度
            Queue_Node* temp = Q.head->next; // 从队首获取进程
            Q.head->next = temp->next; // 更新队列头
            temp->next = nullptr;

            // 将进程插入到内存队列中
            M.tail->next = temp;
            M.tail = temp;
            M.count++;

            finished[static_cast<int>(temp->data.process_id)][0] = t;

            continue;
        }
        // 执行调度算法，根据优先数选择合适的进程执行
        Queue_Node* temp = M.head->next; // 从队首获取进程
        while (temp != nullptr) {
            if (temp->data.service_time > 0) {
                // 进程未执行完成，执行完一个进程后再执行下一个
                temp->data.stat = 0;
                t += temp->data.service_time;
                temp->data.service_time = 0;
                temp->data.stat = 1;

                // 移出队列
                Queue_pop(M);
                break;
            }
            temp = temp->next;
        }
        // 输出当前进程执行信息
        cout << "PID: " << temp->data.process_id << "\tArrival_time: " << finished[static_cast<int>(temp->data.process_id)][0]
             << "\tFinished_time: " << t << "\tTurnover time: " << t - finished[static_cast<int>(temp->data.process_id)][0]
             << "\tWeight_Turnover time: " << static_cast<float>(t - finished[static_cast<int>(temp->data.process_id)][0]) / (t - finished[static_cast<int>(temp->data.process_id)][0])
             << endl;
        // 移出队列
        Queue_pop(M);
    }
    cout << "===========All-Process-Finished===========" << endl;
}