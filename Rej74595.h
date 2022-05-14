#ifndef REJ74595_H
#define REJ74595_H

#include <Arduino.h>
#include <SPI.h>

#define OEL 0
#define LAT	1

class Rej74595{
	
	private:
	uint8_t val;	//wartość
	uint8_t lat;
	uint8_t typ;
	uint8_t oute;	//output enable pin
	int del;	//delay time	
	sendSPI(void);
	
	public:
	//inicjacja urzadzenia
	// jesli type = OEL ("0") to pin latch = pin outen
	// jesli type = LAT ("1") to latch i outen to osobne piny
	// latch - pin, do ktorego podpiety jest sygnal Latch rejestru
	// outen - pin, do ktorego podpiety jest sygnal OutEn rejestru
	// delau - długosc impulsu latch (us)
	begin(uint8_t type,uint8_t latch, uint8_t outen, int delau);
	//wpisuje wartosc "Value" do wyswietlenia ale nie wyswietla
	WriteValue(uint8_t);
	//odczytuje wartosc "Value" do wyswietlenia
	uint8_t ReadValue(void);
	//wyświetla wartosc "Value"
	Display(void);
	//przesuwa wartosc "Value" bitowo o 1 i wyswietla 
	uint8_t StepDisplay(uint8_t);
	//przesuwa wartosc "Value" bitowo o 1 i wyswietla - jesli jest przesuniecie
	//to dodaje 1 tworzac efekt petli
	uint8_t LoopDisplay(void);
	//wpisuje wartosc "Value" i wyswietla ja
	WriteDisplay(uint8_t);

};


#endif	/* REJ74595_H*/