#include "ahuai51.h"

unsigned char data_string_up[17];
unsigned char data_string_down[17];
int answer;
char unconfrim_char;
char confrim_char;
int main(){

begin:
	strcpy(data_string_up, "");
	strcpy(data_string_down, "");

	
  LCD_Init();
	LCD_ShowNum(1, 1, 0, 1);
	
	
	while (1){
		unconfrim_char = get_keyboard_char();
		if(unconfrim_char != '!') {
			confrim_char = unconfrim_char;
			strcat(&data_string_up, &confrim_char);
			LCD_ShowString(1, 1, data_string_up);
			
			
			if(confrim_char == '=') {
			answer = calculat_output(data_string_up);
			sprintf(data_string_down, "%16d", answer);
			LCD_ShowString(2, 1, data_string_down);
			}
			
			
			if(confrim_char == '#') {
				goto begin;
			}
		}
	}
}