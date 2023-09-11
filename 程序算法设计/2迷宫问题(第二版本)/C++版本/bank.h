#pragma once

#include"realtime.h"
#include"queue.h"

#define CUS_NUM 1
#define RES_TIM 2
#define TOTAL_CUS_TIME 3

#define WORK 1
#define OFF 2
#define BEGIN_REST 3
#define END_REST 4

#define REST 2
#define DUTY 3

class Window {

private:
	Queue queue;
	int total_cus_time;
	int rest_time;
	int customer_number;

public:
	Window();
	bool En(Customer cer);
	bool De();
	int get(int mode);
	bool run();
	bool clear();
};

class Bank {

private:
	realtime working_time;
	realtime off_time;
	realtime rest_begin_time;
	realtime rest_end_time;
	Window window_1;
	Window window_2;
	Window window_3;
	Window window_4;
	bool rest_state;
	bool duty_window_state;

	int get_min_customer_window();
	bool De(int win_index);

public:
	Bank(realtime Work, realtime Off, bool break_state, bool duty_win, realtime begin, realtime end);
	Bank(realtime Work, realtime Off);
	bool En_duty(Customer cer);
	bool En(Customer cer);
	bool De();
	bool run(int mode);
	int get_total_wait_time();
	bool reset(realtime Work, realtime Off);
	bool reset(realtime Work, realtime Off, bool break_state, bool duty_win, realtime begin, realtime end);
	bool isRest();
	bool isDutyWindow();
	realtime get_time(int time_mode);
};