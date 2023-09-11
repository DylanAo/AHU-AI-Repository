#ifndef CUSTOMER_H
#define CUSTOMER_H

#define Customer_Number_Max 15  //最大顾客人数
#define Customer_Number_Min 6  //最少顾客人数
#define Serve_Time_Max 60  //最大顾客服务相对时间
#define Serve_Time_Min 5  //最少顾客服务相对时间
#define Customer_OK 1

#define NULL 0
typedef int State;  //队列相关结果状态
#define QueueisSucess 1  //队列操作成功
#define QueueisEmpty 0   //队列为空

typedef struct {
	int ID;
	int arrive_time;  //相对到达时间
	int server_time;  //相对服务时间
}Customer;

typedef struct {
	int number;
	Customer cer[Customer_Number_Max]; // 下标0是插入排序的哨站
}Customers;

//队列，链队
typedef struct Node {
	Customer data;
	struct Node* next;
}QNode;

typedef struct {
	QNode* head;  //队头
	QNode* rear;  //队尾
}Queue;

State Queue_Init(Queue& Q);  //初始化队列
State Queue_En(Queue& Q, Customer e);  //入队
State Queue_De(Queue& Q, Customer& e);  //出队
Customer Queue_Get_HeadData(Queue Q);  //获得队头元素值
int Queue_Get_Length(Queue Q);  //获得队列长
State Queue_Copy(Queue Q, Queue Q_Copy);

int Customer_Init(Customer& Customer, int ID, int time);
int Customers_Init(Customers& Customers, int time);
void Customers_Sort(Customers& Customers);
#endif // !_customer_h_

