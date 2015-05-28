#ifndef SPI_H
#define SPI_H

#include <reg52.h>
//#include "uipopt.h"

/*ENC28J60 -- pin connect,
  use PIN to PIN*/
//sbit VCC1 = P2^0; // VCC1 NO USE

sbit CSN  = P1^2;   // CS
sbit SIN  = P1^3;   // MOSI
sbit SON  = P1^4;   // MISO
sbit SCKN = P1^5;   // SCK
//sbit RSTN = P3^5; // RST
//sbit INTN = P3^2; // INT 

void WriteByte(unsigned char temp);
unsigned char ReadByte(void);

#endif
