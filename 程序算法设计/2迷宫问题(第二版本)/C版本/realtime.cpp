#include "realtime.h"

int Realtime_deviation(real_time time1, real_time time2) {
	return (time2.hour - time1.hour - 1) * 60 + time2.minute + 60 - time1.minute;
}
