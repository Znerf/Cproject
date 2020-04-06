#include<avr/io.h>
#include<util/delay.h>

#define F_CPU 1000000UL

void serialglow(int a,int b);
void fade();
void glow(int,int);




int main(void)
{

	DDRB=0xFF;
	DDRC=0xFF;
	DDRD=0x00; //0-right 1-left 2-up 3-down	
	fade();
	
	int x,y;
	x=1;y=1;
	glow(x,y);
	s
	while(1)
	{
		//if(PIND & (1<<0)){
		//	x++;
		//	glow(x,y);
		//}
		
	}

	return 0;
}



void serialglow(int a,int b)
{
	int x,y;
	x=a/10;
	y=a % 10;
		
	glow(x,y);
	_delay_ms(2);
	
	x=b/10;
	y=b % 10;
		
	glow(x,y);
	_delay_ms(2);
	

}

void glow(int a,int b)
{
	PORTB=(1<<(a-1));
	
	PORTC=(0xff) ^ (1<<(b-1));	
}


void fade(void)
{
	
	PORTB=0x00;
	PORTC=0xff;
	
}


void i(void){
	serialglow(66,65);
	serialglow(64,55);

	serialglow(45,35);

	serialglow(36,34);
	fade();



}