#include"bank.h"
#include<stdio.h>

int Window_Init(Window& win) {
	win.customer_wait_number = 0;
	win.rest_serve_time = 0;
	win.wait_time_total = 0;
	Queue_Init(win.queue);
	return Window_OK;
}

int Bank_Init(Bank& bank, real_time work, real_time quite, Break_State break_state) {
	bank.work = work;
	bank.quite = quite;
	bank.break_state = break_state;
	bank.serve_time = Realtime_deviation(work, quite);  //计算银行服务相对时间
	for (int i = 0; i < 4; i++) {
		Window_Init(bank.windows[i]);  // 初始化窗口队列
	}
	return Bank_OK;
}

int Windows_Min_Customer(Bank Bank){
	int min_window = 0;
	for (int i = 1; i < 3; i++) {
		if (Bank.windows[i].customer_wait_number > Bank.windows[i + 1].customer_wait_number) {
			min_window = i + 1;
		}
	}
	return min_window;
}

void Customer_Decrease_Serve_Time(Window window) {
	window.queue.head->next->data.server_time--;
}

int Windows_Line_Up(Bank& Bank, Customer C) {
	int min_window = Windows_Min_Customer(Bank);
	Queue_En(Bank.windows[min_window].queue, C);
	Bank.windows[min_window].customer_wait_number++;
	return Window_OK;
}

int Windows_Serve(Bank& Bank) {
	Customer e;
	int window_num = 0;
	for (window_num = 0; window_num < 4; window_num++) {
		if (Bank.windows[window_num].customer_wait_number != 0) {  // 判断当前窗口队列有没有顾客
			Bank.windows->wait_time_total += Bank.windows->customer_wait_number;  // 增加逗留时间(写的是等待其实是逗留)
			Customer_Decrease_Serve_Time(Bank.windows[window_num]);  // 减少顾客服务时间
			if (Bank.windows[window_num].queue.head->next->data.server_time == 0) {
				Queue_De(Bank.windows[window_num].queue, e);  //服务时间没了就给爷出队
				Bank.windows[window_num].customer_wait_number--;
			}//其实这里我设计了当前顾客服务时间，但是不想再多写代码了，就这样，成为屎山了
		}
	}
	return Window_OK;
}

int Bank_Serve(Bank& Bank, Customers C) {
	int time = 0;
	int now_customer = 1;
	int total_wait_time = 0;
	if (Bank.break_state == noBreak){  //  没有午休模式
		for (time = 0; time <= Realtime_deviation(Bank.work, Bank.quite); time++) { // 模拟相对时间流逝
			if (time == C.cer[now_customer].arrive_time) { //到达当前顾客服务时间
				Windows_Line_Up(Bank, C.cer[now_customer]);   //顾客排队和进入队列
				now_customer++;
			}
			Windows_Serve(Bank); //  窗口服务函数
		}
		for (int i = 0; i < 4; i++) {
			total_wait_time += Bank.windows[i].wait_time_total;
		}
	}
	printf("%d", total_wait_time);
	return Bank_OK;
}