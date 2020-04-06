#include<avr/io.h>
#include<util/delay.h>

void b(position)
{
	if (position==1)PORTB= 0b11100001;
	
	else if(position==2)PORTB= 0b11010001;
	else if(position==3)PORTB= 0b10110001;
	
	else if(position==4)PORTB= 0b01110001;
	else if(position==5)PORTB= 0b11100010;
	
	else if(position==6)PORTB= 0b11010010;	
	else if(position==7)PORTB= 0b10110010;
	
	else if(position==8)PORTB= 0b01110010;
	else if(position==9)PORTB= 0b11100100;
	else if(position==10)PORTB= 0b11010100;
	
	else if(position==11)PORTB= 0b10110100;
	else if(position==12)PORTB= 0b01110100;
	else if(position==13)PORTB= 0b11101000;
	else if(position==14)PORTB= 0b11011000;
	else if(position==15)PORTB= 0b10111000;
	else if(position==16)PORTB= 0b01111000;
	else PORTB=0b11110000;
}

	
int main(void)
{
	DDRB = 0b11111111;
	b(0);
	DDRD &= ~(0b00001111);
	PORTD=0b00001111;
	
	
	int a=3,position=5,i,n=2;
	b(position);
	while(1){
		if(bit_is_clear(PIND,0)){
			if (a!=2) a=0;
		}else if(bit_is_clear(PIND,1)){
			if (a!=1)a=1;
		}else if(bit_is_clear(PIND,2)){
			if (a!=3)a=2;
		}else if(bit_is_clear(PIND,3)){
			if (a!=2)a=3;
		}
		
		if (a==0)
		{	if (position==1||position==2||position==3||position==4)
			{
				position+=12;
			
			}else{
			position-=4;
			}
			
		}else if(a==1)
		{
			if (position==13||position==14||position==15||position==16)
			{
				position-=12;
			
			}else{
				position+=4;
			}
		}else if(a==2)
		{
			if (position==1||position==5||position==9||position==13)
			{
				position+=3;
			
			}else{
				position-=1;
			}
		}else if(a==3)
		{
			if (position%4==0)
			{
				position-=3;
			
			}else{
				position+=1;
			}
		}
		b(0);
		b(position);
		
		_delay_ms(16);
	}


}