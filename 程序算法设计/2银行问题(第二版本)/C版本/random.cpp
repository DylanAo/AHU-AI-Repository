#include "random.h"
#include <time.h>
#include <stdlib.h>
#include "customer.h"
#include <stdarg.h>

int random(Random_State use_state, ...) {
	va_list arg_list;  //用个不定参数来写一下，其实用类的重载或许更好
	va_start(arg_list, use_state);
	int work_time = va_arg(arg_list, int);
	if (Debug_State) {
		srand((unsigned)time(NULL) + (unsigned)rand());  //不开启Debug模式
	}
	else{
		srand(Debug_Seed);  //开启Debug模式
	}
	if (use_state == Customer_Number_State) {  //顾客数量随机数
		return (rand() % (Customer_Number_Max - Customer_Number_Min + 1)) + Customer_Number_Min;
	}
	if (use_state == Customer_Serve_Time_State) {  //顾客服务时间随机数
		return (rand() % (Serve_Time_Max - Serve_Time_Min + 1)) + Serve_Time_Min;
	}
	if (use_state == Customer_Arreive_Time_State) {  //顾客到达时间随机数
		return (rand() % (work_time + 1));
	}
}
