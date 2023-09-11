#include "random.h"
#include <time.h>
#include <stdlib.h>
#include "customer.h"
#include <stdarg.h>

int random(Random_State use_state, ...) {
	va_list arg_list;  //�ø�����������дһ�£���ʵ��������ػ������
	va_start(arg_list, use_state);
	int work_time = va_arg(arg_list, int);
	if (Debug_State) {
		srand((unsigned)time(NULL) + (unsigned)rand());  //������Debugģʽ
	}
	else{
		srand(Debug_Seed);  //����Debugģʽ
	}
	if (use_state == Customer_Number_State) {  //�˿����������
		return (rand() % (Customer_Number_Max - Customer_Number_Min + 1)) + Customer_Number_Min;
	}
	if (use_state == Customer_Serve_Time_State) {  //�˿ͷ���ʱ�������
		return (rand() % (Serve_Time_Max - Serve_Time_Min + 1)) + Serve_Time_Min;
	}
	if (use_state == Customer_Arreive_Time_State) {  //�˿͵���ʱ�������
		return (rand() % (work_time + 1));
	}
}
