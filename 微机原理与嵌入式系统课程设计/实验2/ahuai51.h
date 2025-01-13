#ifndef __AHUAI51_H__
#define __AHUAI51_H__

/*
Tis liabry is written by ChenAo for AHU-AI
Open sourced at https://github.com/DylanAo/AHU-AI-Repository
Last change: 2024.9.12
*/


/*** include area ***/
#include <REG51.H>


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

/* about key */
#define KEY_0 0x01
#define KEY_1 0x02
#define KEY_2 0x04
#define KEY_3 0x08
#define KEY_4 0x10
#define KEY_5 0x20
#define KEY_6 0x40
#define KEY_7 0x80
#define KEY_NONE 0xff

/* about smg */
#define SMG_SATRT 1
#define SMG_OFF 8

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


/*** globe var area ***/
extern uint8_t FLAG_MPX2_MODE;
extern uint8_t FLAG_MPX6_MODE;


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

/* about smg */
void smg_postive_static(uint8_t IO, uint8_t element);

void smg_MPX2_postive(uint8_t IO1, uint8_t pin1, uint8_t IO2, uint8_t pin2, uint8_t pin3, uint8_t element1, uint8_t element2);
void smg_MPX2_postive_left(uint8_t IO1, uint8_t pin, uint8_t IO2, uint8_t element);
void smg_MPX2_postive_right(uint8_t IO1, uint8_t pin, uint8_t IO2, uint8_t element);
void smg_MPX2_postive_display(uint8_t IO1, uint8_t IO2, uint8_t element_left, uint8_t element_right);

void smg_MPX6_postive_single(uint8_t IO1, uint8_t IO2, uint8_t pin, uint8_t element, uint8_t switch_smg);
void smg_MPX6_postive_display(uint8_t IO1, uint8_t IO2, uint8_t *switchs, uint8_t element_1, uint8_t element_2, uint8_t element_3, uint8_t element_4, uint8_t element_5, uint8_t element_6);

/* about key */
uint8_t get_key_single_PullUp(uint8_t IO);
#endif