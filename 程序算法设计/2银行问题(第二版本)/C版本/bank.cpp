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
	bank.serve_time = Realtime_deviation(work, quite);  //�������з������ʱ��
	for (int i = 0; i < 4; i++) {
		Window_Init(bank.windows[i]);  // ��ʼ�����ڶ���
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
		if (Bank.windows[window_num].customer_wait_number != 0) {  // �жϵ�ǰ���ڶ�����û�й˿�
			Bank.windows->wait_time_total += Bank.windows->customer_wait_number;  // ���Ӷ���ʱ��(д���ǵȴ���ʵ�Ƕ���)
			Customer_Decrease_Serve_Time(Bank.windows[window_num]);  // ���ٹ˿ͷ���ʱ��
			if (Bank.windows[window_num].queue.head->next->data.server_time == 0) {
				Queue_De(Bank.windows[window_num].queue, e);  //����ʱ��û�˾͸�ү����
				Bank.windows[window_num].customer_wait_number--;
			}//��ʵ����������˵�ǰ�˿ͷ���ʱ�䣬���ǲ����ٶ�д�����ˣ�����������Ϊʺɽ��
		}
	}
	return Window_OK;
}

int Bank_Serve(Bank& Bank, Customers C) {
	int time = 0;
	int now_customer = 1;
	int total_wait_time = 0;
	if (Bank.break_state == noBreak){  //  û������ģʽ
		for (time = 0; time <= Realtime_deviation(Bank.work, Bank.quite); time++) { // ģ�����ʱ������
			if (time == C.cer[now_customer].arrive_time) { //���ﵱǰ�˿ͷ���ʱ��
				Windows_Line_Up(Bank, C.cer[now_customer]);   //�˿��ŶӺͽ������
				now_customer++;
			}
			Windows_Serve(Bank); //  ���ڷ�����
		}
		for (int i = 0; i < 4; i++) {
			total_wait_time += Bank.windows[i].wait_time_total;
		}
	}
	printf("%d", total_wait_time);
	return Bank_OK;
}