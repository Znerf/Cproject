#include<avr/io.h>
#include<util/delay.h>

#define F_CPU 16000000UL

void delay(int a)
{

	_delay_ms(a);
	_delay_ms(a);
	_delay_ms(a);
	_delay_ms(a);
	_delay_ms(a);
	_delay_ms(a);
	_delay_ms(a);
	_delay_ms(a);
	_delay_ms(a);
	_delay_ms(a);

}
int main()
{
	DDRC=0xFF;
	DDRD=0b00011111;
	DDRB=0b00011111;
	//DDRC=0b11111111;
	
	while(1)
	{
		PORTB =	0b00011111;
		PORTC =	0b11111111;
		PORTD =	0b00011111;
		delay(750);
		PORTB =	0b00011110;
		delay(750);
		PORTB =	0b00011100;
		delay(750);
		PORTB =	0b00011000;
		delay(750);
		PORTB =	0b00010000;
		delay(750);
		PORTB =	0b00000000;
		delay(30);
		
		PORTC =	0b11111111;
		delay(750);
		PORTC =	0b11111110;
		delay(750);
		PORTC =	0b11111100;
		delay(750);
		PORTC =	0b11111000;
		delay(750);
		PORTC =	0b11110000;
		delay(750);
		PORTC =	0b11100000;
		delay(750);
		PORTC =	0b11000000;
		delay(750);
		PORTC =	0b10000000;
		delay(750);
		PORTC =	0b00000000;
		delay(30);
		
		PORTD =	0b00011111;
		delay(750);
		PORTD =	0b00011110;
		delay(750);
		PORTD =	0b00011100;
		delay(750);
		PORTD =	0b00011000;
		delay(750);
		PORTD =	0b00010000;
		delay(750);
		PORTD =	0b00000000;

	//	PORTC =	0b00000001;
	//	delay(750);
	//	PORTC =	0b00000011;
	//	delay(750);
	//	PORTC =	0b00000111;
	//	delay(750);
	//	PORTC =	0b00001111;
	//	delay(750);
	//	PORTC =	0b00011111;
	//	delay(750);
		
		
	}


}