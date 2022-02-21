#include "MK64F12.h"                    // Device header

void SystickDelayMs(int delay);

int main()
{
	SIM->SCGC5     |= 0x2000;				// Enable clock to PORTE
	PORTE->PCR[26]  = 0x100;				// Set PTE26 a GPIO
	PTE->PDDR      |= 0x4000000;		// Set PTE26 as output
	
	while(1)
	{
		PTE->PTOR = 0x4000000;
		SystickDelayMs(500);
	}
}

void SystickDelayMs(int delay)
{
	int i;
	SysTick->LOAD = 4194 - 1; //Because systick clock is running at 41.94MHz
	SysTick->CTRL = 5;
	
	for(i=0;i<delay;i++)
	{
		//wait until the COUNT flag is set
		while((SysTick->CTRL & 0x10000) == 0){}
	}
	SysTick->CTRL = 0;
}
