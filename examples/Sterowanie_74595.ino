#include <SPI.h>

/************************************************
 * <b>Podłaczenie pinów </b>
 * Arduino = Płytka 74595
 * Pin8 = LATCH = OUTEN
 * Pin11 = IN
 * Pin13 = SCK
 * 
 * tryb SPI_MODE3
 * MSBFIRST - działa "od prawej"
 * LSBFIRST - działa "od lewej" 
 *  
 * **********************************************
 */

#define outen 9
#define rej 4 //liczba rejestrów

char poz = 0;
int i=0;
char arr[rej];

void setup() {
  // put your setup code here, to run once:
pinMode(outen,OUTPUT);
digitalWrite(outen,HIGH);
SPI.begin();
SPI.beginTransaction(SPISettings(140000, LSBFIRST, SPI_MODE3));
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

//Serial.print(i);
//Serial.print("  ");
//Serial. println(i,BIN);
//SPIsend(i);
//i=i<<1;
//delay(700);
//if(i>0x80) i=1;

char data;

data = _BV(poz);
poz++;
if(poz==8) poz=0;

ZerujArr();
arr[i]=data;

for(char k=0;k<rej;k++) SPIsend(arr[k]);    



       
if(poz==0x00) i++;
if(i==rej)i=0;
  delay(700);
}

void SPIsend(int datain)
{
  
SPI.transfer(datain);
SPI.endTransaction();
digitalWrite(outen,LOW);
delay(2);
digitalWrite(outen,HIGH);
}

void ZerujArr(void)
{
  for(char i=0;i<rej;i++) arr[i]=0x00;
}
