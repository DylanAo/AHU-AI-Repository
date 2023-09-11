#ifndef REALTIME_H
#define REALTIME_H

typedef struct {
	int hour;
	int minute;
}real_time;

#define Time_OK 1;  //真实时间操作正常
#define Time_Range_Error 0;  //时间超出范围(时针:0-24,分针0-60)

int Realtime_deviation(real_time time1, real_time time2);  //计算真实时间差值，返回分钟
#endif // !_realtime_h_
