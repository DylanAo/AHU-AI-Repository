#ifndef __AHUAI51_H__
#define __AHUAI51_H__

/*
Tis liabry without LCD1602 is written by ChenAo for AHU-AI
Open sourced at https://github.com/DylanAo/AHU-AI-Repository
Last change: 2024.10.23
*/


/*** include area ***/
#include <REG51.H>
#include <stdio.h>
#include <string.h>

/*** var types area ***/

/*stm32 style*/
typedef unsigned char uint8_t;    // 8bit: 0~255
typedef signed char int8_t;       // 8bit: -128~127
typedef unsigned short uint16_t;  // 16bit: 0~65535
typedef signed short int16_t;     // 16bit: -32768~32767
typedef unsigned int uint32_t;    // 32bit: 0~4294967295
typedef signed int int32_t;       // 32bit: -2147483648~2147483647

/*The following sections(var types) are defined to be compatible with the teacher's content*/
typedef unsigned char uchar;      // 8bit: 0~255
typedef unsigned int uint;       // 32bit: 0~4294967295


/*** abot LCD1602 ***/
sbit LCD_RS = P2^7;
sbit LCD_RW = P2^6;
sbit LCD_EN = P2^5;
#define LCD_DataPort P0

/*** abot calculat ***/
enum state_mode {
	num,  // number mode
	add,  // addition mode
	sub,  // subtraction mode
	mul,  // multiplication mode
	div,  // division mode
	ans   // answer mode
};


typedef struct {
	int confrim_number;
	int unconfrim_number;
	enum state_mode state;
}composite_data;

sbit column0 = P1 ^ 0; 
sbit column1 = P1 ^ 1; 
sbit column2 = P1 ^ 2; 
sbit column3 = P1 ^ 3; 

sbit line0 = P1 ^ 4;
sbit line1 = P1 ^ 5;
sbit line2 = P1 ^ 6;
sbit line3 = P1 ^ 7;


typedef enum  {
	key0 ,key1, key2, key3, key4, key5, key6, key7, key8, key9, key10, key11, key12, key13, key14, key15, no_key_down
}key_matrix_id;

/*** function area ***/

/*
          VERY IMPORTANT
All delay functions are base on 12MHZ(maybe)
*/
void delay_100ms(uint8_t x);
void delay_ms(uint16_t x);
void delay_us(uint16_t x);

/* about key */
key_matrix_id key_matrix_16();
char get_keyboard_char();
	
/* about LCD1602 */
void LCD_Init();
void LCD_ShowChar(unsigned char Line,unsigned char Column,char Char);
void LCD_ShowString(unsigned char Line,unsigned char Column,char *String);
void LCD_ShowNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length);
void LCD_ShowSignedNum(unsigned char Line,unsigned char Column,int Number,unsigned char Length);
void LCD_ShowHexNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length);
void LCD_ShowBinNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length);

/* abot calculat */
void calculat(composite_data* input_data, char input_char);
void calculat_symbol(composite_data* input_data);
int calculat_output(unsigned char* str);
void composite_data_init(composite_data* input_data);
#endif