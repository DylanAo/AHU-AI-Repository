#include "ahuai51.h"
// 1
/*
void main(void) {
	uint8_t count = 0;
	while(1) {
		for (count = 0; count < 100; count++) {
			smg_postive_static(IO_P0, count % 10 + 0x30);
			smg_postive_static(IO_P1, count / 10 + 0x30);
			delay_100ms(3);
		}	
	}
}*/
// 2
/*
uint8_t FLAG_MPX2_MODE = SMG_SATRT;
uint8_t count = 0;
void main(void) {
	TMOD=0x01;
	TH0 = (65535 - 10000) / 256;
	TL0 = (65535 - 10000) % 256; 
	IE = 0x82;
	TR0 = 1;
	while(1) {
		for (count = 0; count < 100; count++) {
			delay_100ms(3);
		}
	}
}



void time0() interrupt 1 {

	TH0 = (65535 - 10000) / 256;
	TL0 = (65535 - 10000) % 256; 
	
	smg_MPX2_postive_display(IO_P1, IO_P3, count % 10 + 0x30, count / 10 + 0x30);
	
}*/

// 3
/*
uint8_t count = 0;
uint8_t FLAG_MPX2_MODE = SMG_SATRT;

void main(void) {
	uint8_t key_number = KEY_NONE;
	TMOD=0x01;
	TH0 = (65535 - 10000) / 256;
	TL0 = (65535 - 10000) % 256; 
	IE = 0x82;
	TR0 = 1;
	
	
	while(1) {
		key_number = get_key_single_PullUp(IO_P2);
		
		switch(key_number) {
			case KEY_0:
				if (count < 99) {
					count ++;
				}
				break;
				
			case KEY_1:
				if (count > 0) {
					count --;
				}
				break;
			default:
				break;
		}
	}
}

void time0() interrupt 1 {

	TH0 = (65535 - 10000) / 256;
	TL0 = (65535 - 10000) % 256; 
	
	smg_MPX2_postive_display(IO_P1, IO_P3, count % 10 + 0x30, count / 10 + 0x30);
}*/

// 4

uint8_t FLAG_MPX6_MODE = SMG_SATRT;
uint8_t HOUR = 23;
uint8_t MIN = 59;
uint8_t SECOND = 58;
uint8_t COUNT = 0;
uint8_t FLASH_SWITCH = 0;
uint8_t SMG_MPX6_SWITCHS[6] = {1, 1, 1, 1, 1, 1};
uint8_t CURRENT_CHOICE = 0;
void main(void) {
	uint8_t key_number = KEY_NONE;
	
	TMOD=0x01;
	TH0 = (65535 - 10000) / 256;
	TL0 = (65535 - 10000) % 256; 
	IE = 0x8a;
	TR0 = 1;
	
	TH1 = (65535 - 40000) / 256;
	TL1 = (65535 - 40000) % 256;
	PT1 = 1;
	TR1 = 1;
	
	
	while(1) {
	key_number = get_key_single_PullUp(IO_P2);
		
	switch(key_number) {
			case KEY_0:
				switch (CURRENT_CHOICE % 10) {
					case 0:
						CURRENT_CHOICE = 1;
						break;
					
					case 1:
						CURRENT_CHOICE = 2;
						break;
					
					case 2:
						CURRENT_CHOICE = 3;
						break;
					
					case 3:
						CURRENT_CHOICE = 1;
						break;
					
					default:
						CURRENT_CHOICE = 0;
			}
				break;
				
			case KEY_1:
				switch (CURRENT_CHOICE) {					
					case 1:
						if(HOUR < 23){
							HOUR ++;
						}
						else {
							HOUR = 0;
						}
						break;
								
					case 2:
						if(MIN < 59) {
							MIN ++;
						}
						else {
							MIN = 0;
						}
						break;
								
					case 3:
						if(SECOND < 59) {
							SECOND ++;
						}
						else {
							SECOND = 0;
						}
						break;
								
					default:
						break;
				}
				break;
			
			case KEY_2:
					switch (CURRENT_CHOICE) {					
					case 1:
						if(HOUR > 0){
							HOUR --;
						}
						else {
							HOUR = 23;
						}
						break;
								
					case 2:
						if(MIN > 0) {
							MIN --;
						}
						else {
							MIN = 59;
						}
						break;
								
					case 3:
						if(SECOND > 0) {
							SECOND --;
						}
						else {
							SECOND = 59;
						}
						break;
								
					default:
						break;
				}
				break;
			
			case KEY_3:
				CURRENT_CHOICE = 0;
				break;
				
			default:
				break;
		}
	}
}

void time0() interrupt 1   { 
	// To display
	TH0 = (65535 - 10000) / 256;
	TL0 = (65535 - 10000) % 256; 
	
	smg_MPX6_postive_display(IO_P1, IO_P3, SMG_MPX6_SWITCHS, HOUR / 10 + 0x30, HOUR % 10 + 0x30, MIN / 10 + 0x30, MIN % 10 + 0x30, SECOND / 10 + 0x30, SECOND % 10 + 0x30);
}


void time1() interrupt 3   { 
	TH1 = (65535 - 40000) / 256;
	TL1 = (65535 - 40000) % 256; 
	
	switch (CURRENT_CHOICE) {
		case 0:
			SMG_MPX6_SWITCHS[0] = 1;
			SMG_MPX6_SWITCHS[1] = 1;
			SMG_MPX6_SWITCHS[2] = 1;
			SMG_MPX6_SWITCHS[3] = 1;
			SMG_MPX6_SWITCHS[4] = 1;
			SMG_MPX6_SWITCHS[5] = 1;
			break;
					
		case 1:
			SMG_MPX6_SWITCHS[0] = 0;
			SMG_MPX6_SWITCHS[1] = 0;
			SMG_MPX6_SWITCHS[2] = 1;
			SMG_MPX6_SWITCHS[3] = 1;
			SMG_MPX6_SWITCHS[4] = 1;
			SMG_MPX6_SWITCHS[5] = 1;
			CURRENT_CHOICE += 10;
			break;
					
		case 2:
		  SMG_MPX6_SWITCHS[0] = 1;
			SMG_MPX6_SWITCHS[1] = 1;
			SMG_MPX6_SWITCHS[2] = 0;
			SMG_MPX6_SWITCHS[3] = 0;
			SMG_MPX6_SWITCHS[4] = 1;
			SMG_MPX6_SWITCHS[5] = 1;
			CURRENT_CHOICE += 10;
			break;
					
		case 3:
			SMG_MPX6_SWITCHS[0] = 1;
			SMG_MPX6_SWITCHS[1] = 1;
			SMG_MPX6_SWITCHS[2] = 1;
			SMG_MPX6_SWITCHS[3] = 1;
			SMG_MPX6_SWITCHS[4] = 0;
			SMG_MPX6_SWITCHS[5] = 0;
			CURRENT_CHOICE += 10;
			break;
					
		default:
			SMG_MPX6_SWITCHS[0] = 1;
			SMG_MPX6_SWITCHS[1] = 1;
			SMG_MPX6_SWITCHS[2] = 1;
			SMG_MPX6_SWITCHS[3] = 1;
			SMG_MPX6_SWITCHS[4] = 1;
			SMG_MPX6_SWITCHS[5] = 1;
			CURRENT_CHOICE -= 10;
		}
		
	if (COUNT < 250) {
		COUNT ++;
	}
	else {
		COUNT = 0;
		if (SECOND < 59) {
			SECOND ++;
		}
		else{
			SECOND = 0;
			if (MIN < 59) {
				MIN ++;
			}
			else {
				MIN = 0;
				if (HOUR < 23) {
					HOUR ++;
				}
				else {
					HOUR = 0;
				}
			}
		}
	}
}
