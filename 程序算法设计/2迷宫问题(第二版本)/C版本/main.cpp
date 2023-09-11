#include "head.h"

int main() {
	// 初始化部分
	Customers C;
	Bank bank;
	real_time work;
	real_time quit;
	work.hour = 9;
	work.minute = 50;
	quit.hour = 11;
	quit.minute = 30;
	real_time rest_begin;
	real_time rest_end;
	rest_begin.hour = 12;
	rest_begin.minute = 0;
	rest_end.hour = 14;
	rest_end.minute = 0;
	Bank_Init(bank, work, quit, noBreak);
	Customers_Init(C, Realtime_deviation(work, quit));
	//Bank_Serve(bank, C);


	int time = 0;
	int now_customer = 1;
	int total_wait_time = 0;
	int relave_rest_begin = Realtime_deviation(bank.work, rest_begin);
	int relave_rest_end = relave_rest_begin + Realtime_deviation(rest_begin, rest_end);
	for (time = 0; time <= Realtime_deviation(bank.work, bank.quite); time++) { // 模拟相对时间流逝
		
		if (time == C.cer[now_customer].arrive_time) { //到达当前顾客服务时间
			Windows_Line_Up(bank, C.cer[now_customer]);   //顾客排队和进入队列
			now_customer++;
		}
		if (time <= relave_rest_end && time >= relave_rest_begin) {
			//少窗口逻辑
		}
		else{
			Windows_Serve(bank); //  窗口服务函数
		}
		
		

		
	}
	for (int i = 0; i < 4; i++) {
		total_wait_time += bank.windows[i].wait_time_total;
	}
	printf("%d", total_wait_time);
	return Bank_OK;
	
}