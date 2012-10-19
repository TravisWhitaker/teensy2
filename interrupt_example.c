//http://code.google.com/p/micro-64-controller/wiki/Mini64Controller

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>

volatile int trigger = 0;
uint64_t count = 0;

ISR(INT0_vect)
{
	trigger = 1;
}

int main()
{	
	CLKPR = 0x80;
	CLKPR = 0x00; //64 khz
	cli();
	DDRD |= (1<<6); //D6(LED) in output mode
	EICRA |= (0<<0);
	EICRA |= (1<<1); //Set the interrupt to trigger given a low level on D0(INT0)
	EIMSK |= (1<<INT0); //Enable the interrupt
	sei();
	while(1)
	{
		cli();
		count++;
		sei();
		if(count == 100)
		{
			cli();
			count = 0;
			trigger = 0;
			sei();
		}
		if(trigger == 1)
		{
			PORTD |= (1<<6);
		}
		else
		{
			PORTD &= ~(1<<6);
		}
	}
}
