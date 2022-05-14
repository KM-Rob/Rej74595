#include "Disp74595.h"

Disp74595::begin(uint8_t NO, uint8_t type,uint8_t latch, uint8_t outen, int delau)
{
	num = NO;
	typ = type;
	oute = outen;
	for(uint8_t i=0;i<num;i++)
		rej[i].begin(OEL,latch,outen,delau);

	if(typ==LAT)
		{
		pinMode(oute,OUTPUT);
		digitalWrite(oute,LOW);
		}	
}

Disp74595::WriteDisplay(uint8_t val)
{
	for(uint8_t i=0;i<num;i++)
      rej[i].WriteDisplay(val);
	
}

Disp74595::StepDisplay(uint8_t val)
{
	rej[0].WriteDisplay(val);
    if(typ==LAT)digitalWrite(oute,HIGH);
	if(typ==LAT) delayMicroseconds(1);
	for(uint8_t i=1;i<num;i++)
      rej[i].WriteDisplay(0);
	if(typ==LAT) delayMicroseconds(1);
	if(typ==LAT)digitalWrite(oute,LOW);
}

Disp74595::LoopDisplay(void)
{
uint8_t a=0;
    a=rej[num-1].ReadValue()>>7;
    a = a&_BV(0);
    if(typ==LAT)digitalWrite(oute,HIGH);
	if(typ==LAT) delayMicroseconds(1); 
	for(uint8_t i=0;i<num;i++)
      a=rej[i].StepDisplay(a);	
  	if(typ==LAT) delayMicroseconds(1);
	if(typ==LAT)digitalWrite(oute,LOW);
}

uint8_t Disp74595::ReadFirst(void)
{
	return rej[0].ReadValue();
}