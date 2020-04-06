#include<avr/io.h>
/*Includes io.h header file where all the Input/Output Registers and its Bits are defined for all AVR microcontrollers*/

#define           F_CPU           2000000
/*Defines a macro for the delay.h header file. F_CPU is the microcontroller frequency value for the delay.h header file. Default value of F_CPU in delay.h header file is 1000000(1MHz)*/

#include<util/delay.h>
/*Includes delay.h header file which defines two functions, _delay_ms (millisecond delay) and _delay_us (microsecond delay)*/

#define           LCD_DATA_PORT           PORTB
/*Defines a macro for the lcd.h header File. LCD_DATA_PORT is the microcontroller PORT Register to which the data pins of the LCD are connected. Default PORT Register for data pins in lcd.h header file is PORTA*/

#define           LCD_CONT_PORT           PORTD
/*Defines a macro for the lcd.h header File. LCD_CONT_PORT is the microcontroller PORT Register to which the control pins of the LCD are connected. Default PORT Register for control pins in lcd.h header file is PORTB*/

#define           LCD_RS           PD0
/*Defines a macro for the lcd.h header file. LCD_RS is the microcontroller Port pin to which the RS pin of the LCD is connected. Default Port pin for RS pin in lcd.h header file is PB0*/

#define           LCD_RW           PD1
/*Defines a macro for the lcd.h header file. LCD_RW is the microcontroller Port pin to which the RW pin of the LCD is connected. Default Port pin for RW pin in lcd.h header file is PB1*/

#define           LCD_E           PD2
/*Defines a macro for the lcd.h header file. LCD_EN is the microcontroller Port pin to which the EN pin of the LCD is connected. Default Port pin for EN pin in lcd.h header file is PB2*/

#include<avr/lcd.h>
/*Includes lcd.h header file which defines different functions for all Alphanumeric LCD(8-Bit Interfacing Method). LCD header file version is 1.1*/

#include<avr/ds1307.h>
/*Includes ds1307.h header file which defines different functions for DS1307 Real Time Clock. DS1307 header file version is 1.1*/

int main(void)
{


DDRB=0xff;
/*All the 8 pins of PortB are declared output (data pins of LCD are connected)*/

DDRD=0x07;
/*PD0, PD1 and PD2 pins of PortD are declared output (control pins of LCD are connected)*/

unsigned char sec=0,min=0;
/*Variable declaration*/

twi_init();
/*TWI initialisaiton*/

lcd_init();
/*LCD initialisaiton*/

lcd_string_write(“ABLab Solutions”);
/*String display in 1st row of LCD*/

lcd_command_write(0xc0);
/*Cursor moves to 2nd row 1st column of LCD*/

lcd_string_write(“www.ablab.in”);
/*String display in 2nd row of LCD*/

_delay_ms(500);
_delay_ms(500);
_delay_ms(500);
_delay_ms(500);
/*Display stays for 2 second*/

lcd_command_write(0x01);
/*Clear screen*/

lcd_string_write(“Minute & Second:”);
/*String display in 1st row of LCD*/

/*DS1307 write section starts here*/

ds1307_second_write(0);
/*Writting second value in DS1307*/

ds1307_minute_write(0);
/*Writting minute value in DS1307*/

/*DS1307 write section ends here*/

/*Start of infinite loop*/
while(1)
{


sec=ds1307_read_second();
/*Reading second value from DS1307*/

min=ds1307_read_minute();
/*Reading minute value from DS1307*/

lcd_command_write(0xc0);
/*Cursor moves to 2nd row 1st column of LCD*/

min=convert_bcd_to_decimal(min);
/*Converting BCD number to Decimal value*/

lcd_number_write(min,10);
/*Minute value display in 2nd row of LCD*/

lcd_string_write(“min “);
/*String display in 2nd row of LCD*/

sec=convert_bcd_to_decimal(sec);
/*Converting BCD number to Decimal value*/

lcd_number_write(sec,10);
/*Second value display in 2nd row of LCD*/

lcd_string_write(“sec “);
/*String display in 2nd row of LCD*/


}


}
/*End of Program*/