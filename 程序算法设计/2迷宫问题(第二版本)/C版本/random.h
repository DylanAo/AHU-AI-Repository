#ifndef RANDOM_H
#define RANDOM_H


typedef int Random_State;
#define Debug_State 1 // 1Ϊ����ģʽ��0Ϊdebugģʽ;
#define Debug_Seed 114514  //�ó������Ӱ�(��)
#define Customer_Number_State 1  //����˿�����ģʽ
#define Customer_Serve_Time_State 2  //����˿�ʱ��ģʽ
#define Customer_Arreive_Time_State 3 //����˿͵���ʱ��ģʽ

int random(Random_State use_state, ...);// ���������
#endif // !_random_h_
