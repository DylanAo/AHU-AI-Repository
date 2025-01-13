#include <reg51.h>
#include <string.h>
#include <stdio.h>
#include <intrins.h>

#define uchar unsigned char
#define uint unsigned int //�����
#define SEC_R 0x81 //����
#define MIN_R 0x83//����
#define HR_R 0x85 //��ʱ
#define DATE_R 0x87//����
#define MONTH_R 0x89//����
#define DAY_R 0x8b//������
#define YEAR_R 0x8d//����
#define CL_BURST_R 0xbf//��ͻ��ģʽλ

#define SEC_W 0x80//д��
#define MIN_W 0x82//д��
#define HR_W  0x84//дʱ
#define	DATE_W 0x86//д��
#define	MONTH_W 0x88//д��
#define	DAY_W 0x8a//д����
#define YEAR_W 0x8c//д��
#define CTRL_W 0x8e//д����λ
#define TR_CH_W 0x90 //д����
#define CL_BURST_W 0xbe//дͻ������λ
#define R_RAM 0xc1//��RAM
#define W_RAM 0xc0//дRAM

sbit IO=P3^0;
sbit SCLK=P3^1;
sbit REST=P3^2;
bit	Timer_flag=1;
uchar Timer_count=0;
uchar Dstring[15];//��ʾ�ַ���
uchar Dtimer[7]={12,7,7,28,3,12,0};//ʮ�������ݣ��ꡢ���ڡ��¡��ա�ʱ���֡��룩
char code *weektable[]={"��","һ","��","��","��","��","��"};
extern void LCD_Init();
extern void writeString(unsigned char *pcStr,unsigned short x0,unsigned int y0);
uchar single_R(uchar com);
void single_W(uchar com,uchar W_data);
void Set_ds1302();
void RD_ds1302();
void DIS_ds1302();

void delay_1302()
{
	_nop_();
	_nop_();
	_nop_();
}

uchar single_R(uchar com)
{
	uchar R_data=0;
	uchar i;
	SCLK=0;
	IO=0;
	REST=1;
	for(i=0;i<8;i++)
	{
		if((com&0x01)==0x01)
			IO=1;
		else
			IO=0;
		SCLK=1;
		delay_1302();
		SCLK=0;
		com=com>>1;
	}
	for(i=0;i<8;i++)
	{
		R_data=R_data>>1;
		SCLK=0;
		delay_1302();
		if(IO==1)
			R_data|=0x80;
		SCLK=1;
	}
	SCLK=0;
	IO=0;
	REST=0;
	return R_data;
}

void simgle_W(uchar com,uchar W_data)
{
	uchar i;
	SCLK=0;
	IO=0;
	REST=1;
	for(i=1;i<8;i++)
	{
		if((com&0x01)==0x01)
			IO=1;
		else
			IO=0;
		SCLK=1;
		delay_1302();
		SCLK=0;
		com=com>>1;
	}
	for(i=0;i<8;i++)
	{
		if((W_data&0x01)==0x01)
			IO=1;
		else
			IO=0;
		SCLK=1;
		delay_1302();
		SCLK=0;
		W_data=W_data>>1;					
	}
	SCLK=0;
	IO=0;
	REST=0;
}

void Set_ds1302()
{
	uchar i;	
	for(i=0;i<7;i++)
	{		
	  single_W(YEAR_W-2*i,((Dtimer[i]/10)<<4)+(Dtimer[i]%10));
	}
}

void RD_ds1302()
{
	uchar i,n;
	for(i=0;i<7;i++)
	{
		n=single_R(YEAR_R-2*i);
		Dtimer[i]=((n>>4)*10)+(n&0x0f);
	}
}

void DIS_ds1302()
{
	sprintf(Dstring,"%c%c",(Dtimer[0]/10)+'0',(Dtimer[0]%10)+'0');
	writeString(Dstring,3,2);
	sprintf(Dstring,"%c%c",(Dtimer[2]/10)+'0',(Dtimer[2]%10)+'0');
	writeString(Dstring,3,6);
	sprintf(Dstring,"%c%c",(Dtimer[3]/10)+'0',(Dtimer[3]%10)+'0');
	writeString(Dstring,3,10);
	sprintf(Dstring,"%c%c",(Dtimer[4]/10)+'0',(Dtimer[4]%10)+'0');
	writeString(Dstring,6,2);
	sprintf(Dstring,"%c%c",(Dtimer[5]/10)+'0',(Dtimer[5]%10)+'0');
	writeString(Dstring,6,6);
	sprintf(Dstring,"%c%c",(Dtimer[6]/10)+'0',(Dtimer[6]%10)+'0');
	writeString(Dstring,6,10);
	sprintf(Dstring,"����%s",weektable[Dtimer[1]-1]);
	writeString(Dstring,9,8);
}

void main(void)
{
	LCD_Init();
	TMOD=0x01;
	TH0=0xb0;
	TL0=0x3c;
	TR0=1;
	ET0=1;
	EA=1;
	writeString("DS1302����",0,4);
	writeString("2012��07��28��",3,0);
	writeString("03ʱ12��00��",6,2);
	writeString("������",9,8);
	Set_ds1302();
	while(1)
	{
		if(Timer_flag==1)
		{
			Timer_flag=0;
			RD_ds1302();
			DIS_ds1302();
		}
	};
}
void timer0_int(void) interrupt 1 using 0
{
	TH0=0xb0;
	TL0=0x3c;
	Timer_count++;
	if(Timer_count==20)
	{
		Timer_count=0;
		Timer_flag=1;
	}
}




