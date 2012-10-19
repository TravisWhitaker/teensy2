//http://code.google.com/p/micro-64-controller/wiki/Mini64Controller

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>

volatile int trigger = 0;

ISR(INT0_vect)
{
	PORTD |= (1<<6);
	trigger = 1;
}

int main()
{	
	CLKPR = 0x80;
	CLKPR = 0x00; //8 Mhz, 8 cycles per microsecond
	cli();
	DDRD |= (1<<6); //D6(LED) in output mode
	EICRA |= (0<<0);
	EICRA |= (1<<1); //Set the interrupt to trigger given a low level on D0(INT0)
	EIMSK |= (1<<0); //Enable the interrupt
	sei();
	while(1)
	{
		if(trigger == 1)
		{
			PORTD |= (1<<6);
		}
	}
}
