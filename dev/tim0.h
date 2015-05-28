#ifndef __TIM0_H__
#define __TIM0_H__
sfr AUXR        =   0x8E;

extern clock_time_t tick_cnt;
void Init_Tim0();
#endif