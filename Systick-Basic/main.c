#include "MK64F12.h"                    // Device header

//Configure Systick to toggle RED led at 200ms

int main()
{
	SIM->SCGC5 |=0x0400;
	PORTB->PCR[22] = 0x100;
	PTB->PDDR |= 0x0400000;			// Set PTB21 as output
	
	//Configure Systick
	SysTick->LOAD = 10000000 - 1; // System clock is 50MHz and for 200ms  
	SysTick->CTRL = 5;  //Enable systick, no interrupt, use system clock.
	
	while(1)
	{
		if(SysTick->CTRL & 0x10000) //if COUNT flag is set
		{
			PTB->PTOR = 0x400000; //Toggle Red LED
		}
	}
}
