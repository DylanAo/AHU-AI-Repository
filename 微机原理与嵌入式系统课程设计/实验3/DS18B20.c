#include <reg51.h>
#include <string.h>
#include <intrins.h>
#include <math.H>
#include "stdio.h"


#define uchar unsigned char
#define uint unsigned int

#define Search_ROM   0xf0
#define Read_ROM     0x33
#define Math_ROM     0x55 
#define Skip_ROM     0xcc
#define Alarm_Search 0xec
#define	Convert_T	   0x44
#define	Write_S	     0x8d
#define	Read_S	     0xbe
#define	Copy_S	     0x48
#define Recall_EE    0xb8
#define	Read_P_S     0x84

//接口定义
sbit ds = P2^7;
 
//变量定义
bit Tflag;
uchar code df_Table[] = {0, 1, 1, 2, 3, 3, 4, 4, 5, 6, 6, 7, 8, 8, 9, 9};

//函数声明
extern void LCD_Init();
extern void writeString(unsigned char *pcStr, unsigned short x0, unsigned int yO );
void delay(unsigned int i);
void ds18b20Init();
void dsWait();
bit readBit(); 
uchar readByte(); 
void writeByte(unsigned char dat);
void sendChangeCmd();
void sendReadCmd(); 
float getTmpValue();

void delay(unsigned int i){
	unsigned int j;
	while(i--){
		for(j=0; j<125; j++);
	}
}	
		
void ds18b20Init(){
	unsigned int i;
	ds = 0;
	i = 100;
	while (i>0){
		i--;
	}
	ds = 1;
	i = 4;
	while (i>0){
		i--;
	}
}
	
void dsWait(){
	unsigned int i;
	while(ds);
	while(~ds);
	i = 4;
	while(i > 0){
		i--;
	}
}

bit  readBit(){
	unsigned int i;
	bit b; 
	ds = 0;
	i++;
	ds = 1;
	i++; i++;
	b = ds;
	i = 8;
	while(i > 0){
		i--;
	}
	
	return b;
}

unsigned char readByte(){
	unsigned int i;
	unsigned char j, dat;
	dat = 0; 
	for (i=0; i<8; i++){
		j =	readBit();	
		dat	= (j << 7) | (dat >> 1);
	}
	
	return dat;
}

void writeByte(unsigned char dat){
	unsigned int i;
	unsigned char j;
	bit b;
  for (j=0; j<8; j++){
		b = dat & 0x01;
		dat >>= 1;
		if (b){
			ds = 0;
			i++; i++;
			ds = 1;
			i = 8;
			while (i > 0){
				i--;
			}
		}
		
		else{
			ds = 0;
			i = 8;
			while (i > 0){
				i--;
			}
			ds = 1;
			i++; i++;
		}
	}
}
		
void sendChangeCmd(){
	ds18b20Init();
	dsWait();
	delay(1);
	writeByte(Skip_ROM);
	writeByte(Convert_T);
}

void sendReadCmd(){
	ds18b20Init();
	dsWait();
	delay(1);
	writeByte(Skip_ROM);
	writeByte(Read_S);
}

float getTmpValue() {
	
	unsigned char high;
  unsigned char low;
	float temp;
	//ds18b20Init();
	sendReadCmd();
	
	low = readByte();
	high = readByte();

	Tflag = 0;
	
    if ((high & 0xf8) == 0xf8) {
      high = ~high;
			low = ~low + 1;
			if (low == 0x00){
				high++;
			}
			Tflag = 1;
    } 
		
		temp = (((high & 0x0f) << 4) | ((low & 0xf0) >> 4)) + df_Table[low & 0x0F] * 0.1;
		
    if (Tflag) {
			temp = -temp;
		}
		
    return (temp);
}

