//It's dangerous to go alone, take these:
//http://www.larsivar.com/cp/comments.php?y=11&m=09&entry=entry110905-190247
//http://code.google.com/p/micro-64-controller/wiki/Mini64Controller

#include <avr/io.h>
#include <avr/pgmspace.h>
//DELAY IS SHIT. USE NOPS.

void zero()
{
	PORTD &= ~(1<<0);
	asm volatile("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop");
	PORTD &= ~(1<<0);
	asm volatile("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop");
}

void one()
{
	PORTD |= (1<<0);
	asm volatile("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop");
	PORTD &= ~(1<<0);
	asm volatile("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop");
}

int main()
{
	CLKPR = 0x80;
	CLKPR = 0x01; //8 Mhz, 125 nanoseconds per cycle, 8 cycles per microsecond
	DDRD |= (1<<6);
	PORTD |= (1<<6);
	DDRD |= (1<<0);
	asm volatile("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop");
	zero();zero();zero();zero();zero();one();zero();one();
	zero();zero();zero();zero();zero();zero();zero();zero();
	zero();zero();zero();zero();zero();zero();one();zero();
	DDRD &= ~(1<<0);
	while(1)
	{
		if(PIND & (1<<0));
		else
		{
			DDRD |= (1<<0);
			zero();zero();zero();zero();zero();zero();zero();zero();zero();zero();zero();zero();zero();zero();zero();zero();zero();zero();zero();zero();zero();zero();zero();zero();zero();zero();zero();zero();zero();zero();zero();zero();
			DDRD &= ~(1<<0);
		}
	}
	return 0;
}
