#include<iostream>
#include"realtime.h"
#include"queue.h"
#include"bank.h"
#include"day.h"

using namespace std;

int main() {
	realtime working_time(8, 0);
	realtime off_time(17, 0);
	realtime begin_rest(12, 0);
	realtime end_rest(14, 0);
	realtime saturday_working_time(9,0);
	realtime saturday_off_time(16, 0);

	cout << "无休息" << endl;
	week_run(working_time, off_time, saturday_working_time, saturday_off_time, begin_rest, end_rest, false, false);

	cout << "有休息，无值班" << endl;
	week_run(working_time, off_time, saturday_working_time, saturday_off_time, begin_rest, end_rest, true, false);

	cout << "有休息，有值班" << endl;
	week_run(working_time, off_time, saturday_working_time, saturday_off_time, begin_rest, end_rest, true, true);
}