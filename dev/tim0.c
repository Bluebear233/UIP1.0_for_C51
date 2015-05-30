// File Name: tim0.c
// Author:lanxiong233
// Date:

#include <reg52.h>
#include "clock-arch.h"
#include "tim0.h"

/* ��ʱ��0������TCP���Ӽ�ʱ��ARP����ʹ�� */
clock_time_t tick_cnt = 0;

/* ��ʼ����ʱ��0 */
void Init_Tim0()
{
	AUXR &= 0x7F;
	TMOD &= 0xF0;
	TH0 = 0x50;       /*33M������,��ʱ20ms*/
	TL0 = 0x38;
	EA = 1;           /*�����ж�*/
	ET0 = 1;          /*����ʱ��0�ж�*/
	TR0 = 1;          /*����TR0*/
}

/*��ʱ��0�жϷ�����*/
void  timer0()  interrupt 1
{
	tick_cnt ++;
}