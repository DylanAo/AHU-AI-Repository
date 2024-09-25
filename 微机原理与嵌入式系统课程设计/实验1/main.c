#include "ahuai51.h"

void main1(void){
	IO_WritePin(IO_P1, pin_0, PIN_RESET);
	while(1) {
		IO_TooglePin(IO_P1, pin_0);
		delay_100ms(2);
	}
}


void main2(void){
	uint8_t i;
	IO_WritePin(IO_P1, pin_all, PIN_SET);	while(1){
		for (i = 0; i < 8; i++){
			IO_WritePin(IO_P1, pin_0 << i, PIN_RESET);
			delay_100ms(2);
		}
	}
}


void main3(void) {
	uint8_t i;
	IO_WritePin(IO_P1, pin_all, PIN_SET);
	while(1){
		for(i = 0; i < 8; i++) {
			IO_WritePin(IO_P1, pin_0 << i | pin_7 >> i, PIN_RESET);
			delay_ms(100);
		}
	}
}


void main4(void) {
	uint8_t i;
	uint8_t pin_count;
	IO_WritePin(IO_P1, pin_all, PIN_SET);
	while(1){
		pin_count = 0x00;
		for(i = 0; i < 4; i++) {
			IO_WritePin(IO_P1, pin_0 << i | pin_7 >> i, PIN_RESET);
			delay_100ms(2);
			pin_count = pin_count | pin_0 << i | pin_7 >> i;
			IO_WritePin(IO_P1, pin_all, PIN_SET);
			IO_TooglePin(IO_P1, ~pin_count);
			delay_100ms(2);
		}
	}
}