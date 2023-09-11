#ifndef CUSTOMER_H
#define CUSTOMER_H

#define Customer_Number_Max 15  //���˿�����
#define Customer_Number_Min 6  //���ٹ˿�����
#define Serve_Time_Max 60  //���˿ͷ������ʱ��
#define Serve_Time_Min 5  //���ٹ˿ͷ������ʱ��
#define Customer_OK 1

#define NULL 0
typedef int State;  //������ؽ��״̬
#define QueueisSucess 1  //���в����ɹ�
#define QueueisEmpty 0   //����Ϊ��

typedef struct {
	int ID;
	int arrive_time;  //��Ե���ʱ��
	int server_time;  //��Է���ʱ��
}Customer;

typedef struct {
	int number;
	Customer cer[Customer_Number_Max]; // �±�0�ǲ����������վ
}Customers;

//���У�����
typedef struct Node {
	Customer data;
	struct Node* next;
}QNode;

typedef struct {
	QNode* head;  //��ͷ
	QNode* rear;  //��β
}Queue;

State Queue_Init(Queue& Q);  //��ʼ������
State Queue_En(Queue& Q, Customer e);  //���
State Queue_De(Queue& Q, Customer& e);  //����
Customer Queue_Get_HeadData(Queue Q);  //��ö�ͷԪ��ֵ
int Queue_Get_Length(Queue Q);  //��ö��г�
State Queue_Copy(Queue Q, Queue Q_Copy);

int Customer_Init(Customer& Customer, int ID, int time);
int Customers_Init(Customers& Customers, int time);
void Customers_Sort(Customers& Customers);
#endif // !_customer_h_

