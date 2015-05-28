#include "spi.h"

void WriteByte(unsigned char temp)
{
  idata unsigned char i;
  for(i=0;i<8;i++)
  {
	SCKN=0;//delay_us(2);
    SIN = temp & 0x80;
	SCKN=1;//delay_us(2);
	temp <<=1;
  }
  SCKN=0;
}

unsigned char ReadByte(void)
{
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
