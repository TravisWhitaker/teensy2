#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

int main()
{
	CLKPR = 0x80;
	CLKPR = 0x00;
	DDRD |= 0x40;
	DDRB |= 0x01;
	int d = 0;
	int j = 0;
	int jinc = 4;
	while(1)
	{
		d += 1;
		j += jinc;
		if(d == 1000)
		{
			d = 0;
		}
		if(j == 4000 || j == 0)
		{
			jinc = -jinc;
		}
		PORTB |= 0x01; PORTD |= (1<<6);
		_delay_us(d+j);
		PORTB &= ~0x01; PORTD &= ~(1<<6);
		_delay_us(d);
	}
	return 0;
}
