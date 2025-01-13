#include "ahuai51.h"
/*Tis liabry without LCD16012 is written by ChenAo for AHU-AI*/
	
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

void LCD_Clean() {
	LCD_ShowString(1, 1, "                ");
	LCD_ShowString(2, 1, "                ");
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

void welcome_page(){
	LCD_Clean();
	IO_WritePin(IO_P3, PIN_ALL, PIN_RESET);
	LCD_ShowString(1, 1, "Welcome purchase");
}


uint8_t get_keyboard_amount() {
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
		
		case key4:
			return '4';
			break;
		
		case key5:
			return '5';
			break;
		
		case key6:
			return '6';
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
			return CANCEL;
			break;
		
		case key13:
			return '0';
			break;
		
		case key15:
			return CONFRIM;
			break;
		
		default:
			return NONE;
		
	}
}

uint8_t get_keyboard_cargo() {
	key_matrix_id id;
	id = key_matrix_16();
	switch (id) {
		case key0:
			return cargo7;
			break;
		
		case key1:
			return cargo8;
			break;
		
		case key4:
			return cargo4;
			break;
		
		case key5:
			return cargo5;
			break;
		
		case key6:
			return cargo6;
			break;

		case key8:
			return cargo1;
			break;
		
		case key9:
			return cargo2;
			break;
		
		case key10:
			return cargo3;
			break;
		
		case key11:
			return CANCEL;
			break;	
		
		case key15:
			return CONFRIM;
			break;
		
		default:
			return NONE;
	}
}

uint8_t get_keyboard_money() {
	key_matrix_id id;
	id = key_matrix_16();
	switch (id) {
		case key0:
			return coin1_cash1;
			break;
		
		case key1:
			return coin1_cash1;
			break;
		
		case key2:
			return cash5;
			break;
		
		case key3:
			return cash10;
			break;
		
		case key4:
			return cash20;
			break;

		case key5:
			return cash50;
			break;
		
		case key6:
			return cash100;
			break;
		
		case key11:
			return CANCEL;
			break;	
		
		case key15:
			return CONFRIM;
			break;
		
		default:
			return NONE;
	}
}


void change_collection_init(change_collection* p) {
    p->money1 = 0;
    p->money5 = 0;
    p->money10 = 0;
    p->money20 = 0;
    p->money50 = 0;
    p->money100 = 0;
}


void get_change(change_collection* p, int money) {
    p->money100 = money / 100;
    money = money - (p->money100) * 100;
    while (money >= 10) {
        if (money >= 50) {
            p->money50++;
            money = money - (p->money50) * 50;
        }
        if (money >= 20) {
            p->money20++;
            money = money - (p->money20) * 20;
        }
        if (money >= 10) {
            p->money10++;
            money = money - (p->money10) * 10;
        }
    }
		while (money >= 5) {
         p->money5++;
         money = money - (p->money5) * 5;
        }
		p->money1 = money;
}