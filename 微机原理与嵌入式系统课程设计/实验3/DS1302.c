#include <reg51.h>
#include <string.h>
#include <stdio.h>
#include <intrins.h>

#define uchar unsigned char
#define uint unsigned int	
extern bit Dis_flag_2 = 0;
extern char Adjust_count;

#define SEC_R       0x81
#define	MIN_R	      0x83
#define	HR_R	      0x85
#define	DATE_R	    0x87
#define	MONTH_R	    0x89
#define	DAY_R	      0x8b
#define	YEAR_R	    0x8d
#define	CL_BURST_R	0xbf
#define	SEC_W	      0x80
#define	MIN_W	      0x82
#define	HR_W	      0x84
#define	DATE_W	    0x86
#define	MONTH_W	    0x88
#define	DAY_W	      0x8a
#define	YEAR_W	    0x8c
#define	CTRL_W	    0x8e	
#define	TR_CH_W	    0x90
#define	CL_BURST_W	0xbe
#define	R_RAM	      0xcl	
#define	W_RAM	      0xc0	
 
//接口定义
sbit IO	  = P2^6;
sbit SCLK = P2^5;
sbit REST = P2^4;
 
//变量定义
uchar Dstring[15];
uchar Dtimer[7] = {12, 7, 7, 28, 3, 12, 0};
char code *weektable[]={"日", "一", "二", "三", "四", "五", "六"} ;

//函数声明
extern void LCD_Init();
extern void writeString(unsigned char *pcStr, unsigned short x0, unsigned int y0);
uchar single_R(uchar com);
void  single_W(uchar com, uchar W_data);
void Set_ds1302(); 
void RD_ds1302(); 
void DIS_ds1302();
 
void  delay_1302(){
	_nop_();
	_nop_() ;
	_nop_() ;
}
	
uchar single_R(uchar com){
	uchar R_data = 0;
	uchar i;
	SCLK = 0;
	IO = 0;
	REST = 1;
	for(i=0; i<8 ;i++){
		if ((com & 0x01) == 0x01){
			IO = 1;
		}
		else{
			IO = 0;
		}
		SCLK = 1;
		delay_1302();
		SCLK = 0;
		com	= com >> 1;
	}
	for(i=0; i<8; i++){
		R_data = R_data >> 1;
		SCLK = 0;
		delay_1302();
		if (IO == 1){
			R_data |= 0x80;
		}
			SCLK = 1;
	}

	SCLK = 0;
	IO = 0;
	REST = 0;
	
	return R_data;
}

void single_W(uchar com, uchar W_data){
	uchar i;
	SCLK = 0;
	IO = 0;
	REST = 1;
	for(i=0; i<8; i++){
		if((com & 0x01) == 0x01){
			IO = 1;
		}
		else{
			IO = 0;
		}
		SCLK = 1;
	  delay_1302();
		SCLK = 0;
		com	= com >> 1;
	}
 
	for(i=0; i<8; i++){ 
		if((W_data & 0x01) == 0x01){
			IO = 1;
		}
		else{
			IO = 0;
		}
		SCLK = 1;
		delay_1302();
		SCLK = 0;
		W_data = W_data >> 1;
	}
	SCLK = 0;
	IO = 0;
	REST = 0;
}

void Set_ds1302(){
	uchar i;
	for (i=0; i<7; i++){
		single_W(YEAR_W -	2*i, ((Dtimer[i]/10) << 4) + (Dtimer[i] % 10));
	}
}

void RD_ds1302(){
	uchar i, n;
	for(i=0; i<7; i++){
		n = single_R(YEAR_R - i*2);
		Dtimer[i] = ((n>>4) * 10) + (n & 0x0f);
	}
}

void DIS_ds1302(){
	Dis_flag_2 = Adjust_count == 0;
	sprintf(Dstring, "%c%c", (Dtimer[0]/10) + '0',(Dtimer[0]%10) + '0');
	writeString(Dstring, 3, 2);  //年
	Dis_flag_2 = Adjust_count == 2;
	sprintf(Dstring, "%c%c", (Dtimer[2]/10) + '0',(Dtimer[2]%10) + '0');
	writeString(Dstring, 3, 6);  //月
 	Dis_flag_2 = Adjust_count == 3;
	sprintf(Dstring, "%c%c", (Dtimer[3]/10) + '0',(Dtimer[3]%10) + '0');
	writeString(Dstring, 3, 10);  //日
	Dis_flag_2 = Adjust_count == 4;
	sprintf(Dstring, "%c%c", (Dtimer[4]/10) + '0',(Dtimer[4]%10) + '0');
	writeString(Dstring, 6, 2);  //时
	Dis_flag_2 = Adjust_count == 5;
	sprintf(Dstring, "%c%c", (Dtimer[5]/10) + '0',(Dtimer[5]%10) + '0');
	writeString(Dstring, 6, 6);  //分	
	Dis_flag_2 = Adjust_count == 6;
	sprintf(Dstring, "%c%c", (Dtimer[6]/10) + '0',(Dtimer[6]%10) + '0');
	writeString(Dstring, 6, 10);  //秒	
	sprintf(Dstring, "星期%s", weektable[Dtimer[1] - 1]);
	writeString(Dstring, 9, 8);  //周
}