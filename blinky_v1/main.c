//PTB22 RED    cathode
//PTB21 BLUE   cathode
//PTE26 GREEN  cathode

#include "MK64F12.h"                    // Device header




void delayMs(int delay);

int main()
{
	//SCGC5
	//Direction Register : PDDR
	//Data // PDOR
	//PCR - Pin Control Register
	

	SIM->SCGC5     |= 0x400;				// 0b 0100 0000 0000 : Enable clock to Port B
	PORTB->PCR[22]  = 0x100;				// Set PTB22 a GPIO
	PTB->PDDR      |= 0x400000;			// Set PTB21 as output
	PORTB->PCR[21]  = 0x100;        // Set PTB21 a GPIO
	PTB->PDDR      |= 0x200000;     // Set PTB21 as output
	
	SIM->SCGC5     |= 0x2000;				// Enable clock to PORTE
	PORTE->PCR[26]  = 0x100;				// Set PTE26 a GPIO
	PTE->PDDR      |= 0x4000000;		// Set PTE26 as output
	
	while(1)
	{
		PTB->PDOR &=~0x400000;			// Turn Red LED on
		delayMs(200);
		PTB->PDOR |= 0x400000;			// Turn Red LED off
		delayMs(200);
		PTB->PDOR &=~0x200000;			// Turn Blue LED on
		delayMs(200);
		PTB->PDOR |= 0x200000;			// Turn Blue LED off
		delayMs(200);
		PTE->PDOR &=~0x4000000;			// Turn Green LED on
		delayMs(200);
		PTE->PDOR |= 0x4000000;			// Turn Gren LED off
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
