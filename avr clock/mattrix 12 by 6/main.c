#include<avr/io.h>
#include<util/delay.h>

#define F_CPU 1000000UL

void serialglow(int a,int b);
void fade();
void glow(int,int);
void datai(int );
void datao(int );
void datae(int);
void datar(int);

void dataa(int);
void datac(int);
void all();

int main(void)
{

	DDRB=0xff;
	DDRC=0xFF;
	DDRD=0xff; //0-right 1-left 2-up 3-down	
	fade();
	int y=11;
	while(1)
	{
		int x=0;
		while(x!=100){
			datai(y);
			x++;
		}
		x=0;
		
		while(x!=100){
			datao(y);
			x++;
		}
		x=0;
		
	
		while(x!=100){
			datae(y);
			x++;
		}
		
		fade();
		_delay_ms(50);
		
		x=0;
		int i;
		for(i=0;i<=3;i++){
			while(x!=100){
			
				datai(y);
				datae(y);
				datao(y);
				x++;
			}
		_delay_ms(25);
		}
		
		y=11;
		x=0;
		while(y!=0){
			x=0;
			while(x!=100){
				datai(y);
				datao(y);
				datae(y);
				x++;
			}
		y--;
		fade();
		_delay_ms(1);

		}
		y=11;
		
		x=0;
		while(x!=100){
			datar(y);
			dataa(y-4);
			datac(y-8);
			x++;
		}
	}

	return 0;
}




void glow(int a,int b)
{
	fade();
	PORTB=(1<<(a-1));
	
	if(b>12 || b<1) b=0;
	else if(b>8) PORTC=(0xff) ^ (1<<(b-1-8));
	
	else PORTD=(0xff) ^ (1<<(b-1));
	
}


void fade(void)
{
	
	PORTB=0x00;
	PORTC=0xff;
	PORTD=0xFF;
	
}


void datai(int x)
{
	glow(1,x);
	_delay_ms(1);
	
	glow(1,x-1);
	
	_delay_ms(1);
	glow(1,x-2);
	
	_delay_ms(1);
	glow(2,x-1);
	
	_delay_ms(1);
	glow(3,x-1);
	
	_delay_ms(1);
	glow(4,x-1);
	
	_delay_ms(1);
	glow(5,x-1);
	
	_delay_ms(1);
	glow(5,x-2);
	
	_delay_ms(1);
	glow(5,x);
	
	_delay_ms(1);

}

void datao(int x)
{
	x-=4;

	glow(1,x);
	_delay_ms(1);
	glow(1,x-1);
	
	_delay_ms(1);
	glow(1,x-2);
	
	_delay_ms(1);
	glow(2,x);
	
	_delay_ms(1);
	glow(2,x-2);
	
	_delay_ms(1);
	glow(3,x);
	
	
	_delay_ms(1);
	glow(3,x-2);
	
	_delay_ms(1);
	glow(4,x);
	
	
	_delay_ms(1);
	glow(4,x-2);
	
	_delay_ms(1);
	glow(5,x);
	
	_delay_ms(1);
	glow(5,x-2);
	
	_delay_ms(1);
	glow(5,x-1);
	
	_delay_ms(1);	

}


void datae(int x)
{
	x=x-8;

	glow(1,x);
	_delay_ms(1);
	glow(1,x-1);
	
	
	_delay_ms(1);
	glow(1,x-2);
	
	_delay_ms(1);
	glow(2,x);
	
	
	_delay_ms(1);
	glow(3,x);
	
	
	_delay_ms(1);
	glow(3,x-1);
	
	_delay_ms(1);
	glow(4,x);
	
	
	
	_delay_ms(1);
	glow(5,x);
	
	
	_delay_ms(1);
	glow(5,x-1);
	
	_delay_ms(1);	
	glow(5,x-2);
	_delay_ms(1);
	




}


void datar(int x)
{
	x=11;
	glow(1,x);
	_delay_ms(1);
	glow(1,x-2);
	
	
	_delay_ms(1);
	glow(2,x);
	
	_delay_ms(1);
	glow(2,x-1);
	
	_delay_ms(1);
	glow(3,x);
	
	_delay_ms(1);
	glow(3,x-1);
	
	
	_delay_ms(1);
	glow(3,x-2);
	
	_delay_ms(1);
	glow(4,x);
	
	
	
	_delay_ms(1);
	glow(4,x-2);
	
	
	_delay_ms(1);
	glow(5,x-1);
	
	_delay_ms(1);	
	glow(5,x-2);
	_delay_ms(1);
	
	glow(5,x);
	_delay_ms(1);
	



}


void dataa(int x)
{
	glow(1,x);
	_delay_ms(1);
	
	glow(1,x-2);
	
	_delay_ms(1);
	glow(2,x);
	
	_delay_ms(1);
	glow(2,x-2);
	
	_delay_ms(1);
	glow(3,x);
	
	
	_delay_ms(1);
	glow(3,x-2);
	
	_delay_ms(1);
	glow(3,x-1);
	
	
	
	_delay_ms(1);
	glow(4,x-2);
	
	
	_delay_ms(1);
	glow(4,x);
	
	_delay_ms(1);	
	glow(5,x-2);
	_delay_ms(1);
	
	glow(5,x);
	_delay_ms(1);
	

	glow(5,x-1);
	_delay_ms(1);
	



}


void datac(int x)
{
	glow(1,x);
	_delay_ms(1);
	
	glow(1,x-2);
	
	_delay_ms(1);
	glow(1,x-1);
	
	_delay_ms(1);
	glow(2,x);
	
	_delay_ms(1);
	glow(3,x);
	
	
	_delay_ms(1);
	glow(4,x);
	
	_delay_ms(1);
	glow(5,x);
	
	
	
	_delay_ms(1);
	glow(5,x-2);
	
	
	_delay_ms(1);
	glow(5,x-1);
	
	_delay_ms(1);
	



}