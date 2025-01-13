#include "ahuai51.h"

uint8_t get_cargo_id = 0;
uint8_t current_cargo_id = 0;
uint8_t get_amount = 0;
int current_amount = 0;
int target_money = 0;
uint8_t get_money = 0;
int current_money = 0;
change_collection changes;
int second = 0;
uint8_t time_count = 0;
uint8_t second_str[3];
uint8_t FLAG = 0;
void main(){

	uint8_t cargo_str[] = "Cargo:0";
	uint8_t amount_str[3];
	uint8_t target_money_str[3];
	uint8_t current_money_str[3];
	
	LCD_Init();
start:
	// var init
	get_cargo_id = 0;
	current_cargo_id = 0;
	get_amount = 0;
	current_amount = 0;
	target_money = 0;
	get_money = 0;
	current_money = 0;
	time_count = 0;
	second = 0;
	FLAG = 0;
	TR0 = 0;
	welcome_page();
	
	// about cargo
	while(1) {
		if(FLAG) {
			FLAG = 0;
			goto start;
		}
		
		get_cargo_id = get_keyboard_cargo();
		if (get_cargo_id != NONE) {
			if (get_cargo_id == CONFRIM) {
				if (current_cargo_id == 0) {
					LCD_Clean();
					LCD_ShowString(1, 1, "No Choice");
					delay_100ms(5);
					goto start;
				}
				goto amount;
			}
			TMOD=0x01;
			TH0 = (65535 - 50000) / 256;
			TL0 = (65535 - 50000) % 256; 
			IE = 0x82;
			TR0 = 1;
			second = 30;
			
			current_cargo_id = get_cargo_id;
			*(cargo_str + 6) = current_cargo_id + 0x30;
			IO_WritePin(IO_P3, PIN_0 << (current_cargo_id - 1), PIN_SET);
			LCD_Clean();
			LCD_ShowString(1, 1, cargo_str);
		}
	}
	
	// about amount
amount:
	LCD_Clean();
	LCD_ShowString(1, 1, "Amount:0");
	while(1) {
		if(FLAG) {
			FLAG = 0;
			goto start;
		}
		
		get_amount = get_keyboard_amount();
		if (get_amount != NONE) {
			if (get_amount == CONFRIM) {
				if (current_amount == 0) {
					LCD_Clean();
					LCD_ShowString(1, 1, "Is empty");
					delay_100ms(5);
					goto start;
				}
				goto input_money;
			}
			LCD_Clean();
			current_amount = current_amount * 10 + get_amount - 0x30;
			LCD_ShowString(1, 1, "Amount:");
			sprintf(amount_str, "%3d", current_amount);
			LCD_ShowString(1, 8, amount_str);
		}
	}
	
	// anout get money
input_money:
	target_money = current_cargo_id * current_amount;
	LCD_Clean();
	LCD_ShowString(1, 1, "$:");
	sprintf(target_money_str, "%3d", target_money);
	LCD_ShowString(1, 3, target_money_str);
	LCD_ShowString(1, 6, "Paid:  0");
	while(1) {
		if(FLAG) {
			FLAG = 0;
			goto start;
		}
		
		get_money = get_keyboard_money();
		if(get_money != NONE) {
			if (get_money == CONFRIM) {
				goto change_money;
			}
			current_money += get_money;
			sprintf(current_money_str, "%3d", current_money);
			LCD_ShowString(1, 13, current_money_str);
		}
	}
	
		// about change 
change_money:
	TR0 = 0;
	change_collection_init(&changes);
	if(current_money < target_money) {
		LCD_Clean();
		LCD_ShowString(1, 1, "Not enough money");
		delay_100ms(5);
		get_change(&changes, current_money);
	}
	else{
		get_change(&changes, current_money - target_money);
	}

	LCD_Clean();
	LCD_ShowString(1, 1, "100:0 50:0 20:0");
	LCD_ShowString(2, 1, "10:0 5:0 1:0");
	
	LCD_ShowChar(1, 5, changes.money100 + 0x30);
	LCD_ShowChar(1, 10, changes.money50 + 0x30);
	LCD_ShowChar(1, 15, changes.money20 + 0x30);
	LCD_ShowChar(2, 4, changes.money10 + 0x30);
	LCD_ShowChar(2, 8, changes.money5 + 0x30);
	LCD_ShowChar(2, 12, changes.money1 + 0x30);
	
	delay_100ms(5);
	goto start;
}


void time0() interrupt 1 {
	TH0 = (65535 - 50000) / 256;
	TL0 = (65535 - 50000) % 256; 
	
	if (time_count < 15) { 
		time_count ++;
	}
	else {
		time_count = 0;
		second --;
		}
		

		LCD_ShowString(2, 1, "Time:");
		sprintf(second_str, "%2d", second);
		LCD_ShowString(2, 6, second_str);
		
		if(second == 0) {
			FLAG = 1;
			TR0 = 0;
		}
}