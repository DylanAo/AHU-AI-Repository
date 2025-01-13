#ifndef __AHUAI51_H__
#define __AHUAI51_H__

/*
Tis liabry is written by ChenAo for AHU-AI
Open sourced at https://github.com/DylanAo/AHU-AI-Repository
Last change: 2024.9.3
*/


/*** include area ***/
#include <REG51.H>


/*** define area ***/
/* some type */
#define PIN_RESET 0  //low voltage
#define PIN_SET   1  //high voltage

/* about pin */
#define IO_P0 0
#define IO_P1 1
#define IO_P2 2
#define IO_P3 3

#define pin_0 0x01 << 0
#define pin_1 0x01 << 1
#define pin_2 0x01 << 2
#define pin_3 0x01 << 3
#define pin_4 0x01 << 4
#define pin_5 0x01 << 5
#define pin_6 0x01 << 6
#define pin_7 0x01 << 7
#define pin_all 0xff

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
typedef unsigned int uint;        // 32bit: 0~4294967295


/*** function area ***/

/*
          VERY IMPORTANT
All delay functions are base on 12MHZ(maybe)
*/
void delay_100ms(uint8_t x);
void delay_ms(uint16_t x);
/* about IO */
void IO_WritePin(uint8_t IO, uint8_t Pin_Nums, uint8_t type);
void IO_TooglePin(uint8_t IO, uint8_t Pin_Nums);
uint8_t IO_ReadAllPins(uint8_t IO);
uint8_t IO_ReadPin(uint8_t IO, uint8_t Pin_Nums);
#endif