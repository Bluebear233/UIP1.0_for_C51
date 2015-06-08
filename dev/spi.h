#ifndef SPI_H
#define SPI_H

#include <reg52.h>
//#include "uipopt.h"

#define SPI   //Ó²¼þSPI

sfr SPADT=0xcf;
sfr SPCTL=0XCE;
sfr SPSTAT=0XCD;
sfr AUXR1=0XA2;

#define SSIG 0X80
#define SPEN 0x40
#define DORD 0X20
#define MSTR 0X10
#define CPOL 0x08
#define CPHA 0x04
#define SPR1 0X02
#define SPR0 0X01
#define SPIF 0X80
#define WCOL 0X40
#define CLOCK_16 0X00

/*ENC28J60 -- pin connect,
  use PIN to PIN*/

sbit CSN  = P1^2;   // CS
sbit SIN  = P1^3;   // MOSI
sbit SON  = P1^4;   // MISO
sbit SCKN = P1^5;   // SCK
//sbit RSTN = P3^5; // RST
//sbit INTN = P3^2; // INT 

void WriteByte(unsigned char temp);
unsigned char ReadByte(void);
void IntSpi(void);
#endif
