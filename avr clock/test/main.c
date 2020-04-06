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
	DDRB= 0b11111111;
	int i,j,k;
	while(1){
		for(i=0;i<=15;i++){
			for(k=1;k<=1000000000;k++){
			for(j=i;j<=i+1;i++){
			b(i);
			_delay_ms(50);
			}
			}
			
		}
	}
}