/**
 * ����ҵ��ģ��ϵͳ
 * ���Ĵ���
 * **ѧ����**
 * **��Ҫ�����������**
 */

// 8:00�ϰ࣬16.00�°࣬�˸�Сʱ
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

const int WindowsNum = 4;
int AllTime = 480;
int LatestTime = 450; // �˿�������ʱ��

const int MaxServiceNum = 50; //����ÿ����߷����˴�
int MinServiceNum = 40; //����ÿ����ͷ����˴�

int MaxServiceTime = 30; // ÿ����߷���ʱ��
int MinServiceTime = 5; // ÿ����ͷ���ʱ��

typedef struct Customer {
    int id; // �˿����
    int ArrivalTime; // ����ʱ��
    int ServiceTime; // ����ʱ��
} Customer;

typedef struct Queue
{
    Customer data[1000];
    int front;
    int rear;
    int size;
};

typedef struct Window {
    int CurRemainingServiceTime; // ��ǰ���ڰ���ҵ��Ŀͻ���ʣ�����ʱ��
    int RemainingServiceTime; // ��ʣ�����ʱ��
    int TotalWaitTime; // ͳ�Ƹ÷��񴰿����й˿͵ĵȴ�ʱ��
    Queue WindowsQueue; // ���񴰿ڶ���
} Window;

typedef struct Bank {
    int OpenTime, CloseTime; // �������°�ʱ��
    int NumToService; // ��Ҫ�����������
    Window windows[WindowsNum]; // �������񴰿�
    Queue BankQueue; // �����ɵĹ˿Ͷ���
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

void printBank(Bank* bank, int time) // ��ӡ��ǰ����״̬
{
    cout << endl;
    cout << "=====��ǰʱ��Ϊ " << RealTimeHour(time) << " �� " << RealTimeMin(time) << " ��=====" << endl;
    for (int i = 0; i < WindowsNum; ++i)
    {
        if (bank->windows[i].WindowsQueue.size == 0)
        {
            cout << "Windows[ " << i << " ]���޹˿�" << endl;
        }
        else
        {
            cout << "Windows[ " << i << " ]���й˿�" << bank->windows[i].WindowsQueue.size << "��" << endl;
            for (int j = bank->windows[i].WindowsQueue.front; j != bank->windows[i].WindowsQueue.rear; j++)
                cout << bank->windows[i].WindowsQueue.data[j].id << "   " << endl;
        }
    }
    cout << "================================" << endl << endl;
}

void GetCustomers(Bank* bank)
{//�������й˿�
    for (int i = 0; i < genRand(MinServiceNum, MaxServiceNum); i++)
    {
        Customer customer =
        {
        i,
        genRand(0, LatestTime), // ����ʱ��
        genRand(MinServiceTime, MaxServiceTime) // ����ʱ��
        }; // �����¹˿�
        cout << "�˿� " << customer.id << " ���� "
            << RealTimeHour(customer.ArrivalTime) << ":" << RealTimeMin(customer.ArrivalTime) 
            << " �����Ҫ����ʱ��Ϊ " << RealTimeMin(customer.ServiceTime) << " ���� " << endl;
        enqueue(bank->BankQueue, customer); // �����ɵĹ˿����
        bank->NumToService += 1;
    }
    BubbleSort(bank->BankQueue);

    cout << "���չ˿͹� " << bank->NumToService << " �ˣ������" << endl; //������
    for (int i = 0; i < bank->NumToService ; i++)
    {
        Customer customer = bank->BankQueue.data[i];
        cout << "�˿� " << customer.id << " ���� "
            << RealTimeHour(customer.ArrivalTime) << ":" << RealTimeMin(customer.ArrivalTime)
            << " �����Ҫ����ʱ��Ϊ " << RealTimeMin(customer.ServiceTime) << " ���� " << endl;
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
        initQueue(bank->windows[i].WindowsQueue); // ��ʼ�����񴰿ڶ���
    }
    initQueue(bank->BankQueue); // ��ʼ�������ɵĹ˿Ͷ���
}

void EventDriven(Bank* bank, Customer cur_customer, int now)
{
    int min = 0; // �ҵ���̷��񴰿ڶ���
    for (int i = 0; i < WindowsNum; ++i) 
        if (bank->windows[i].WindowsQueue.size <= min) 
            min = i;

    enqueue(bank->windows[min].WindowsQueue, cur_customer); // �˿�����̶�
    cout << "�˿� " << cur_customer.id << " �� "
        << RealTimeHour(now) << ":" << RealTimeMin(now)
        << " ������� " << min << " �ŷ��񴰿�," 
        << "��Ҫ����ʱ��Ϊ " << RealTimeMin(cur_customer.ServiceTime) << " ���� " << endl;

    // ͳ��ʱ��
    if (bank->windows[min].RemainingServiceTime > 0)  // 1. ͳ�Ƶȴ�ʱ����Ҫ���ǵ�ÿ���˵ĵȴ�ʱ��������Ҫ�ۼ�ʣ�����ʱ��
        bank->windows[min].TotalWaitTime += bank->windows[min].RemainingServiceTime;
    bank->windows[min].TotalWaitTime += cur_customer.ServiceTime; // 2. ͳ�Ʒ���ʱ��

    if (bank->windows[min].RemainingServiceTime == 0)
        bank->windows[min].CurRemainingServiceTime = cur_customer.ServiceTime; // 3. ��ʣ�����ʱ��Ϊ0��˵���ÿͻ�Ϊ��ǰ���С���һ�����ͻ�
    bank->windows[min].RemainingServiceTime += cur_customer.ServiceTime; // 4. ˢ�¸ö��е�ʣ�����ʱ��
}

void Clock(Bank* bank)
{// ʱ�����ƺ���
    for (int NowTime = 0; NowTime <= AllTime; NowTime++) // NowTime����ģ��ʱ�䣬1����1����
    {
        if (NowTime == getQueueHead(bank->BankQueue).ArrivalTime) // ĳ���˿���ʱ���ȥ��
        {
            EventDriven(bank, getQueueHead(bank->BankQueue), NowTime); 
            dequeue(bank->BankQueue); // �������
        }
        else
        {
            for (int i = 0; i < WindowsNum; ++i) // ʱ�����ţ�ÿ�����ڵ�ʣ�����ʱ��-1
            {
                if (bank->windows[i].RemainingServiceTime > 0) // �÷��񴰿ڶ��в�Ϊ��ʱ
                {
                    bank->windows[i].RemainingServiceTime -= 1;
                    bank->windows[i].CurRemainingServiceTime -= 1;
                    if (bank->windows[i].CurRemainingServiceTime == 0) // ��1֮�����0��˵��ͷ�˿Ͱ�����
                    {
                        Customer sb = getQueueHead(bank->windows[i].WindowsQueue);
                        cout << "�˿� " << sb.id << " �� "
                            << RealTimeHour(NowTime) << ":" << RealTimeMin(NowTime)
                            << " �� " << i << " �ŷ��񴰿�����" << endl;
                        dequeue(bank->windows[i].WindowsQueue); // ����
                        if (bank->windows[i].WindowsQueue.size != 0) // ���滹�����Ŷӣ�����ͷ�˿�
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
{ // ����ͻ�ƽ������ʱ��
    double total_time = 0;
    for (int i = 0; i < WindowsNum; ++i) 
        total_time += bank->windows[i].TotalWaitTime;
    return total_time / bank->NumToService; // �������ʱû�а�����ɵĹ˿ͼ�������ֱ�����
}

int main()
{
    //setSeed(2023)
    srand((unsigned)time(0));
    Bank* bank = (Bank*)malloc(sizeof(Bank));
    cout << "������8:00����Ӫҵ, 18:00����Ъҵ,�� " << WindowsNum << " �����񴰿�" << endl << endl; // ����
    OpenForDay(bank);
    GetCustomers(bank);
    Clock(bank);
    cout << "�����н���ƽ���ȴ�ʱ��Ϊ " << CloseForDay(bank) << " ����" << endl; // ����
 
    return 0;
}

