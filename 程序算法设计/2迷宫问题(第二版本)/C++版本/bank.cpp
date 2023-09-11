#include"bank.h"

Window::Window() {
	rest_time = 0;
	total_cus_time = 0;
	customer_number = 0;
}

bool Window::En(Customer cer) {
	queue.En(cer);
	customer_number++;
	rest_time = cer.get(SERVE_TIME);
	return true;
}

bool Window::De() {
	if (customer_number == 0) {
		return false;
	}
	else {
		queue.De();
		customer_number--;
	}
	return true;
}

Bank::Bank(realtime Work, realtime Off,bool break_state, bool duty_win , realtime begin, realtime end) {
	working_time = Work;
	off_time = Off;
	rest_state = break_state;
	duty_window_state = duty_win;
	this->rest_begin_time = begin;
	this->rest_end_time = end;
}

Bank::Bank(realtime Work, realtime Off) {
	working_time = Work;
	off_time = Off;
	rest_state = 0;
	duty_window_state = 0;
}

int Bank::get_min_customer_window() {
	int win_1 = window_1.get(CUS_NUM);
	int win_2 = window_2.get(CUS_NUM);
	int win_3 = window_3.get(CUS_NUM);
	int win_4 = window_4.get(CUS_NUM);
	int min_num = win_1;
	int min_win = 1;
	if (min_num > win_2) {
		min_win = 2;
	}
	if (min_num > win_3) {
		min_win = 3;
	}
	if (min_num > win_4) {
		min_win = 4;
	}
	return min_win;
}

int Window::get(int mode) {
	switch (mode){
	case CUS_NUM:
		return customer_number;
		break;
	case RES_TIM:
		return rest_time;
		break;
	case TOTAL_CUS_TIME:
		return total_cus_time;
		break;
	default:
		return 0;
		break;
	}
}

bool Bank::En(Customer cer) {
	int win_index = get_min_customer_window();
	switch (win_index){
	case 1:
		window_1.En(cer);
		break;
	case 2:
		window_2.En(cer);
		break;
	case 3:
		window_3.En(cer);
		break;
	case 4:
		window_4.En(cer);
		break;
	default:
		return false;
		break;
	}
	return true;
}

bool Bank::En_duty(Customer cer) {
	window_1.En(cer);
	return true;
}

bool Bank::De(int win_index) {

	switch (win_index) {
	case 1:
		window_1.De();
		break;
	case 2:
		window_2.De();
		break;
	case 3:
		window_3.De();
		break;
	case 4:
		window_4.De();
		break;
	default:
		return false;
		break;
	}
	return true;
}

bool Bank::De() {
	if (window_1.get(RES_TIM) == 0) {
		De(1);
	}
	if (window_2.get(RES_TIM) == 0) {
		De(2);
	}
	if (window_3.get(RES_TIM) == 0) {
		De(3);
	}
	if (window_4.get(RES_TIM) == 0) {
		De(4);
	}
	return true;
}

bool Window::run() {
	if (rest_time <= 0) {
		return false;
	}
	else {
		rest_time--;
		total_cus_time += customer_number;
		return true;
	}
}

bool Bank::run(int mode) {
	if (mode == WORK) {
		if (window_1.get(CUS_NUM) != 0) {
			window_1.run();
		}
		if (window_2.get(CUS_NUM) != 0) {
			window_2.run();
		}
		if (window_3.get(CUS_NUM) != 0) {
			window_3.run();
		}
		if (window_4.get(CUS_NUM) != 0) {
			window_4.run();
		}
	}
	else {
		if (mode == DUTY) {
			if (window_1.get(CUS_NUM) != 0) {
				window_1.run();
			}
		}
	}
	return true;
}

int Bank::get_total_wait_time() {
	return window_1.get(TOTAL_CUS_TIME) + window_2.get(TOTAL_CUS_TIME) + window_3.get(TOTAL_CUS_TIME) + window_4.get(TOTAL_CUS_TIME);
}

bool Window::clear() {
	total_cus_time = 0;
	rest_time = 0;
	customer_number = 0;
	queue.clear();
	return true;
}

bool Bank::reset(realtime Work, realtime Off) {
	working_time = Work;
	off_time = Off;
	rest_state = 0;
	duty_window_state = 0;
	window_1.clear();
	window_2.clear();
	window_3.clear();
	window_4.clear();
	return true;
}

bool Bank::reset(realtime Work, realtime Off, bool break_state, bool duty_win, realtime begin, realtime end) {
	working_time = Work;
	off_time = Off;
	rest_state = break_state;
	duty_window_state = duty_win;
	rest_begin_time = begin;
	rest_end_time = end;
	window_1.clear();
	window_2.clear();
	window_3.clear();
	window_4.clear();
	return true;
}

bool Bank::isRest() {
	return rest_state;
}

bool Bank::isDutyWindow() {
	return duty_window_state;
}

realtime Bank::get_time(int time_mode) {
	switch (time_mode){
	case WORK:
		return working_time;
		break;
	case OFF:
		return off_time;
		break;
	case BEGIN_REST:
		return rest_begin_time;
		break;
	case END_REST:
		return rest_end_time;
		break;
	}
}