#include "head.h"

int main() {
	// ��ʼ������
	Customers C;
	Bank bank;
	real_time work;
	real_time quit;
	work.hour = 9;
	work.minute = 50;
	quit.hour = 11;
	quit.minute = 30;
	real_time rest_begin;
	real_time rest_end;
	rest_begin.hour = 12;
	rest_begin.minute = 0;
	rest_end.hour = 14;
	rest_end.minute = 0;
	Bank_Init(bank, work, quit, noBreak);
	Customers_Init(C, Realtime_deviation(work, quit));
	//Bank_Serve(bank, C);


	int time = 0;
	int now_customer = 1;
	int total_wait_time = 0;
	int relave_rest_begin = Realtime_deviation(bank.work, rest_begin);
	int relave_rest_end = relave_rest_begin + Realtime_deviation(rest_begin, rest_end);
	for (time = 0; time <= Realtime_deviation(bank.work, bank.quite); time++) { // ģ�����ʱ������
		
		if (time == C.cer[now_customer].arrive_time) { //���ﵱǰ�˿ͷ���ʱ��
			Windows_Line_Up(bank, C.cer[now_customer]);   //�˿��ŶӺͽ������
			now_customer++;
		}
		if (time <= relave_rest_end && time >= relave_rest_begin) {
			//�ٴ����߼�
		}
		else{
			Windows_Serve(bank); //  ���ڷ�����
		}
		
		

		
	}
	for (int i = 0; i < 4; i++) {
		total_wait_time += bank.windows[i].wait_time_total;
	}
	printf("%d", total_wait_time);
	return Bank_OK;
	
}