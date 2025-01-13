//#include "ahuai51.h"

//void main(void)
//{
//	LCD_CE=0;
//	LCD_Init();
//	writeString("“∫æßœ‘ æ≤‚ ‘∆¡ƒª∑÷±Ê¬ :160*128\r\nPG160128...OK!",0,0);
//	while(1){};
//}

#include <reg51.h>
#include <intrins.h>
#include "stdio.h"
#include <math.h>
#include <string.h>
#define uchar unsigned char
#define uint unsigned int
	
#define	Search_ROM 0xf0
#define	Read_ROM 0x33
#define	Math_ROM 0x55
#define	Skip_ROM 0xcc
#define	Alarm_Search 0xec
#define	Convert_T 0x44
#define	Write_S	0x8d
#define	Read_S 0xbe
#define	Copy_S 0x48
#define	Recall_EE 0xb8
#define	Read_P_S 0x84


sbit ds=P2^4;
//bit flag_200ms;
uchar menu_1, menu_2;

uchar Timer_count=0;
bit Timer_flag=1;
uchar Dstring[15];
//uchar Dstring2[15];
uint temperature;
//float temperature;

//void LCD_Init(void)
//∫Ø ˝…˘√˜
extern void LCD_Init();  // PG160128 ≥ı ºªØ
extern void writeString(unsigned char *pcStr,unsigned short x0,unsigned int y0);


void delay_uint(unsigned int i)
{
	while(i--);
}

void delay_1ms(unsigned int q)
{
	uint i,j;
	for(i=0;i<q;i++)
		for(j=0;j<125;j++);
}


void init_18b20()
{
	bit q;
	ds = 1;
	delay_uint(1);
	ds = 0;
	delay_uint(80);
	ds = 1;
	delay_uint(10);
	q = ds;
	delay_uint(20);
	ds = 1;
}





void write_18b20(uchar dat)
{
	uchar i;
	for(i=0;i<8;i++)
	{
		ds = 0;
		ds = dat & 0x01;
		delay_uint(5);
		ds = 1;
		dat >>=1;		
	}
}



uchar read_18b20()
{
	uchar i, value;
	for(i=0;i<8;i++)
	{
		ds = 0;
		value >>=1;
		ds = 1;
		if(ds == 1)
			value |= 0x80;
		delay_uint(5);
	}
	return value;
}


uint read_temp()
{
	uint value;
	uchar low;
	init_18b20();
	write_18b20(0xcc);
	write_18b20(0x44);
	delay_uint(50);
	
	init_18b20();
	
	write_18b20(0xcc);
	write_18b20(0xbe);
	
	EA = 0;
	low = read_18b20();
	value = read_18b20();
	EA = 1;
	value = ((value <<8) | low);
	return value;
	
}



void main()
{

	LCD_Init();
	writeString("DS18B20≤‚ ‘",0,4);
	writeString("Now temp:         oC",3,0);
	init_18b20();
	temperature = read_temp();
	delay_1ms(650);
	temperature = read_temp();
	delay_1ms(650);
	while(1)
	{
		temperature = read_temp();
		
		sprintf(Dstring,"%7.1f",((float)temperature) * 0.0625);
		writeString(Dstring,3,10);

	}
}

