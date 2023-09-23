// 8:00�ϰ࣬18:00�°࣬��ʱ������������������Ϣ
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

const int WindowsNum = 4; // ����������const��Ϊ�˶���ṹ��
int AllTime = 60; // �ܷ���ʱ�䣬�ɸ��ģ�600Ϊ��׼�°�ʱ��
int LatestArrivalTime = AllTime - 30; // �ڹ���ǰ30���Ӳ��ٽ��չ˿ͣ��������ڲ��˿ͺ����

int MaxServiceNum = 10; //����ÿ����߷����˴Σ��ɸ��ģ����˹���
int MinServiceNum = 8; //����ÿ����ͷ����˴�,�ɸ��ģ����˹���

int MaxServiceTime = 30; // ÿ����߷���ʱ��
int MinServiceTime = 5; // ÿ����ͷ���ʱ��

typedef struct Customer
{
    int id; // �˿����
    int ArrivalTime; // ����ʱ��
    int ServiceTime; // ����ʱ��
} Customer;

typedef struct Queue // ˳��ӣ������Ǽ��������
{
    Customer data[1000];
    int front; // ͷָ�룬ָ��ͷ�ڵ�
    int rear; // βָ�룬ָ��β�ڵ����һ��ֵ
    int size; // �ӳ�
};

typedef struct Window
{
    int CurRemainingServiceTime; // ��ǰ���ڰ���ҵ��Ŀͻ���ʣ�����ʱ��
    int RemainingServiceTime; // ��ʣ�����ʱ��
    int TotalWaitTime; // �÷��񴰿����й˿͵ĵȴ�ʱ��
    Queue WindowsQueue; // ���񴰿ڶ���
} Window;

typedef struct Bank
{
    int OpenTime, CloseTime; // �������°�ʱ��
    int NumToService; // ��Ҫ�����������
    Window windows[WindowsNum]; // �������񴰿�
    Queue BankQueue; // �����ɵĹ˿Ͷ���
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
void EnQueue(Queue& Q, Customer customer) // customer���
{
    Q.data[Q.rear] = customer;
    Q.rear += 1;
    Q.size += 1;
}
void DeQueue(Queue& Q) // ͷ�ڵ����
{
    Q.front += 1;
    Q.size -= 1;
}
int GetRand(int min, int max) // ��ȡmin��max�е�һ�������
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
void BubbleSort(Queue& Q) // ð�������㷨
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

void PrintBank(Bank* bank, int time) // ��ӡ��ǰ����״̬
{
    cout << endl;
    cout << "=====��ǰʱ��Ϊ " << RealTimeHour(time) << " �� " << RealTimeMin(time) << " ��=====" << endl;
    for (int i = 0; i < WindowsNum; ++i)
    {
        if (bank->windows[i].WindowsQueue.size == 0)
            cout << "Windows[ " << i << " ]���޹˿�" << endl;
        else
        {
            cout << "Windows[ " << i << " ]���й˿� " << bank->windows[i].WindowsQueue.size << " ��" << endl;
            for (int j = bank->windows[i].WindowsQueue.front; j < bank->windows[i].WindowsQueue.rear; j++)
                cout << bank->windows[i].WindowsQueue.data[j].id << "   ";
            cout << endl;
        }
    }
    cout << "================================" << endl << endl;
}

void GetCustomers(Bank* bank)
{//�������й˿�
    for (int i = 0; i < GetRand(MinServiceNum, MaxServiceNum); i++)
    {
        Customer sb = // sb��somebody
        {
        i,
        GetRand(0, LatestArrivalTime), // ����ʱ��
        GetRand(MinServiceTime, MaxServiceTime) // ����ʱ��
        }; // �����¹˿�
        cout << "�˿� " << sb.id << " ���� "
            << RealTimeHour(sb.ArrivalTime) << ":" << RealTimeMin(sb.ArrivalTime)
            << " �����Ҫ����ʱ��Ϊ " << RealTimeMin(sb.ServiceTime) << " ���� " << endl;
        EnQueue(bank->BankQueue, sb); // �����ɵĹ˿����
        bank->NumToService += 1;
    }
    BubbleSort(bank->BankQueue); // ���ɵĹ˿͵���ʱ����ң�������ʱ������

    cout << "���չ˿͹� " << bank->NumToService << " �ˣ������" << endl;
    for (int i = 0; i < bank->NumToService; i++)
    {
        Customer sb = bank->BankQueue.data[i];
        cout << "�˿� " << sb.id << " ���� "
            << RealTimeHour(sb.ArrivalTime) << ":" << RealTimeMin(sb.ArrivalTime)
            << " �����Ҫ����ʱ��Ϊ " << RealTimeMin(sb.ServiceTime) << " ���� " << endl;
    }
}

void OpenForDay(Bank* bank) // ��ʼ������
{
    bank->OpenTime = 0;
    bank->CloseTime = AllTime;
    bank->NumToService = 0;

    for (int i = 0; i < WindowsNum; ++i) // ��ʼ�����񴰿�
    {
        bank->windows[i].CurRemainingServiceTime = 0;
        bank->windows[i].RemainingServiceTime = 0;
        bank->windows[i].TotalWaitTime = 0;
        InitQueue(bank->windows[i].WindowsQueue); // ��ʼ�����񴰿ڶ���
    }
    InitQueue(bank->BankQueue); // ��ʼ�������ɵĹ˿Ͷ���
}

void EventDriven(Bank* bank, Customer cur_customer, int now)
{
    int MinI = 0; // �ҵ���̷��񴰿ڶ���MinI
    int MinSize = bank->windows[0].WindowsQueue.size;
    for (int i = 1; i < WindowsNum; ++i)
        if (bank->windows[i].WindowsQueue.size < MinSize)
        {
            MinSize = bank->windows[i].WindowsQueue.size;
            MinI = i;
        }

    EnQueue(bank->windows[MinI].WindowsQueue, cur_customer); // �˿�����̶�
    cout << "�˿� " << cur_customer.id << " �� "
        << RealTimeHour(now) << ":" << RealTimeMin(now)
        << " ������� " << MinI << " �ŷ��񴰿�,"
        << "��Ҫ����ʱ��Ϊ " << RealTimeMin(cur_customer.ServiceTime) << " ���� " << endl;

    // ͳ��ʱ��, �ҿ�����������������
    if (bank->windows[MinI].RemainingServiceTime > 0)  // 1. ͳ�Ƶȴ�ʱ����Ҫ���ǵ�ÿ���˵ĵȴ�ʱ��������Ҫ�ۼ�ʣ�����ʱ��
        bank->windows[MinI].TotalWaitTime += bank->windows[MinI].RemainingServiceTime;
    bank->windows[MinI].TotalWaitTime += cur_customer.ServiceTime; // 2. ͳ�Ʒ���ʱ��

    if (bank->windows[MinI].RemainingServiceTime == 0)
        bank->windows[MinI].CurRemainingServiceTime = cur_customer.ServiceTime; // 3. ��ʣ�����ʱ��Ϊ0��˵���ÿͻ�Ϊ��ǰ���С���һ�����ͻ�
    bank->windows[MinI].RemainingServiceTime += cur_customer.ServiceTime; // 4. ˢ�¸ö��е�ʣ�����ʱ��
}

void Clock(Bank* bank)
{// ʱ�����ƺ���
    int flag[WindowsNum] = { 0 };
    for (int NowTime = 0; NowTime <= AllTime; NowTime++) // NowTime����ģ��ʱ�䣬1����1����
    {
        for (int i = 0; i < WindowsNum; ++i) // �������һ�����ҵ���Ӧ�ó��ӵĴ���
        {
            if (flag[i] == 1)
            {
                DeQueue(bank->windows[i].WindowsQueue);
                flag[i] = 0;
            }
        }

        while (NowTime == GetQueueHead(bank->BankQueue).ArrivalTime) // ͷ�˿͵�ʱ����
        {
            Customer sb = GetQueueHead(bank->BankQueue);
            EventDriven(bank, sb, NowTime);
            DeQueue(bank->BankQueue); // ͷ�˿ͳ����ж�
        }

        for (int i = 0; i < WindowsNum; ++i) // ʱ�����ţ�ÿ�����ڵ�ʣ�����ʱ��-1
        {
            if (bank->windows[i].RemainingServiceTime > 0) // �÷��񴰿ڶ��в�Ϊ��ʱ
            {
                bank->windows[i].RemainingServiceTime -= 1;
                bank->windows[i].CurRemainingServiceTime -= 1;
                if ((bank->windows[i].CurRemainingServiceTime) == 0) // ��1֮�����0��˵��ͷ�˿Ͱ�����
                {
                    Customer sb = GetQueueHead(bank->windows[i].WindowsQueue);
                    cout << "�˿� " << sb.id << " �� "
                        << RealTimeHour(NowTime + 1) << ":" << RealTimeMin(NowTime + 1)
                        << " �� " << i << " �ŷ��񴰿�����" << endl;
                    flag[i] = 1;// ����һ������ӵ����ݣ��ȵ���һ�����ٳ���
                    if (bank->windows[i].WindowsQueue.size != 0) // ���滹�����Ŷӣ�����ͷ�˿�
                        bank->windows[i].CurRemainingServiceTime = GetQueueHead(bank->windows[i].WindowsQueue).ServiceTime;
                }
            }
        }

        if (NowTime % 5 == 0) // 1���ӿ�һ��������״
            PrintBank(bank, NowTime);
    }
}

double CloseForDay(Bank* bank)
{ // ����ͻ�ƽ������ʱ��
    double total_time = 0;
    for (int i = 0; i < WindowsNum; ++i)
        total_time += bank->windows[i].TotalWaitTime;
    return total_time / bank->NumToService; // �������ʱû�а�����ɵĹ˿ͼ�������ֱ�����
}

int main()
{
    //srand((unsigned)time(0)); // ����ǰʱ�������������
    Bank* bank = (Bank*)malloc(sizeof(Bank));
    cout << "������8:00����Ӫҵ, 16:00����Ъҵ,�� " << WindowsNum << " �����񴰿�" << endl << endl; // ����
    OpenForDay(bank);
    GetCustomers(bank);
    Clock(bank);
    cout << "�����н���ƽ���ȴ�ʱ��Ϊ " << CloseForDay(bank) << " ����" << endl; // ����

    return 0;
}