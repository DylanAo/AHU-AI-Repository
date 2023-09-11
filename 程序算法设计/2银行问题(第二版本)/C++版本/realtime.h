#pragma once
#include<iostream>

class realtime {
private:
	int hour;
	int minute;
public:
	realtime();
	realtime(int hour, int minute);
	int operator-(realtime t);
	friend std::ostream& operator<<(std::ostream& os, realtime t);
	bool set(realtime T);
};