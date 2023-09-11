#ifndef REALTIME_H
#define REALTIME_H

typedef struct {
	int hour;
	int minute;
}real_time;

#define Time_OK 1;  //��ʵʱ���������
#define Time_Range_Error 0;  //ʱ�䳬����Χ(ʱ��:0-24,����0-60)

int Realtime_deviation(real_time time1, real_time time2);  //������ʵʱ���ֵ�����ط���
#endif // !_realtime_h_
