#ifndef DISP74595_H
#define DISP74595_H

#include <Rej74595.h>

#define MAXREG 20


class Disp74595
{
	private:
	uint8_t num;
	uint8_t typ;
	uint8_t oute;	//output enable pin
	Rej74595 rej[MAXREG];
	
	public:
	// NO - liczba wyswietlaczy
	// pozostale parametry jak w bibliotece Rej595
	begin(uint8_t NO, uint8_t type, uint8_t latch, uint8_t outen, int delau);
	// wyswietla na wszystkich wyswietlaczach ta sama wartosc - val
	WriteDisplay(uint8_t val);
	// wyswietla wartosc val na pierwszym wyswietlaczu a na reszcie 0
	StepDisplay(uint8_t val);
	// przesuwa wartosci wyswietlaczy o 1 i wyswietla
	LoopDisplay(void);
	// odczytuje aktualna wartosc z pierwszego wyswietlacza
	uint8_t ReadFirst(void);
};






#endif /* DISP74595_H */