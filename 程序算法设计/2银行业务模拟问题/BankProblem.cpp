#include"head.h"

//开始定义链队列
typedef struct QNode
{
	Customer data;
	struct QNode *next;
}QNode, *QueuePtr;
typedef struct
{
	QueuePtr front;	//队头指针 
	QueuePtr rear;	//队尾指针 
}LinkQueue;

//链队列的初始化 
Status InitQueue(LinkQueue &Q)
{
	//构造一个空队列Q 
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	Q.front->next=NULL;	//头节点的指针域置空 
	return OK;
}

//入队
Status EnQueue(LinkQueue &Q, Customer e)
{
	//插入元素e为Q的新的队尾元素
	QueuePtr p;
	p=(QueuePtr)malloc(sizeof(QNode));
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;	//插入队尾的后方
	Q.rear=p;	//修改队尾指针 
	return OK; 
 } 

//出队
Status DeQueue(LinkQueue &Q, Customer &e)
{
	//删除Q的队头元素，用e返回其值
	QueuePtr p;
	if(Q.front==Q.rear)
	return ERROR;	//若队列为空，则返回ERROR
	p=Q.front->next;	//p指向队头元素 
	e=p->data;
	Q.front->next=p->next;
	if(Q.rear==p)
	Q.rear=Q.front;	//最后一个头节点被删，队尾指针指向头节点 
	free(p);
	return OK;
 } 

//计算队列元素的个数 
int length_of_Queue(LinkQueue &q)
{
	int count = 0;
	QNode *p = q.front->next;
	
	while(p)
	{		
		count++;
		p = p->next;
	}
	return count;
}

//取队头元素
Customer GetHead(LinkQueue Q)
{
	//返回Q的队头元素，不修改队头指针 
	if(Q.front!=Q.rear)
	return Q.front->next->data;	//返回队头元素的值，队头元素不变 
 } 

/************************队列操作结束******************************/

//定义时间类型
typedef struct Time
{
	int hour;
	int minute;
}Time;

//定义窗口的相关类型
typedef struct Window
{
	double rest_service_time;				//当前客户办理业务的剩余时长
	double total_rest_service_time;		//总剩余服务时长
	double total_wait_time;					//累计总等待时长
	LinkQueue Q;									//排队队列
}Window;

//定义银行的相关类型
typedef struct Bank
{
	Time open_time;										//上班时间
	Time close_time;										//下班时间
	int total_time;											//上班时长
	Status mid_rest;										//是否午休
	Window windows[WINDOWS];					//值班窗口数
	LinkQueue customer_queue;						//已生成的顾客队列（可选）
	int total_person;										//需要服务的总人数
	int length[12];											//队列时刻长度
	int customer_time;										//顾客一天需要服务的总时长
}Bank;


//银行信息的初始化
void Init_Bank(Bank &bank)		//不要忘记&！！！！！！
{
	double a1,a2;
	int i;
	//时间初始化
	printf("请输入上班时间(24时制,格式:'时:分'):");
	scanf("%d:%d",&bank.open_time.hour,&bank.open_time.minute);
	printf("请输入下班时间(24时制,格式:'时:分'):");
	scanf("%d:%d",&bank.close_time.hour,&bank.close_time.minute);
	a1=bank.open_time.hour+bank.open_time.minute/60.0;
	a2=bank.close_time.hour+bank.close_time.minute/60.0;
	bank.total_time=a2-a1;		//银行开门的总时长	建议为整数，否则rand()%会报错
	printf("工作时长为：%d小时\n",bank.total_time);

	//初始化服务窗口
	for(i=0;i<WINDOWS;i++)
	{
		bank.windows[i].rest_service_time=0;
		bank.windows[i].total_rest_service_time=0;
		bank.windows[i].total_wait_time=0;
		InitQueue(bank.windows[i].Q);
	}

	bank.total_person=0;			//需要服务的总人数置为0
}

//查找对应时刻的队列元素
void find(Bank &bank, Customer arr[][12] , int now)
{
	LinkQueue q=bank.customer_queue;
	QNode *p = q.front->next;
	int i=0;
	while(p)
	{
		if(p->data.arrival_time==now)
		{
			arr[now][i].arrival_time=p->data.arrival_time;
			arr[now][i].id=p->data.id;
			arr[now][i].service_time=p->data.service_time;
			i++;
		}
		bank.length[now]=i;		//now时刻有多少人还在
		p = p->next;
	}
}

//生成所有顾客
void genCustomer(Bank &bank,int p)
{
	int i;
	bank.customer_time=0;
	for(i=0;i<p;i++)
	{
		Customer e;
		e.id=i+1;
		e.arrival_time=rand()%(bank.total_time-0);
		e.service_time=(rand()%(TIME_MAX-TIME_MIN+1)+TIME_MIN);

		EnQueue(bank.customer_queue,e);
		printf("客户%3.3d于%2.2d点抵达，预计服务时间为%2.2d分钟\n",e.id,e.arrival_time+bank.open_time.hour,e.service_time);
		bank.customer_time+=e.service_time;
	}
}

//按到达时间分类
void classification(Bank &bank, Customer arr[][12])
{
	int now;

	for(now=0;now<=bank.total_time;now++)
	{
		find(bank,arr,now);
	}
}

void EventDriven(Bank &bank, Customer &cur_customer, int now)
{
    // 找到最短服务窗口队列
	int i;
	
	int tmp = length_of_Queue(bank.windows[0].Q);
	int min=0;

	for (i = 0; i < WINDOWS; ++i) 
	{
		if (length_of_Queue(bank.windows[i].Q) < tmp) 
		{
			min = i;
			//printf("min:%d\n",min);
			break;
		}
	}
	// 顾客入队
	EnQueue(bank.windows[min].Q, cur_customer);

	// 统计时长
	if (bank.windows[min].total_rest_service_time > 0)							// 1. 统计等待时长；要考虑到每个人的等待时长，所以要累加剩余服务时长
	{																									
		bank.windows[min].total_wait_time += bank.windows[min].total_rest_service_time;
	}
	bank.windows[min].total_wait_time += cur_customer.service_time/60.0; // 2. 统计服务时长
	if (bank.windows[min].total_rest_service_time == 0) 
	{
		bank.windows[min].rest_service_time = cur_customer.service_time/60.0; // 3. 总剩余服务时长为0，说明该客户为当前队列“第一个”客户
	}
	bank.windows[min].total_rest_service_time += cur_customer.service_time/60.0; // 4. 刷新该队列的剩余服务时长
	//}
}

void printStatus(Bank &bank, int now)
{ // 打印当前队列状态
	cout << "=====CLOCK[" << now+bank.open_time.hour << "]=====" << endl;
    for (int i = 0; i < WINDOWS; ++i) 
	{
		QNode* p = bank.windows[i].Q.front->next;
        cout << "Queue[" << i << "] ";
        while (p != NULL) 
		{
			cout << p->data.id << " ";
            p = p->next;
        }
        cout << "[TAIL]" << endl;
    }
}

void Clock(Bank &bank, Customer &e, Customer arr[][12])
{
	int now;		//定义时间变量
	int i,j;
	double a,b;
	for(now=0;now<=bank.total_time;now++)	//时间流逝
	{
		for(i=0;i<WINDOWS;i++)						//时间流逝，每个窗口的剩余服务时长-1
		{
			for(j=0;j<bank.length[now]+1;j++)
			{
				if(bank.windows[i].total_rest_service_time>0)		// 若不满足条件，则该服务窗口队列已为空
				{
					a=bank.windows[i].rest_service_time;
					b=0;

						while(1)
						{

							e=GetHead(bank.windows[i].Q);		//取第i个窗口的第一个人
							b+=e.service_time/60.0;				//把第一个人所需的服务时间累加到b这个变量里面
							if(b<1&&b>0)								//如果这个时间在0~1之间，说明这个人在这一个小时之内服务完了
							{
								DeQueue(bank.windows[i].Q,e);			//这个人该出队了
								//更新窗口的服务时间
								bank.windows[i].rest_service_time-=e.service_time/60.0;
								bank.windows[i].total_rest_service_time-=e.service_time/60.0;
							}
							else
							{
								e.service_time=(b-1)*60;			//累计和超过一个小时就更新这个人的服务时长

								if(length_of_Queue(bank.windows[i].Q)!=0)		// 窗口队列不为0，继续办理下一个客户
								{
									e=GetHead(bank.windows[i].Q);									//取该窗口队头
									bank.windows[i].rest_service_time+=e.service_time/60.0;		//确定服务时间
										
								}
								break;							
							}												
						}				
					}
				}
			}
			if(length_of_Queue(bank.customer_queue)>0)			// 如果还有剩余顾客
			{

				for(j=0;j<12;j++)
				{
					Customer cur_customer=arr[now][j];

					if(cur_customer.arrival_time==now)
					{
					
						EventDriven(bank, cur_customer, now);		// 找到最短服务窗口队列
					}
				}
			}
			printStatus(bank, now);
	}		
}

int main()
{
	srand((unsigned int)time(NULL));		//通过时间戳生成随机数发生种子

	Bank bank;
	double timer;		//计时器
	int p;				//顾客数
	int i,j;
	Customer e;

	Customer arr[12][12];		//根据到达时间不同分类储存顾客
	//初始化顾客队列（该队列为今天顾客的总队列，与窗口队列区别开来）
	InitQueue(bank.customer_queue);
	//初始化银行
	Init_Bank(bank);
	
	//生成所有顾客
	p=(rand()%(PERSON_MAX-PERSON_MIN+1))+1;
	printf("一共有%d个顾客\n",p);
	genCustomer(bank,p);
	bank.total_person=p;
	classification(bank,arr);
	//开始一天的工作
	Clock(bank,e,arr);
	printf("客户一天的平均逗留时长为：%.2f分钟\n客户一周的平均逗留时长为：%.2f分钟\n",
		(double)bank.customer_time/bank.total_person,(double)bank.customer_time/bank.total_person*7);
	system("pause");
	return 0;
}