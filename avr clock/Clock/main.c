#include<avr/io.h>
#include<util/delay.h>
#include<avr/ds1307.h>

#define F_CPU 16000000UL

int main()
{
	unsigned char sec=0,min=0;
	DDRB=0xff;
	DDRC &= ~(0b00000011);
	
	ds1307_second_write(0);
	ds1307_minute_write(0);

	while(1)
	{
		sec=ds1307_read_second();
		min=ds1307_read_minute();
		sec=convert_bcd_to_decimal(min);

		if (sec== 5) PORTB =0b00000001;
		if (sec == 10)PORTB=0b00000010;
		if (sec== 15) PORTB=0b00000100;
		if (sec == 20)PORTB=0b00001000;	
	
	}


}