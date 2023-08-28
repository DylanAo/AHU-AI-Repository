#include"head.h"

//��ʼ����������
typedef struct QNode
{
	Customer data;
	struct QNode *next;
}QNode, *QueuePtr;
typedef struct
{
	QueuePtr front;	//��ͷָ�� 
	QueuePtr rear;	//��βָ�� 
}LinkQueue;

//�����еĳ�ʼ�� 
Status InitQueue(LinkQueue &Q)
{
	//����һ���ն���Q 
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	Q.front->next=NULL;	//ͷ�ڵ��ָ�����ÿ� 
	return OK;
}

//���
Status EnQueue(LinkQueue &Q, Customer e)
{
	//����Ԫ��eΪQ���µĶ�βԪ��
	QueuePtr p;
	p=(QueuePtr)malloc(sizeof(QNode));
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;	//�����β�ĺ�
	Q.rear=p;	//�޸Ķ�βָ�� 
	return OK; 
 } 

//����
Status DeQueue(LinkQueue &Q, Customer &e)
{
	//ɾ��Q�Ķ�ͷԪ�أ���e������ֵ
	QueuePtr p;
	if(Q.front==Q.rear)
	return ERROR;	//������Ϊ�գ��򷵻�ERROR
	p=Q.front->next;	//pָ���ͷԪ�� 
	e=p->data;
	Q.front->next=p->next;
	if(Q.rear==p)
	Q.rear=Q.front;	//���һ��ͷ�ڵ㱻ɾ����βָ��ָ��ͷ�ڵ� 
	free(p);
	return OK;
 } 

//�������Ԫ�صĸ��� 
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

//ȡ��ͷԪ��
Customer GetHead(LinkQueue Q)
{
	//����Q�Ķ�ͷԪ�أ����޸Ķ�ͷָ�� 
	if(Q.front!=Q.rear)
	return Q.front->next->data;	//���ض�ͷԪ�ص�ֵ����ͷԪ�ز��� 
 } 

/************************���в�������******************************/

//����ʱ������
typedef struct Time
{
	int hour;
	int minute;
}Time;

//���崰�ڵ��������
typedef struct Window
{
	double rest_service_time;				//��ǰ�ͻ�����ҵ���ʣ��ʱ��
	double total_rest_service_time;		//��ʣ�����ʱ��
	double total_wait_time;					//�ۼ��ܵȴ�ʱ��
	LinkQueue Q;									//�ŶӶ���
}Window;

//�������е��������
typedef struct Bank
{
	Time open_time;										//�ϰ�ʱ��
	Time close_time;										//�°�ʱ��
	int total_time;											//�ϰ�ʱ��
	Status mid_rest;										//�Ƿ�����
	Window windows[WINDOWS];					//ֵ�ര����
	LinkQueue customer_queue;						//�����ɵĹ˿Ͷ��У���ѡ��
	int total_person;										//��Ҫ�����������
	int length[12];											//����ʱ�̳���
	int customer_time;										//�˿�һ����Ҫ�������ʱ��
}Bank;


//������Ϣ�ĳ�ʼ��
void Init_Bank(Bank &bank)		//��Ҫ����&������������
{
	double a1,a2;
	int i;
	//ʱ���ʼ��
	printf("�������ϰ�ʱ��(24ʱ��,��ʽ:'ʱ:��'):");
	scanf("%d:%d",&bank.open_time.hour,&bank.open_time.minute);
	printf("�������°�ʱ��(24ʱ��,��ʽ:'ʱ:��'):");
	scanf("%d:%d",&bank.close_time.hour,&bank.close_time.minute);
	a1=bank.open_time.hour+bank.open_time.minute/60.0;
	a2=bank.close_time.hour+bank.close_time.minute/60.0;
	bank.total_time=a2-a1;		//���п��ŵ���ʱ��	����Ϊ����������rand()%�ᱨ��
	printf("����ʱ��Ϊ��%dСʱ\n",bank.total_time);

	//��ʼ�����񴰿�
	for(i=0;i<WINDOWS;i++)
	{
		bank.windows[i].rest_service_time=0;
		bank.windows[i].total_rest_service_time=0;
		bank.windows[i].total_wait_time=0;
		InitQueue(bank.windows[i].Q);
	}

	bank.total_person=0;			//��Ҫ�������������Ϊ0
}

//���Ҷ�Ӧʱ�̵Ķ���Ԫ��
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
		bank.length[now]=i;		//nowʱ���ж����˻���
		p = p->next;
	}
}

//�������й˿�
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
		printf("�ͻ�%3.3d��%2.2d��ִԤ�Ʒ���ʱ��Ϊ%2.2d����\n",e.id,e.arrival_time+bank.open_time.hour,e.service_time);
		bank.customer_time+=e.service_time;
	}
}

//������ʱ�����
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
    // �ҵ���̷��񴰿ڶ���
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
	// �˿����
	EnQueue(bank.windows[min].Q, cur_customer);

	// ͳ��ʱ��
	if (bank.windows[min].total_rest_service_time > 0)							// 1. ͳ�Ƶȴ�ʱ����Ҫ���ǵ�ÿ���˵ĵȴ�ʱ��������Ҫ�ۼ�ʣ�����ʱ��
	{																									
		bank.windows[min].total_wait_time += bank.windows[min].total_rest_service_time;
	}
	bank.windows[min].total_wait_time += cur_customer.service_time/60.0; // 2. ͳ�Ʒ���ʱ��
	if (bank.windows[min].total_rest_service_time == 0) 
	{
		bank.windows[min].rest_service_time = cur_customer.service_time/60.0; // 3. ��ʣ�����ʱ��Ϊ0��˵���ÿͻ�Ϊ��ǰ���С���һ�����ͻ�
	}
	bank.windows[min].total_rest_service_time += cur_customer.service_time/60.0; // 4. ˢ�¸ö��е�ʣ�����ʱ��
	//}
}

void printStatus(Bank &bank, int now)
{ // ��ӡ��ǰ����״̬
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
	int now;		//����ʱ�����
	int i,j;
	double a,b;
	for(now=0;now<=bank.total_time;now++)	//ʱ������
	{
		for(i=0;i<WINDOWS;i++)						//ʱ�����ţ�ÿ�����ڵ�ʣ�����ʱ��-1
		{
			for(j=0;j<bank.length[now]+1;j++)
			{
				if(bank.windows[i].total_rest_service_time>0)		// ����������������÷��񴰿ڶ�����Ϊ��
				{
					a=bank.windows[i].rest_service_time;
					b=0;

						while(1)
						{

							e=GetHead(bank.windows[i].Q);		//ȡ��i�����ڵĵ�һ����
							b+=e.service_time/60.0;				//�ѵ�һ��������ķ���ʱ���ۼӵ�b�����������
							if(b<1&&b>0)								//������ʱ����0~1֮�䣬˵�����������һ��Сʱ֮�ڷ�������
							{
								DeQueue(bank.windows[i].Q,e);			//����˸ó�����
								//���´��ڵķ���ʱ��
								bank.windows[i].rest_service_time-=e.service_time/60.0;
								bank.windows[i].total_rest_service_time-=e.service_time/60.0;
							}
							else
							{
								e.service_time=(b-1)*60;			//�ۼƺͳ���һ��Сʱ�͸�������˵ķ���ʱ��

								if(length_of_Queue(bank.windows[i].Q)!=0)		// ���ڶ��в�Ϊ0������������һ���ͻ�
								{
									e=GetHead(bank.windows[i].Q);									//ȡ�ô��ڶ�ͷ
									bank.windows[i].rest_service_time+=e.service_time/60.0;		//ȷ������ʱ��
										
								}
								break;							
							}												
						}				
					}
				}
			}
			if(length_of_Queue(bank.customer_queue)>0)			// �������ʣ��˿�
			{

				for(j=0;j<12;j++)
				{
					Customer cur_customer=arr[now][j];

					if(cur_customer.arrival_time==now)
					{
					
						EventDriven(bank, cur_customer, now);		// �ҵ���̷��񴰿ڶ���
					}
				}
			}
			printStatus(bank, now);
	}		
}

int main()
{
	srand((unsigned int)time(NULL));		//ͨ��ʱ��������������������

	Bank bank;
	double timer;		//��ʱ��
	int p;				//�˿���
	int i,j;
	Customer e;

	Customer arr[12][12];		//���ݵ���ʱ�䲻ͬ���ഢ��˿�
	//��ʼ���˿Ͷ��У��ö���Ϊ����˿͵��ܶ��У��봰�ڶ�����������
	InitQueue(bank.customer_queue);
	//��ʼ������
	Init_Bank(bank);
	
	//�������й˿�
	p=(rand()%(PERSON_MAX-PERSON_MIN+1))+1;
	printf("һ����%d���˿�\n",p);
	genCustomer(bank,p);
	bank.total_person=p;
	classification(bank,arr);
	//��ʼһ��Ĺ���
	Clock(bank,e,arr);
	printf("�ͻ�һ���ƽ������ʱ��Ϊ��%.2f����\n�ͻ�һ�ܵ�ƽ������ʱ��Ϊ��%.2f����\n",
		(double)bank.customer_time/bank.total_person,(double)bank.customer_time/bank.total_person*7);
	system("pause");
	return 0;
}