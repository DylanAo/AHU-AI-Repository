#ifndef RANDOM_H
#define RANDOM_H


typedef int Random_State;
#define Debug_State 1 // 1为正常模式，0为debug模式;
#define Debug_Seed 114514  //好臭的种子啊(恼)
#define Customer_Number_State 1  //随机顾客人数模式
#define Customer_Serve_Time_State 2  //随机顾客时间模式
#define Customer_Arreive_Time_State 3 //随机顾客到达时间模式

int random(Random_State use_state, ...);// 生成随机数
#endif // !_random_h_
