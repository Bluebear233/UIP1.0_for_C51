#include "spi.h"

#ifdef SPI
void WriteByte(unsigned char temp)
{
	SPADT=temp;
	while(!(SPSTAT&SPIF));
	SPSTAT=SPIF|WCOL;
}
unsigned char ReadByte(void)
{ 
	SPADT=0;
	while(!(SPSTAT&SPIF));
	SPSTAT=SPIF|WCOL;
	return SPADT;
}
void IntSpi()
{
	SPSTAT=SPIF|WCOL;
 	SPCTL=(SSIG|SPEN|MSTR|CLOCK_16)&~CPHA;
}
#else
void WriteByte(unsigned char temp){
	idata unsigned char i;
	for(i=0;i<8;i++)
	{
		SCKN=0;//delay_us(2);//时钟信号
    	SIN = temp & 0x80;   //从高位开始发送
		SCKN=1;//delay_us(2);
		temp <<=1;			 //数据位移
	}
	SCKN=0;
} 	
unsigned char ReadByte(void){
	idata unsigned char i,dat1;
	SCKN=0;dat1=0;
	for(i=0;i<8;i++)
	{	
		SCKN=1;//delay_us(2);
		dat1 <<=1;
		dat1 |= SON; 
		SCKN=0;	//delay_us(2);
	}	
  return dat1;	
}
#endif
