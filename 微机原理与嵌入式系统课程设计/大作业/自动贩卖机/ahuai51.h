#ifndef __AHUAI51_H__
#define __AHUAI51_H__

/*
Tis liabry without LCD1602 is written by ChenAo for AHU-AI
Open sourced at https://github.com/DylanAo/AHU-AI-Repository
Last change: 2024.10.29
*/


/*** include area ***/
#include <REG51.H>
#include <stdio.h>
#include <string.h>


/*** define area ***/
/* about pin */
#define PIN_RESET 0
#define PIN_SET   1

#define IO_P0 0x80
#define IO_P1 0x90
#define IO_P2 0xA0
#define IO_P3 0xB0

#define PIN_0 0x01
#define PIN_1 0x02
#define PIN_2 0x04
#define PIN_3 0x08
#define PIN_4 0x10
#define PIN_5 0x20
#define PIN_6 0x40
#define PIN_7 0x80
#define PIN_ALL 0xff


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

/*** abot KEY MATRIX ***/

sbit column0 = P1 ^ 0; 
sbit column1 = P1 ^ 1; 
sbit column2 = P1 ^ 2; 
sbit column3 = P1 ^ 3; 

sbit line0 = P1 ^ 4;
sbit line1 = P1 ^ 5;
sbit line2 = P1 ^ 6;
sbit line3 = P1 ^ 7;

#define CONFRIM 250
#define CANCEL 249
#define NONE 248

typedef enum  {
	key0 ,key1, key2, key3, key4, key5, key6, key7, key8, key9, key10, key11, key12, key13, key14, key15, no_key_down
}key_matrix_id;


/*** abot Aoto shopping ***/
typedef enum  {
	cargo1 = 1, cargo2 = 2, cargo3 = 3, cargo4 = 4, cargo5 = 5, cargo6 = 6, cargo7 = 7, cargo8 = 8
}cargo_id;

typedef enum  {
	coin1_cash1 = 1 , cash5 = 5, cash10 = 10, cash20 = 20, cash50 = 50, cash100 = 100
}money_id;

typedef struct {
    int money1;
    int money5;
    int money10;
    int money20;
    int money50;
    int money100;
}change_collection;

/*** function area ***/

/*
          VERY IMPORTANT
All delay functions are base on 12MHZ(maybe)
*/
void delay_100ms(uint8_t x);
void delay_ms(uint16_t x);
void delay_us(uint16_t x);


/* about IO */
void IO_WritePin(uint8_t IO, uint8_t Pin_Nums, uint8_t type);

/* about key */
key_matrix_id key_matrix_16();
uint8_t get_keyboard_amount();
uint8_t get_keyboard_cargo();
uint8_t get_keyboard_money();

/* about LCD1602 */
void LCD_Init();
void LCD_ShowChar(unsigned char Line,unsigned char Column,char Char);
void LCD_ShowString(unsigned char Line,unsigned char Column,char *String);
void LCD_Clean();

void welcome_page();
void change_collection_init(change_collection* p);
void get_change(change_collection* p, int money);
#endif
