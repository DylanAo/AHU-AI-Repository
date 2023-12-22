#include <iostream>
#include <string>
#include <random>

#define MAX 65535
#define Size_Storge 15 // 初始化进程数目（外存大小）
#define Size_Memory 5 // 内存大小(就绪队列大小)
#define TimePiece 50 // 初始化静态时间片大小

//优先数随机范围
#define max_prior 7
#define min_prior 1

//服务时间随机范围
#define max_service 100
#define min_service 30

#define max_arrival 100
#define min_arrival 0

// 数据控制块结构
typedef struct JobControlBlock
{
    short job_id; //标识符，用一个id来模拟表示其序号
    //string job_name; //外部标识符，赋予一个进程外部名
    /*
    处理机其他上下文，指本实验中没有用到的其他信息，为保证模拟方便未写出
    */
    short stat; //进程状态 {用1表示就绪，-1表示阻塞，0表示执行}
    bool fin; //该进程部分是否执行完（用于阻塞后再执行检索其链接的进程块）
    int prior; //进程优先级
    int service_time; //服务时间
    int arrival_time; //进入内存时间
    struct JobControlBlock* next; //下一个PCB块地址
}JCBType;

// 队列结点
typedef struct Queue_Node
{
    JCBType data;
    struct Queue_Node* next;
}node;
/*
struct cmp{
    bool operator()(Queue_Node& A, Queue_Node& B){
    if(A.data.service_time > B.data.service_time)
        return true;
    else
        return false;
    }
};
*/
// 队列
typedef struct LQueue
{
    node* head; // 队头
    node* tail; // 队尾
    short count; // 计数
}LinkQueue;