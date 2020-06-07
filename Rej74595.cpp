#include "Rej74595.h"




Rej74595::begin(int type,char latch, char outen, int delau)
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

Rej74595::WriteValue(int value)
{
	val = value;	
}


int Rej74595::ReadValue()
{
	return val;
}

Rej74595::Display(void)
{
	sendSPI();
}

int Rej74595::StepDisplay(int bit1)
{
	int res =0;
	if(val &_BV(7)) res=1;
	val = val<<1;
	val = val + bit1;
	
	sendSPI();
	
	return res;
}

int Rej74595::LoopDisplay(void)
{
	int res =0;
	if(val &_BV(7)) res=1;
	val = val<<1;
	val = val+res;
	
	sendSPI();
	
}

Rej74595::WriteDisplay(int in)
{
	val = in;
	sendSPI();
}


Rej74595::sendSPI()
{
	if(typ==LAT)digitalWrite(oute,HIGH);
	if(typ==LAT)delay(del);
	SPI.transfer(val);
	SPI.endTransaction();
	digitalWrite(lat,LOW);
	delay(del);
	digitalWrite(lat,HIGH);
	if(typ==LAT)delay(del);	
	if(typ==LAT)digitalWrite(oute,LOW);
	
	
}