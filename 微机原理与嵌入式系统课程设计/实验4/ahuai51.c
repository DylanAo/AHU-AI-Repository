#include "ahuai51.h"
/*Tis liabry without LCD is written by ChenAo for AHU-AI*/
	
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

void delay_us(uint16_t x) {
	while(x --);
}


/* calculat function */

void composite_data_init(composite_data* input_data) {
	input_data->unconfrim_number = 0;
	input_data->confrim_number = 0;
	input_data->state = num;
}


void calculat_symbol(composite_data* input_data) {
	switch (input_data->state) {
	case 0:
		input_data->confrim_number = input_data->unconfrim_number;
		input_data->unconfrim_number = 0;
		break;

	case 1: // +
		input_data->confrim_number = input_data->confrim_number + input_data->unconfrim_number;
		input_data->unconfrim_number = 0;
		break;

	case 2: // -
		input_data->confrim_number = input_data->confrim_number - input_data->unconfrim_number;
		input_data->unconfrim_number = 0;
		break;

	case 3: // *
		input_data->confrim_number = input_data->confrim_number * input_data->unconfrim_number;
		input_data->unconfrim_number = 0;
		break;

	case 4: // /
		input_data->confrim_number = input_data->confrim_number / input_data->unconfrim_number;
		input_data->unconfrim_number = 0;
		break;

	default:

		break;
	}
}

void calculat(composite_data* input_data, char input_char) {
	if (input_char > 0x30 && input_char < 0x39) {
		input_data->unconfrim_number = input_data->unconfrim_number * 10 + input_char - 0x30;
	}
	else {
		switch (input_char) {
		case '+':
			calculat_symbol(input_data);
			input_data->state = add;
			break;

		case '-':
			calculat_symbol(input_data);
			input_data->state = sub;
			break;

		case '*':
			calculat_symbol(input_data);
			input_data->state = mul;
			break;

		case '/':
			calculat_symbol(input_data);
			input_data->state = div;
			break;

		case '=':
			calculat_symbol(input_data);
			input_data->state = ans;
			break;

		default:
			break;
		}
	}
}


int calculat_output(unsigned char* str) {
	unsigned char* str_p = str;
	composite_data input_data;
	composite_data_init(&input_data);

	while (*str_p != '=') {
		calculat(&input_data, *str_p);
		str_p++;
	}
	calculat(&input_data, *str_p);
	return input_data.confrim_number;
}




void LCD_Delay()
{
	unsigned char i, j;

	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
}


void LCD_WriteCommand(unsigned char Command)
{
	LCD_RS=0;
	LCD_RW=0;
	LCD_DataPort=Command;
	LCD_EN=1;
	LCD_Delay();
	LCD_EN=0;
	LCD_Delay();
}


void LCD_WriteData(unsigned char Data)
{
	LCD_RS=1;
	LCD_RW=0;
	LCD_DataPort=Data;
	LCD_EN=1;
	LCD_Delay();
	LCD_EN=0;
	LCD_Delay();
}


void LCD_SetCursor(unsigned char Line,unsigned char Column)
{
	if(Line==1)
	{
		LCD_WriteCommand(0x80|(Column-1));
	}
	else if(Line==2)
	{
		LCD_WriteCommand(0x80|(Column-1+0x40));
	}
}


void LCD_Init()
{
	LCD_WriteCommand(0x38);
	LCD_WriteCommand(0x0c);
	LCD_WriteCommand(0x06);
	LCD_WriteCommand(0x01);
}


void LCD_ShowChar(unsigned char Line,unsigned char Column,char Char)
{
	LCD_SetCursor(Line,Column);
	LCD_WriteData(Char);
}


void LCD_ShowString(unsigned char Line,unsigned char Column,char *String)
{
	unsigned char i;
	LCD_SetCursor(Line,Column);
	for(i=0;String[i]!='\0';i++)
	{
		LCD_WriteData(String[i]);
	}
}


int LCD_Pow(int X,int Y)
{
	unsigned char i;
	int Result=1;
	for(i=0;i<Y;i++)
	{
		Result*=X;
	}
	return Result;
}


void LCD_ShowNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length)
{
	unsigned char i;
	LCD_SetCursor(Line,Column);
	for(i=Length;i>0;i--)
	{
		LCD_WriteData(Number/LCD_Pow(10,i-1)%10+'0');
	}
}


void LCD_ShowSignedNum(unsigned char Line,unsigned char Column,int Number,unsigned char Length)
{
	unsigned char i;
	unsigned int Number1;
	LCD_SetCursor(Line,Column);
	if(Number>=0)
	{
		LCD_WriteData('+');
		Number1=Number;
	}
	else
	{
		LCD_WriteData('-');
		Number1=-Number;
	}
	for(i=Length;i>0;i--)
	{
		LCD_WriteData(Number1/LCD_Pow(10,i-1)%10+'0');
	}
}


void LCD_ShowHexNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length)
{
	unsigned char i,SingleNumber;
	LCD_SetCursor(Line,Column);
	for(i=Length;i>0;i--)
	{
		SingleNumber=Number/LCD_Pow(16,i-1)%16;
		if(SingleNumber<10)
		{
			LCD_WriteData(SingleNumber+'0');
		}
		else
		{
			LCD_WriteData(SingleNumber-10+'A');
		}
	}
}


void LCD_ShowBinNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length)
{
	unsigned char i;
	LCD_SetCursor(Line,Column);
	for(i=Length;i>0;i--)
	{
		LCD_WriteData(Number/LCD_Pow(2,i-1)%2+'0');
	}
}

key_matrix_id key_matrix_16(){
	P1 = 0xff;
	column0 = 0;
	if(line0 == 0) {
		delay_ms(10);
		if (line0 == 0) {
			while(line0 == 0);
			return key0;
		}
	}
	if(line1 == 0) {
		delay_ms(10);
		if (line1 == 0) {
			while(line1 == 0);
			return key4;
		}
	}
	if(line2 == 0) {
		delay_ms(10);
		if (line2 == 0) {
			while(line2 == 0);
			return key8;
		}
	}
	if(line3 == 0) {
		delay_ms(10);
		if (line3 == 0) {
			while(line3 == 0);
			return key12;
		}
	}
	
	
	P1 = 0xff;
	column1 = 0;
	if(line0 == 0) {
		delay_ms(10);
		if (line0 == 0) {
			while(line0 == 0);
			return key1;
		}
	}
	if(line1 == 0) {
		delay_ms(10);
		if (line1 == 0) {
			while(line1 == 0);
			return key5;
		}
	}
	if(line2 == 0) {
		delay_ms(10);
		if (line2 == 0) {
			while(line2 == 0);
			return key9;
		}
	}
	if(line3 == 0) {
		delay_ms(10);
		if (line3 == 0) {
			while(line3 == 0);
			return key13;
		}
	}
	
	
	P1 = 0xff;
	column2 = 0;
	if(line0 == 0) {
		delay_ms(10);
		if (line0 == 0) {
			while(line0 == 0);
			return key2;
		}
	}
	if(line1 == 0) {
		delay_ms(10);
		if (line1 == 0) {
			while(line1 == 0);
			return key6;
		}
	}
	if(line2 == 0) {
		delay_ms(10);
		if (line2 == 0) {
			while(line2 == 0);
			return key10;
		}
	}
	if(line3 == 0) {
		delay_ms(10);
		if (line3 == 0) {
			while(line3 == 0);
			return key14;
		}
	}
	
	
	P1 = 0xff;
	column3 = 0;
	if(line0 == 0) {
		delay_ms(10);
		if (line0 == 0) {
			while(line0 == 0);
			return key3;
		}
	}
	if(line1 == 0) {
		delay_ms(10);
		if (line1 == 0) {
			while(line1 == 0);
			return key7;
		}
	}
	if(line2 == 0) {
		delay_ms(10);
		if (line2 == 0) {
			while(line2 == 0);
			return key11;
		}
	}
	if(line3 == 0) {
		delay_ms(10);
		if (line3 == 0) {
			while(line3 == 0);
			return key15;
		}
	}
	
	return no_key_down;
}

char get_keyboard_char() {
	key_matrix_id id;
	id = key_matrix_16();
	switch (id) {
		case key0:
			return '7';
			break;
		
		case key1:
			return '8';
			break;
		
		case key2:
			return '9';
			break;
		
		case key3:
			return '/';
			break;
		
		case key4:
			return '4';
			break;
		
		case key5:
			return '5';
			break;
		
		case key6:
			return '6';
			break;
		
		case key7:
			return '*';
			break;
		
		case key8:
			return '1';
			break;
		
		case key9:
			return '2';
			break;
		
		case key10:
			return '3';
			break;
		
		case key11:
			return '-';
			break;
		
		case key12:
			return '#';
			break;
		
		case key13:
			return '0';
			break;
		
		case key14:
			return '=';
			break;
		
		case key15:
			return '+';
			break;
		
		default:
			return '!';
			break;
		
	}
}
