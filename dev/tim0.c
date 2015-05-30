// File Name: tim0.c
// Author:lanxiong233
// Date:

#include <reg52.h>
#include "clock-arch.h"
#include "tim0.h"

/* 定时器0用来做TCP连接计时和ARP更新使用 */
clock_time_t tick_cnt = 0;

/* 初始化定时器0 */
void Init_Tim0()
{
	AUXR &= 0x7F;
	TMOD &= 0xF0;
	TH0 = 0x50;       /*33M晶振下,定时20ms*/
	TL0 = 0x38;
	EA = 1;           /*允许中断*/
	ET0 = 1;          /*允许时间0中断*/
	TR0 = 1;          /*启动TR0*/
}

/*定时器0中断服务函数*/
void  timer0()  interrupt 1
{
	tick_cnt ++;
}