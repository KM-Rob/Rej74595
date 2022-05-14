#include "Rej74595.h"




Rej74595::begin(uint8_t type, uint8_t latch, uint8_t outen, int delau)
{
	oute = outen;
	del = delau;
	lat = latch;
	typ = type;
	
	pinMode(lat,OUTPUT);
	
	digitalWrite(lat,HIGH);
	SPI.begin();
	SPI.beginTransaction(SPISettings(140000, LSBFIRST, SPI_MODE3));
	if(typ==LAT)
		{
		pinMode(oute,OUTPUT);
		digitalWrite(oute,LOW);
		}
	
}

Rej74595::WriteValue(uint8_t value)
{
	val = value;	
}


uint8_t Rej74595::ReadValue()
{
	return val;
}

Rej74595::Display(void)
{
	sendSPI();
}

uint8_t Rej74595::StepDisplay(uint8_t bit1)
{
	uint8_t res =0;
	if(val &_BV(7)) res=1;
	val = val<<1;
	val = val + bit1;
	
	sendSPI();
	
	return res;
}

uint8_t Rej74595::LoopDisplay(void)
{
	uint8_t res =0;
	if(val &_BV(7)) res=1;
	val = val<<1;
	val = val+res;
	
	sendSPI();
	
}

Rej74595::WriteDisplay(uint8_t in)
{
	val = in;
	sendSPI();
}


Rej74595::sendSPI()
{
	if(typ==LAT)digitalWrite(oute,HIGH);
	if(typ==LAT)delayMicroseconds(del);
	SPI.transfer(val);
	SPI.endTransaction();
	digitalWrite(lat,LOW);
	delayMicroseconds(del);
	digitalWrite(lat,HIGH);
	if(typ==LAT)delayMicroseconds(del);	
	if(typ==LAT)digitalWrite(oute,LOW);
	
	
}