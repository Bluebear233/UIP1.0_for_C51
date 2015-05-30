// File Name:uaer.h 
// Author:   lanxiong233
// Date:     UART for C51

#include <reg52.h>
#include "uart.h"

/* ��ʼ������ */
void InitUart(){
	SCON = 0x50;		//8???,?????
	AUXR |= 0x40;		//???1???Fosc,?1T
	AUXR &= 0xFE;		//??1?????1???????
	TMOD &= 0x0F;		//?????1?16???????
	TL1 = 0xf4;		//??????
	TH1 = 0xFf;		//??????
	ET1 = 0;		//?????1??
	TR1 = 1;		//?????1		
	TI = 1;
}