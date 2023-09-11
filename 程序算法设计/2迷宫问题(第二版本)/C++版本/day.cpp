#include "day.h"

void day_run(Bank& bank, Customers& cs) {
	int customer_index = 1;
	if (!bank.isRest()) { // û����Ϣ
		for (int cycle = 0; cycle <= bank.get_time(OFF) - bank.get_time(WORK); cycle++) {
			while (cs.get(customer_index).get(ARRIVE_TIME) == cycle) { // ��ֹ�ж������ʱ��һ����
				bank.En(cs.get(customer_index));  // �����Ŷ�
				customer_index++;
			}
			bank.De();  // ��ʱ���ˣ�����
			bank.run(WORK);  // ��ʼ���м���
		}
	}
	else{ // ����Ϣ
		for (int cycle = 0; cycle <= bank.get_time(OFF) - bank.get_time(WORK); cycle++) {
			if (cycle <= bank.get_time(END_REST) - bank.get_time(WORK) && cycle >= bank.get_time(BEGIN_REST) - bank.get_time(WORK)) {
				//����Ϣʱ����
				if (bank.isDutyWindow() == true) {  // ��ֵ��
					while (cs.get(customer_index).get(ARRIVE_TIME) == cycle) { // ��ֹ�ж������ʱ��һ����
						bank.En_duty(cs.get(customer_index));  // �����Ŷ�
						customer_index++;
						bank.De();
						bank.run(DUTY);
					}
				}
				else {  //��ֵ��
					bank.En(cs.get(customer_index));  // �����Ŷ�
					customer_index++;
					bank.De();
				}
			}
			else{
				// ����Ϣʱ����
				while (cs.get(customer_index).get(ARRIVE_TIME) == cycle) { // ��ֹ�ж������ʱ��һ����
					bank.En(cs.get(customer_index));  // �����Ŷ�
					customer_index++;
				}
				bank.De();  // ��ʱ���ˣ�����
				bank.run(WORK);  // ��ʼ���м���
			}
		}
	}
	cout << bank.get_total_wait_time() << endl;  //����ܹ�����ʱ��
}


void week_run(realtime work,realtime off, realtime sar_work, realtime sar_off, realtime begin, realtime end, bool rest, bool duty) {
	Customers cs_day_1(250, 100, off - work, 25);
	Customers cs_day_2(250, 100, off - work, 25);
	Customers cs_day_3(250, 100, off - work, 25);
	Customers cs_day_4(250, 100, off - work, 25);
	Customers cs_day_5(250, 100, off - work, 25);
	Customers cs_day_6(250, 100, off - work, 25);

	Bank bank(work, off, rest, duty, begin, end);
	day_run(bank, cs_day_1);
	bank.reset(work, off, rest, duty, begin, end);
	day_run(bank, cs_day_2);
	bank.reset(work, off, rest, duty, begin, end);
	day_run(bank, cs_day_3);
	bank.reset(work, off, rest, duty, begin, end);
	day_run(bank, cs_day_4);
	bank.reset(work, off, rest, duty, begin, end);
	day_run(bank, cs_day_5);
	bank.reset(sar_work,sar_off, rest, duty, begin, end);
	day_run(bank, cs_day_6);
}