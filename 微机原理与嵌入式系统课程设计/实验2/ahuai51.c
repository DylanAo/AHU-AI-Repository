#include "ahuai51.h"
/*Tis liabry is written by ChenAo*/


/* function area*/
void delay_100ms(uint8_t x){
	uint8_t i, j, k;
	for(i = 0; i < x; i++)
		for(j = 0; j < 200; j++)
			for(k = 0; k < 165; k++);
}


void delay_ms(uint16_t x){
	uint16_t i;
	uint8_t j;
	for(i = 0; i < x; i++) 
		for(j = 0; j < 113; j++);
}


void IO_WritePin(uint8_t IO, uint8_t Pin_Nums, uint8_t type){	
	type = type ? 0x00 : 0xff;
	
	switch(IO){
		case IO_P0:
			P0 = Pin_Nums ^ type;
			break;
		
		case IO_P1:
			P1 = Pin_Nums ^ type;
			break;
		
		case IO_P2:
			P2 = Pin_Nums ^ type;
	    break;
		
		case IO_P3:
			P3 = Pin_Nums ^ type;
	    break;
		
		default: 
			break;
	}
}


void IO_TooglePin(uint8_t IO, uint8_t Pin_Nums){
	switch(IO){
		case IO_P0:
			P0 = (P0 & (~Pin_Nums)) | (P0 ^ Pin_Nums);
			break;
		
		case IO_P1:
			
		 	P1 = (P1 & (~Pin_Nums)) | (P1 ^ Pin_Nums);
			break;
		
		case IO_P2:
			P2 = (P2 & (~Pin_Nums)) | (P2 ^ Pin_Nums);
	    break;
		
		case IO_P3:
			P3 = (P3 & (~Pin_Nums)) | (P3 ^ Pin_Nums);
	    break;
		
		default: 
			break;
	}
}


uint8_t IO_ReadPin(uint8_t IO, uint8_t Pin_Nums){
		switch(IO){
		case IO_P0:
			return P0 & Pin_Nums ? PIN_SET : PIN_RESET;
			break;
		
		case IO_P1:
		 	return P1 & Pin_Nums ? PIN_SET : PIN_RESET;
			break;
		
		case IO_P2:
			return P2 & Pin_Nums ? PIN_SET : PIN_RESET;
	    break;
		
		case IO_P3:
			return P3 & Pin_Nums ? PIN_SET : PIN_RESET;
	    break;
		
		default: 
			return PIN_RESET;
			break;
	}
}


uint8_t IO_ReadAllPins(uint8_t IO) {
	switch(IO){
		case IO_P0:
			return P0;
			break;
		
		case IO_P1:
		 	return P1;
			break;
		
		case IO_P2:
			return P2;
	    break;
		
		case IO_P3:
			return P3;
	    break;
		
		default: 
			return PIN_RESET;
			break;
	}
}


void smg_postive_static(uint8_t IO, uint8_t element) {
	uint8_t element_index = 0;
	uint8_t smg_libary_static[19] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90, 0x88, 0x83, 0xc6, 0xa1, 0x86, 0x8e, 0xbf, 0x7f, 0xff};

	if (element > 0x2f) { // numbers & chars
		element_index = element - 0x30;
		if (element > 0x40) {  // chars
			element_index = element_index - 7;
		}
		goto smg_postive1_static_out;
	}
	
	switch (element) { // special
		case '-':
			element_index = 16;
		 break;
		
		case '.':
			element_index = 17;
		 break;
		
		default:
			element_index = 18;
	}
	
smg_postive1_static_out:
	switch (IO) {
		case IO_P0:
			P0 = smg_libary_static[element_index];
			break;
		
		case IO_P1:
			P1 = smg_libary_static[element_index];
			break;
		
		case IO_P2:
			P2 = smg_libary_static[element_index];
			break;
		
		case IO_P3:
			P3 = smg_libary_static[element_index];
			break;
		
		default:
			return;
	}
}

void smg_MPX2_postive_all(uint8_t IO1, uint8_t pin1, uint8_t IO2, uint8_t pin2, uint8_t IO3, uint8_t element1, uint8_t element2) {
	/***   ATTENTION:ABANDON & NOT RECOMMEND   ***/
	
	smg_MPX2_postive_left(IO1, pin1, IO3, element1);
	delay_ms(7);
	
	smg_MPX2_postive_right(IO2, pin2, IO3, element2);
	delay_ms(7);
}

void smg_MPX2_postive_left(uint8_t IO1, uint8_t pin, uint8_t IO2, uint8_t element) {
	IO_WritePin(IO1, pin, PIN_SET);
	smg_postive_static(IO2, element);	
}
	

void smg_MPX2_postive_right(uint8_t IO1, uint8_t pin, uint8_t IO2, uint8_t element) {
	IO_WritePin(IO1, pin, PIN_SET);
	smg_postive_static(IO2, element);
}


void smg_MPX2_postive_display(uint8_t IO1, uint8_t IO2, uint8_t element_left, uint8_t element_right) {
	switch(FLAG_MPX2_MODE) {
		case 1:
			smg_MPX2_postive_left(IO1, PIN_0, IO2, element_left);
			FLAG_MPX2_MODE = 2;
			break;
	
		case 2:
			smg_MPX2_postive_right(IO1, PIN_1, IO2, element_right);
			FLAG_MPX2_MODE = 1;
			break;
		
		default:
			IO_WritePin(IO1, PIN_ALL, PIN_RESET);
			break;
	}
}


void smg_MPX6_postive_single(uint8_t IO1, uint8_t IO2, uint8_t pin, uint8_t element, uint8_t switch_single) {
	
	if (!switch_single) {
		IO_WritePin(IO1, PIN_ALL, PIN_RESET);
		return;
	}
	IO_WritePin(IO1, pin, PIN_SET);
	smg_postive_static(IO2, element);
}


void smg_MPX6_postive_display(uint8_t IO1, uint8_t IO2, uint8_t *switchs, uint8_t element_1, uint8_t element_2, uint8_t element_3, uint8_t element_4, uint8_t element_5, uint8_t element_6) {
	switch(FLAG_MPX6_MODE) {
		case 1:
			smg_MPX6_postive_single(IO1, IO2, PIN_0, element_1, *(switchs));
			FLAG_MPX6_MODE = 2;
			break;
	
		case 2:
			smg_MPX6_postive_single(IO1, IO2, PIN_1, element_2, *(switchs + 1));
			FLAG_MPX6_MODE = 3;
			break;
		
		case 3:
			smg_MPX6_postive_single(IO1, IO2, PIN_2, element_3, *(switchs + 2));
			FLAG_MPX6_MODE = 4;
			break;
		
		case 4:
			smg_MPX6_postive_single(IO1, IO2, PIN_3, element_4, *(switchs + 3));
			FLAG_MPX6_MODE = 5;
			break;
		
		case 5:
			smg_MPX6_postive_single(IO1, IO2, PIN_4, element_5, *(switchs + 4));
			FLAG_MPX6_MODE = 6;
			break;
		
		case 6:
			smg_MPX6_postive_single(IO1, IO2, PIN_5, element_6, *(switchs + 5));
			FLAG_MPX6_MODE = 1;
			break;
		
		
		default:
			IO_WritePin(IO1, PIN_ALL, PIN_RESET);
			break;
	}
}


uint8_t get_key_single_PullUp(uint8_t IO) {
	uint8_t key_code;
	IO_WritePin(IO, PIN_ALL, PIN_SET);
	key_code = IO_ReadAllPins(IO);
	if (key_code != KEY_NONE){
		delay_ms(20);
		while(IO_ReadAllPins(IO) != KEY_NONE);
		IO_WritePin(IO, PIN_ALL, PIN_SET);
	}
	return ~key_code;
}

