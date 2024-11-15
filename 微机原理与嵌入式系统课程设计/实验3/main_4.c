#include <reg51.h>
#include <intrins.h>
#include <math.H>
#include "stdio.h"

#define uchar unsigned char
#define uint unsigned int

//接口定义
sbit K1 = P3^4;
sbit K2 = P3^5;
sbit K3 = P3^6;
sbit K4 = P3^7;

//变量定义
uchar Timer_count = 0;
bit   Timer_flag  = 1;
//extern bit Dis_flag;
bit Dis_flag;
extern uchar Dstring[15];
extern  uchar  Dtimer[7];	
char	Adjust_count = -1;	
uchar Month_Days[]={0,31,0,31,30,31,30,31,31,30,31,30,31};
extern char code *weektable();
//char Now_ts[15];

//函数声明
extern void LCD_Init();
extern void writeString(unsigned char *pcStr, unsigned short xO, unsigned int yO);
extern void Set_ds1302();
extern void RD_ds1302();	
extern void DIS_ds1302();	
extern void delay(unsigned int i);	
extern void sendChangeCmd();
extern float getTmpValue(); 
uchar  LeepYear(uint x) ; 
void Update_Weekday();
void Dtimer_Adjust(char x);



uchar  LeepYear(uint x){
	return (x%4 == 0&&x%100 != 0) || (x%400 == 0);
}

void Update_Weekday (){
	uint i,d = 0, w = 5; 
	for(i=2000; i<2000+Dtimer[0]; i++){
		d += (LeepYear(i) ? 2 : 1);
	}
	w = (d+w) % 7; 
	d=0;
	for(i=1; i<Dtimer[2]; i++){
		d += Month_Days[i];
	}
	d += Dtimer[3]; 
	Dtimer[1] = (d+w) % 7 + 1;
}

void Dtimer_Adjust(char x){
	switch (Adjust_count){
		case 0:
			if(x == 1&&Dtimer[0]<99){
				Dtimer[0]++;
			}
			if(x == -1&&Dtimer[0]>0){
				Dtimer[0]--;
			}
			Month_Days[2] = LeepYear(2000 + Dtimer[0]) ? 29 : 28;
			if(Dtimer[3] > Month_Days[Dtimer[2]]){
				Dtimer[3] = Month_Days[Dtimer[2]];
			}
			break;

		case 2:
			if(x == 1&&Dtimer[2]<12){
				Dtimer[2]++;
			}
			if(x == -1&&Dtimer[2]>1){
				Dtimer[2]--;
			}
			Month_Days[2] = LeepYear(2000 + Dtimer[0]) ? 29 : 28;
			if(Dtimer[3] > Month_Days[Dtimer[2]]){
				Dtimer[3] = Month_Days[Dtimer[2]];
			}
			break;

		case 3:
			Month_Days[2] = LeepYear(2000 + Dtimer[0]) ? 29 : 28;
			if(x == 1&&Dtimer[3]<Month_Days[Dtimer[2]]){
				Dtimer[3]++;
			}
			if(x == -1&&Dtimer[3]>1){
				Dtimer[3]--;
			}
			Update_Weekday();
			break;
			
		case 4:
			if(x == 1&&Dtimer[4]<23){
				Dtimer[4]++;
			}
			if(x == -1&&Dtimer[4]>0){
				Dtimer[4]--;
			}
			break;

		case 5:
			if(x == 1&&Dtimer[5]<59){
				Dtimer[5]++;
			}
			if(x == -1&&Dtimer[5]>0){
				Dtimer[5]--;
			}
			break;
		
		case 6:
			if(x == 1&&Dtimer[6]<59){
				Dtimer[6]++;
			}
			if( x== -1&&Dtimer[6]>0){
				Dtimer[6]--;
			}
			break;
	}
}




void main(){
	LCD_Init(); 
	TMOD = 0x01; 
	TH0  = 0xb0; 
	TL0  = 0x3c; 
	TR0  = 1;
	EX0  = 1;
	EA   = 1;
	
	Set_ds1302();
	sendChangeCmd(); 
	delay(500);
	writeString("万年历", 0, 6);
	writeString("2000年09月28日", 3, 0); 
	writeString("22时39分00秒", 6, 2);
	writeString("星期六",9, 8);
	writeString("当前温度         ℃", 12, 0);
	ET0 = 1;
	Dstring[0] = '\0';
	Dstring[1] = '\0';
	Dstring[2] = '\0';
	Dstring[3] = '\0';
	Dstring[4] = '\0';
	Dstring[5] = '\0';
	Dstring[6] = '\0';
	Dstring[7] = '\0';
	Dstring[8] = '\0';
	Dstring[9] = '\0';
	Dstring[10] = '\0';
	
	while(1){
		if(Timer_flag == 1){
			Timer_flag = 0;
			Timer_count = 0;
			if(Adjust_count == -1){
				RD_ds1302();
			}
			DIS_ds1302();
			sendChangeCmd();
			Dis_flag = 0;
			//writeString(Dstring, 14, 10);
			sprintf(Dstring, "%4.1f",getTmpValue());
			writeString(Dstring, 12, 10);
		}
	}
}	


void INT0_int(void) interrupt 0{
	if(K1 == 0){
		while(K1 == 0);
		if(Adjust_count == 6)
			Adjust_count = -1;
		Adjust_count++; 
		if(Adjust_count == 1)
			Adjust_count = 2;
	}

	else if(K2 == 0){
		while(K2 == 0);
		Dtimer_Adjust(1);
	}

	else if(K3 == 0){
		while(K3==0); 
		Dtimer_Adjust(-1);
	}

	else if(K4 == 0){
		while(K4 == 0);
		Set_ds1302();
		Adjust_count = -1;
	}
}

void timer0_int (void) interrupt 1 using 0{
	TH0 = 0xb0; 
	TL0 = 0x3c;
	Timer_count++;
	if(Timer_count == 20){
		Timer_count = 0; 
		Timer_flag = 1;
	}
}