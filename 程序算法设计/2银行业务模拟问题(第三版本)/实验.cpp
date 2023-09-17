/**
 * 银行业务模拟系统
 * 核心代码
 * **学生版**
 * **需要补充基础代码**
 */

// 8:00上班，16.00下班，八个小时
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

const int WindowsNum = 4;
int AllTime = 480;
int LatestTime = 450; // 顾客最晚到达时间

const int MaxServiceNum = 50; //银行每日最高服务人次
int MinServiceNum = 40; //银行每日最低服务人次

int MaxServiceTime = 30; // 每人最高服务时长
int MinServiceTime = 5; // 每人最低服务时长

typedef struct Customer {
    int id; // 顾客序号
    int ArrivalTime; // 到达时刻
    int ServiceTime; // 服务时间
} Customer;

typedef struct Queue
{
    Customer data[1000];
    int front;
    int rear;
    int size;
};

typedef struct Window {
    int CurRemainingServiceTime; // 当前正在办理业务的客户的剩余服务时长
    int RemainingServiceTime; // 总剩余服务时长
    int TotalWaitTime; // 统计该服务窗口所有顾客的等待时长
    Queue WindowsQueue; // 服务窗口队列
} Window;

typedef struct Bank {
    int OpenTime, CloseTime; // 银行上下班时间
    int NumToService; // 需要服务的总人数
    Window windows[WindowsNum]; // 几个服务窗口
    Queue BankQueue; // 已生成的顾客队列
} Bank;


Customer getQueueHead(Queue& Q)
{
    return Q.data[Q.front];
}
void initQueue(Queue& Q)
{
    Q.front= Q.rear = 0;
    Q.size = 0;
}
void enqueue(Queue& Q, Customer customer)
{
    Q.data[Q.rear] = customer;
    Q.rear += 1;
    Q.size += 1;
}
void dequeue(Queue& Q)
{
    Q.front += 1;
    Q.size -= 1;
}
int genRand(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}
int RealTimeHour(int time)
{
    return time / 60 + 8;
}
int RealTimeMin(int time)
{
    return time % 60;
}
void BubbleSort(Queue& Q)
{
    for (int i = Q.front; i < Q.rear; i++)
        for (int j = i + 1; j < Q.rear; j++)
            if (Q.data[i].ArrivalTime > Q.data[j].ArrivalTime)
            {
                Customer cur = Q.data[i];
                Q.data[i] = Q.data[j];
                Q.data[j] = cur;
            }
}

void printBank(Bank* bank, int time) // 打印当前银行状态
{
    cout << endl;
    cout << "=====当前时间为 " << RealTimeHour(time) << " 点 " << RealTimeMin(time) << " 分=====" << endl;
    for (int i = 0; i < WindowsNum; ++i)
    {
        if (bank->windows[i].WindowsQueue.size == 0)
        {
            cout << "Windows[ " << i << " ]现无顾客" << endl;
        }
        else
        {
            cout << "Windows[ " << i << " ]现有顾客" << bank->windows[i].WindowsQueue.size << "人" << endl;
            for (int j = bank->windows[i].WindowsQueue.front; j != bank->windows[i].WindowsQueue.rear; j++)
                cout << bank->windows[i].WindowsQueue.data[j].id << "   " << endl;
        }
    }
    cout << "================================" << endl << endl;
}

void GetCustomers(Bank* bank)
{//生成所有顾客
    for (int i = 0; i < genRand(MinServiceNum, MaxServiceNum); i++)
    {
        Customer customer =
        {
        i,
        genRand(0, LatestTime), // 到达时刻
        genRand(MinServiceTime, MaxServiceTime) // 服务时间
        }; // 生成新顾客
        cout << "顾客 " << customer.id << " 将于 "
            << RealTimeHour(customer.ArrivalTime) << ":" << RealTimeMin(customer.ArrivalTime) 
            << " 到达，需要服务时间为 " << RealTimeMin(customer.ServiceTime) << " 分钟 " << endl;
        enqueue(bank->BankQueue, customer); // 将生成的顾客入队
        bank->NumToService += 1;
    }
    BubbleSort(bank->BankQueue);

    cout << "今日顾客共 " << bank->NumToService << " 人，排序后：" << endl; //操你妈
    for (int i = 0; i < bank->NumToService ; i++)
    {
        Customer customer = bank->BankQueue.data[i];
        cout << "顾客 " << customer.id << " 将于 "
            << RealTimeHour(customer.ArrivalTime) << ":" << RealTimeMin(customer.ArrivalTime)
            << " 到达，需要服务时间为 " << RealTimeMin(customer.ServiceTime) << " 分钟 " << endl;
    }
}

void OpenForDay(Bank* bank) // 初始化函数
{
    bank->OpenTime = 0;
    bank->CloseTime = AllTime;
    bank->NumToService = 0;

    for (int i = 0; i < WindowsNum; ++i) // 初始化服务窗口
    { 
        bank->windows[i].CurRemainingServiceTime = 0;
        bank->windows[i].RemainingServiceTime = 0;
        bank->windows[i].TotalWaitTime = 0;
        initQueue(bank->windows[i].WindowsQueue); // 初始化服务窗口队列
    }
    initQueue(bank->BankQueue); // 初始化已生成的顾客队列
}

void EventDriven(Bank* bank, Customer cur_customer, int now)
{
    int min = 0; // 找到最短服务窗口队列
    for (int i = 0; i < WindowsNum; ++i) 
        if (bank->windows[i].WindowsQueue.size <= min) 
            min = i;

    enqueue(bank->windows[min].WindowsQueue, cur_customer); // 顾客入最短队
    cout << "顾客 " << cur_customer.id << " 于 "
        << RealTimeHour(now) << ":" << RealTimeMin(now)
        << " 到达，进入 " << min << " 号服务窗口," 
        << "需要服务时间为 " << RealTimeMin(cur_customer.ServiceTime) << " 分钟 " << endl;

    // 统计时长
    if (bank->windows[min].RemainingServiceTime > 0)  // 1. 统计等待时长；要考虑到每个人的等待时长，所以要累加剩余服务时长
        bank->windows[min].TotalWaitTime += bank->windows[min].RemainingServiceTime;
    bank->windows[min].TotalWaitTime += cur_customer.ServiceTime; // 2. 统计服务时长

    if (bank->windows[min].RemainingServiceTime == 0)
        bank->windows[min].CurRemainingServiceTime = cur_customer.ServiceTime; // 3. 总剩余服务时长为0，说明该客户为当前队列“第一个”客户
    bank->windows[min].RemainingServiceTime += cur_customer.ServiceTime; // 4. 刷新该队列的剩余服务时长
}

void Clock(Bank* bank)
{// 时间推移函数
    for (int NowTime = 0; NowTime <= AllTime; NowTime++) // NowTime就是模拟时间，1代表1分钟
    {
        if (NowTime == getQueueHead(bank->BankQueue).ArrivalTime) // 某个顾客是时候进去了
        {
            EventDriven(bank, getQueueHead(bank->BankQueue), NowTime); 
            dequeue(bank->BankQueue); // 草泥马滚
        }
        else
        {
            for (int i = 0; i < WindowsNum; ++i) // 时间流逝，每个窗口的剩余服务时长-1
            {
                if (bank->windows[i].RemainingServiceTime > 0) // 该服务窗口队列不为空时
                {
                    bank->windows[i].RemainingServiceTime -= 1;
                    bank->windows[i].CurRemainingServiceTime -= 1;
                    if (bank->windows[i].CurRemainingServiceTime == 0) // 减1之后等于0，说明头顾客办完了
                    {
                        Customer sb = getQueueHead(bank->windows[i].WindowsQueue);
                        cout << "顾客 " << sb.id << " 于 "
                            << RealTimeHour(NowTime) << ":" << RealTimeMin(NowTime)
                            << " 从 " << i << " 号服务窗口走人" << endl;
                        dequeue(bank->windows[i].WindowsQueue); // 走人
                        if (bank->windows[i].WindowsQueue.size != 0) // 后面还有人排队，更新头顾客
                            bank->windows[i].CurRemainingServiceTime = getQueueHead(bank->windows[i].WindowsQueue).ServiceTime;
                    }
                }
            }
        }
        if (NowTime % 60 == 0)
            printBank(bank, NowTime);
    }
}

double CloseForDay(Bank* bank)
{ // 计算客户平均逗留时长
    double total_time = 0;
    for (int i = 0; i < WindowsNum; ++i) 
        total_time += bank->windows[i].TotalWaitTime;
    return total_time / bank->NumToService; // 假设关门时没有办理完成的顾客继续办理直到完成
}

int main()
{
    //setSeed(2023)
    srand((unsigned)time(0));
    Bank* bank = (Bank*)malloc(sizeof(Bank));
    cout << "本银行8:00开门营业, 18:00关门歇业,共 " << WindowsNum << " 个服务窗口" << endl << endl; // 关门
    OpenForDay(bank);
    GetCustomers(bank);
    Clock(bank);
    cout << "本银行今日平均等待时间为 " << CloseForDay(bank) << " 分钟" << endl; // 关门
 
    return 0;
}

