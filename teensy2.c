#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

int main()
{
	CLKPR = 0x00;
	DDRD |= (1<<6);
	while(1)
	{
		PORTD |= (1<<6);
		_delay_ms(100);
		PORTD &= ~(1<<6);
		_delay_ms(100);
	}
	return 0;
}
