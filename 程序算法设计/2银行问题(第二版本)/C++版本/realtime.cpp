#include"realtime.h"

realtime::realtime() {
	hour = 0;
	minute = 0;
}

realtime::realtime(int hour, int minute) {
	this->hour = hour;
	this->minute = minute;
}

int realtime::operator-(realtime t){
	if (this->hour == t.hour) {
		return this->minute - t.minute;
	}
	else {
		return (this->hour - t.hour - 1) * 60 + 60 - t.minute + this->minute;
	}
}

std::ostream& operator<<(std::ostream& os, realtime t) {
	os << t.hour << " hours " << t.minute << " minutes";
	return os;
};

bool realtime::set(realtime T) {
	this->hour = T.hour;
	this->minute = T.minute;
	return true;
}
