#ifndef REJ74595_H
#define REJ74595_H

#include <Arduino.h>
#include <SPI.h>

#define OEL 0
#define LAT	1

class Rej74595{
	
	private:
	int val;	//wartość
	char lat;
	int typ;
	char oute;	//output enable pin
	int del;	//delay time	
	sendSPI(void);
	
	public:
	//inicjacja urzadzenia
	// jesli type = OEL ("0") to pin latch = pin outen
	// jesli type = LAT ("1") to latch i outen to osobne piny
	// delau - długosc impulsu latch
	begin(int type,char latch, char outen, int delau);
	//wpisuje wartosc "Value" do wyswietlenia ale nie wyswietla
	WriteValue(int);
	//odczytuje wartosc "Value" do wyswietlenia
	int ReadValue(void);
	//wyświetla wartosc "Value"
	Display(void);
	//przesuwa wartosc "Value" bitowo o 1 i wyswietla 
	int StepDisplay(int);
	//przesuwa wartosc "Value" bitowo o 1 i wyswietla - jesli jest przesuniecie
	//to dodaje 1 tworzac efekt petli
	int LoopDisplay(void);
	//wpisuje wartosc "Value" i wyswietla ja
	WriteDisplay(int);

};


#endif	/* REJ74595_H*/