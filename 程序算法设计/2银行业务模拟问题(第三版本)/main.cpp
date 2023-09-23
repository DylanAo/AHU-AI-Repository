// 8:00上班，18:00下班，暂时不计午休与周六日休息
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

const int WindowsNum = 4; // 窗口数，加const是为了定义结构体
int AllTime = 60; // 总服务时间，可更改，600为标准下班时间
int LatestArrivalTime = AllTime - 30; // 在关门前30分钟不再接收顾客，消耗完内部顾客后关门

int MaxServiceNum = 10; //银行每日最高服务人次，可更改，不宜过高
int MinServiceNum = 8; //银行每日最低服务人次,可更改，不宜过高

int MaxServiceTime = 30; // 每人最高服务时长
int MinServiceTime = 5; // 每人最低服务时长

typedef struct Customer
{
    int id; // 顾客序号
    int ArrivalTime; // 到达时刻
    int ServiceTime; // 服务时间
} Customer;

typedef struct Queue // 顺序队，不考虑假溢出问题
{
    Customer data[1000];
    int front; // 头指针，指向头节点
    int rear; // 尾指针，指向尾节点的下一个值
    int size; // 队长
};

typedef struct Window
{
    int CurRemainingServiceTime; // 当前正在办理业务的客户的剩余服务时长
    int RemainingServiceTime; // 总剩余服务时长
    int TotalWaitTime; // 该服务窗口所有顾客的等待时长
    Queue WindowsQueue; // 服务窗口队列
} Window;

typedef struct Bank
{
    int OpenTime, CloseTime; // 银行上下班时间
    int NumToService; // 需要服务的总人数
    Window windows[WindowsNum]; // 几个服务窗口
    Queue BankQueue; // 已生成的顾客队列
} Bank;


Customer GetQueueHead(Queue& Q)
{
    return Q.data[Q.front];
}
void InitQueue(Queue& Q)
{
    Q.front = Q.rear = 0;
    Q.size = 0;
}
void EnQueue(Queue& Q, Customer customer) // customer入队
{
    Q.data[Q.rear] = customer;
    Q.rear += 1;
    Q.size += 1;
}
void DeQueue(Queue& Q) // 头节点出队
{
    Q.front += 1;
    Q.size -= 1;
}
int GetRand(int min, int max) // 获取min到max中的一个随机数
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
void BubbleSort(Queue& Q) // 冒泡排序算法
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

void PrintBank(Bank* bank, int time) // 打印当前银行状态
{
    cout << endl;
    cout << "=====当前时间为 " << RealTimeHour(time) << " 点 " << RealTimeMin(time) << " 分=====" << endl;
    for (int i = 0; i < WindowsNum; ++i)
    {
        if (bank->windows[i].WindowsQueue.size == 0)
            cout << "Windows[ " << i << " ]现无顾客" << endl;
        else
        {
            cout << "Windows[ " << i << " ]现有顾客 " << bank->windows[i].WindowsQueue.size << " 人" << endl;
            for (int j = bank->windows[i].WindowsQueue.front; j < bank->windows[i].WindowsQueue.rear; j++)
                cout << bank->windows[i].WindowsQueue.data[j].id << "   ";
            cout << endl;
        }
    }
    cout << "================================" << endl << endl;
}

void GetCustomers(Bank* bank)
{//生成所有顾客
    for (int i = 0; i < GetRand(MinServiceNum, MaxServiceNum); i++)
    {
        Customer sb = // sb是somebody
        {
        i,
        GetRand(0, LatestArrivalTime), // 到达时刻
        GetRand(MinServiceTime, MaxServiceTime) // 服务时间
        }; // 生成新顾客
        cout << "顾客 " << sb.id << " 将于 "
            << RealTimeHour(sb.ArrivalTime) << ":" << RealTimeMin(sb.ArrivalTime)
            << " 到达，需要服务时间为 " << RealTimeMin(sb.ServiceTime) << " 分钟 " << endl;
        EnQueue(bank->BankQueue, sb); // 将生成的顾客入队
        bank->NumToService += 1;
    }
    BubbleSort(bank->BankQueue); // 生成的顾客到达时间错乱，按到达时间排序

    cout << "今日顾客共 " << bank->NumToService << " 人，排序后：" << endl;
    for (int i = 0; i < bank->NumToService; i++)
    {
        Customer sb = bank->BankQueue.data[i];
        cout << "顾客 " << sb.id << " 将于 "
            << RealTimeHour(sb.ArrivalTime) << ":" << RealTimeMin(sb.ArrivalTime)
            << " 到达，需要服务时间为 " << RealTimeMin(sb.ServiceTime) << " 分钟 " << endl;
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
        InitQueue(bank->windows[i].WindowsQueue); // 初始化服务窗口队列
    }
    InitQueue(bank->BankQueue); // 初始化已生成的顾客队列
}

void EventDriven(Bank* bank, Customer cur_customer, int now)
{
    int MinI = 0; // 找到最短服务窗口队列MinI
    int MinSize = bank->windows[0].WindowsQueue.size;
    for (int i = 1; i < WindowsNum; ++i)
        if (bank->windows[i].WindowsQueue.size < MinSize)
        {
            MinSize = bank->windows[i].WindowsQueue.size;
            MinI = i;
        }

    EnQueue(bank->windows[MinI].WindowsQueue, cur_customer); // 顾客入最短队
    cout << "顾客 " << cur_customer.id << " 于 "
        << RealTimeHour(now) << ":" << RealTimeMin(now)
        << " 到达，进入 " << MinI << " 号服务窗口,"
        << "需要服务时间为 " << RealTimeMin(cur_customer.ServiceTime) << " 分钟 " << endl;

    // 统计时长, 我看不懂，反正能运行
    if (bank->windows[MinI].RemainingServiceTime > 0)  // 1. 统计等待时长；要考虑到每个人的等待时长，所以要累加剩余服务时长
        bank->windows[MinI].TotalWaitTime += bank->windows[MinI].RemainingServiceTime;
    bank->windows[MinI].TotalWaitTime += cur_customer.ServiceTime; // 2. 统计服务时长

    if (bank->windows[MinI].RemainingServiceTime == 0)
        bank->windows[MinI].CurRemainingServiceTime = cur_customer.ServiceTime; // 3. 总剩余服务时长为0，说明该客户为当前队列“第一个”客户
    bank->windows[MinI].RemainingServiceTime += cur_customer.ServiceTime; // 4. 刷新该队列的剩余服务时长
}

void Clock(Bank* bank)
{// 时间推移函数
    int flag[WindowsNum] = { 0 };
    for (int NowTime = 0; NowTime <= AllTime; NowTime++) // NowTime就是模拟时间，1代表1分钟
    {
        for (int i = 0; i < WindowsNum; ++i) // 这个是上一分钟找到的应该出队的窗口
        {
            if (flag[i] == 1)
            {
                DeQueue(bank->windows[i].WindowsQueue);
                flag[i] = 0;
            }
        }

        while (NowTime == GetQueueHead(bank->BankQueue).ArrivalTime) // 头顾客到时候了
        {
            Customer sb = GetQueueHead(bank->BankQueue);
            EventDriven(bank, sb, NowTime);
            DeQueue(bank->BankQueue); // 头顾客出银行队
        }

        for (int i = 0; i < WindowsNum; ++i) // 时间流逝，每个窗口的剩余服务时长-1
        {
            if (bank->windows[i].RemainingServiceTime > 0) // 该服务窗口队列不为空时
            {
                bank->windows[i].RemainingServiceTime -= 1;
                bank->windows[i].CurRemainingServiceTime -= 1;
                if ((bank->windows[i].CurRemainingServiceTime) == 0) // 减1之后等于0，说明头顾客办完了
                {
                    Customer sb = GetQueueHead(bank->windows[i].WindowsQueue);
                    cout << "顾客 " << sb.id << " 于 "
                        << RealTimeHour(NowTime + 1) << ":" << RealTimeMin(NowTime + 1)
                        << " 从 " << i << " 号服务窗口走人" << endl;
                    flag[i] = 1;// 保存一下需出队的数据，等到下一分钟再出队
                    if (bank->windows[i].WindowsQueue.size != 0) // 后面还有人排队，更新头顾客
                        bank->windows[i].CurRemainingServiceTime = GetQueueHead(bank->windows[i].WindowsQueue).ServiceTime;
                }
            }
        }

        if (NowTime % 5 == 0) // 1分钟看一次银行现状
            PrintBank(bank, NowTime);
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
    //srand((unsigned)time(0)); // 按当前时间来生成随机数
    Bank* bank = (Bank*)malloc(sizeof(Bank));
    cout << "本银行8:00开门营业, 16:00关门歇业,共 " << WindowsNum << " 个服务窗口" << endl << endl; // 关门
    OpenForDay(bank);
    GetCustomers(bank);
    Clock(bank);
    cout << "本银行今日平均等待时间为 " << CloseForDay(bank) << " 分钟" << endl; // 关门

    return 0;
}