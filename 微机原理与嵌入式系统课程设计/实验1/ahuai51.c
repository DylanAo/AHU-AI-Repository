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
	uint16_t i, j;
	for(i = 0; i < x; i++) 
		for(j = 0; j < 334; j++);
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