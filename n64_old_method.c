//It's dangerous to go alone, take these:
//http://www.larsivar.com/cp/comments.php?y=11&m=09&entry=entry110905-190247
//http://code.google.com/p/micro-64-controller/wiki/Mini64Controller

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>

void zero()
{
	PORTD &= ~(1<<1);
	asm volatile("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop");
	PORTD |= (1<<1);
	asm volatile("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop");
}

void one()
{
	PORTD &= ~(1<<1);
	asm volatile("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop");
	PORTD |= (1<<1);
	asm volatile("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop");
}

int main()
{	
	CLKPR = 0x01; //8 Mhz, 8 cycles per microsecond
	DDRD |= (1<<6); //D6 output (light)
	PORTD |= (1<<6); //D6 high (light)
	DDRD &= ~(1<<0); //D0 input (data in[interrupt])
	PORTD |= (1<<0); //Turn on internal pull-up to keep N64 from freezing
	DDRD |= (1<<1); //D1 output (data out)
	PORTD |= (1<<1); //Always start with pin HIGH to keep N64 from freezing
	asm volatile("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop");
	while(1)
	{
		zero();
	}
	return 0;
}
