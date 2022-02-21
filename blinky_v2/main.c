//PTB22 RED    cathode
//PTB21 BLUE   cathode
//PTE26 GREEN  cathode

#include "MK64F12.h"             // // Device header

void delayMs(int delay);

int main()
{
	SIM->SCGC5 |= 0x400; //Enable clock for PORTB
	PORTB->PCR[21] = 0x100; //Make PTB21 a GPIO
	PTB->PDDR |= 0x200000;  //Make PTB21 an output pin
	
	while(1)
	{
		PTB->PCOR = 0x200000; //Turn on blue LED
		delayMs(200);
		PTB->PSOR = 0x200000; //Turn off blue LED
		delayMs(200);
	}
	
}

void delayMs(int delay)
{
	int i=0;
	int j=0;
	for(i=0;i<delay;i++)
	{
		for(j=0;j<4000;j++){}
	}
}
