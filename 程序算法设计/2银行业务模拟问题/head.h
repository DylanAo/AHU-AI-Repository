#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
using namespace std;

//基本常量申明
#define OK 1
#define ERROR 0
#define OVERFLOW -2

#define WINDOWS 4				//窗口数
#define PERSON_MIN 50		//银行一天最少的顾客数
#define PERSON_MAX 150				//银行一天最多的顾客数
#define TIME_MIN 10				//一次业务办理的最短时间（分钟）
#define TIME_MAX 40			//一次业务办理的最长时间（分钟）

//状态值定义
typedef int Status;

//定义客户的相关类型
typedef struct Customer
{
	int id;					//顾客序号
	int arrival_time;		//到达时间
	int service_time;	//服务时间
}Customer;