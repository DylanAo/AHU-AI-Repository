#ifndef BANK_H
#define BANK_H

#include "customer.h"
#include "realtime.h"

#define haveBreak 1
#define noBreak 0
#define Duty_Window_Number 1
#define Window_Number 4
#define Bank_OK 1
#define Window_OK 1

typedef int Break_State;

typedef struct {
	Queue queue;
	int wait_time_total; //��ǰ�ܹ��˿͵ȴ�ʱ��
	int customer_wait_number; //��ǰ�ȴ��˿���
	int rest_serve_time;  //��ǰ�˿�ʣ�����ʱ��
}Window;

typedef struct {
	real_time work;
	real_time quite;
	Break_State break_state;
	int serve_time;  //���з������ʱ��
	Window windows[Window_Number];
}Bank;

int Window_Init(Window& win); // ���ڳ�ʼ��
int Bank_Init(Bank& bank, real_time work, real_time quite, Break_State break_state);
int Windows_Line_Up(Bank& Bank, Customer C);
int Windows_Serve(Bank& Bank);
void Customer_Decrease_Serve_Time(Window window);
int Bank_Serve(Bank& Bank, Customers C);
#endif // !_bank_h_
