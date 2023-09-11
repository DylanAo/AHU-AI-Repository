#include "customer.h"
#include"realtime.h"
#include"random.h"
#include "bank.h"

State Queue_Init(Queue& Q) {
	Q.head = Q.rear = new QNode;
	Q.head->next = 0;
	return QueueisSucess;
}

State Queue_En(Queue& Q, Customer e) {
	QNode* p = new QNode;
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return QueueisSucess;
}

State Queue_De(Queue& Q, Customer& e) {
	QNode* p;
	if (Q.head == Q.rear) {
		return QueueisEmpty;  //�նӣ����ض���Ϊ��
	}
	p = Q.head->next;
	e = p->data;
	Q.head->next = p->next;
	if (Q.rear == p) {
		Q.rear = Q.head;  //ɾ����
	}
	delete p;
	return QueueisSucess;
}

Customer Queue_Get_HeadData(Queue Q) {
	if (Q.head != Q.rear) {
		return Q.head->next->data;
	}
}

State Queue_Copy(Queue Q, Queue Q_Copy) {
	Queue p = Q;
	Customer e;
	while (p.head->next != NULL){
		Queue_De(Q, e);
		Queue_En(Q_Copy, e);
	}
	return QueueisSucess;
}

int Queue_Get_Length(Queue Q) {
	int length = 0;
	while (Q.head->next != NULL) {
		length++;
		Q.head->next = Q.head->next->next;
	}
	return length;
}

int Customer_Init(Customer &Customer, int ID, int time) {
	Customer.ID = ID;
	Customer.arrive_time = random(Customer_Arreive_Time_State, time);  //���ɵ���ʱ��
	Customer.server_time = random(Customer_Serve_Time_State);  //���ɷ���ʱ��
	return Customer_OK;
}

int Customers_Init(Customers &Customers, int time) {
	Customers.number = random(Customer_Number_State);  //���ɹ˿�����
	Customer_Init(Customers.cer[0], 0, time);  //��վ��ʼ��
	for (int i = 1; i <= Customers.number; i++) {
		Customer_Init(Customers.cer[i], i, time);  //���ɹ˿�
	}
	Customers_Sort(Customers);  //���յ���ʱ������
	return Customer_OK;
}

void Customers_Sort(Customers& Customers) {  //��������(����̫�鷳�ˣ�Ҫʲô�ٶȣ�û��ð�ݾͲ�����)
	int j = 0;
	for (int i = 2; i <= Customers.number; i++) {
		if (Customers.cer[i].arrive_time < Customers.cer[i - 1].arrive_time) {
			Customers.cer[0] = Customers.cer[i];
			Customers.cer[i] = Customers.cer[i - 1];
			for (j = i - 2; Customers.cer[0].arrive_time < Customers.cer[j].arrive_time && j > 0; j--) {
				Customers.cer[j + 1] = Customers.cer[j];
			}
			Customers.cer[j + 1] = Customers.cer[0];
		}
	}
}

