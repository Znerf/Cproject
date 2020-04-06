#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <util/delay.h>

#define F_SCL 100000L

typedef int byte;

#define TW_START 0xA4            //send start condition (TWINT , TWSTA , TWEN)
#define TW_READY (TWCR & 0x80)   //ready when TWINT returns to logic 1  
#define TW_STATUS (TWSR & 0xF8)  //returns value of status register

#define DS1307    0xD0             // i2c bus address of ds1307 rtc
#define TW_SEND   0x84             // send data (TWINT, TWEN)  

#define TW_STOP  0x94              // send stop condition (TWINT ,TWSTO , TWEN)
#define I2C_Stop() TWCR = TW_STOP  // inline macro for stop condition 

#define TW_ACK   0xC4
#define TW_NACK  0x84              //read data with NACK(last byte)
#define READ  

   1
byte I2C_Start(void);
byte I2C_SendAddr(byte addr); //i have change the addr only to (byte addr)


byte I2C_Start(void)                 // generate start condition
{
   TWCR = TW_START;             //send start condition
   while(!TW_READY);            // wait
   return (TW_STATUS == 0x08);  // return 1 if found otherwise 0
}

byte I2C_SendAddr( byte addr)            // send bus address of slave
{
   TWDR = addr;                    //load device bus address
   TWCR = TW_SEND;                 //and send it 
   while (!TW_READY);              //wait   
   return (TW_STATUS == 0x18);     //return 1 if found otherwise 0
}


byte I2C_Write(byte data)            // send a data byte to slave
{
   TWDR = data;                    //load data to be send 
   TWCR = TW_SEND;                 //and send it 
   while (!TW_READY);              //wait   
   return (TW_STATUS == 0x28);     //return 1 if found otherwise 0
}

byte I2C_ReadACK(void)
{
   TWCR = TW_ACK;
   while(!TW_READY);
   return TWDR;
}

byte I2C_ReadNACK(void)                // reads a data byte from slave 
{
   TWCR = TW_NACK;                  // nack = not reading more data
   while (!TW_READY);                // wait
   return TWDR;
}

/*void I2C_WriteByte(byte busAddr, byte data)
{
   I2C_Start(busAddr);
   I2C_Write(data);
   I2C_Stop();
}*/

void I2C_WriteRegister (byte deviceRegister , byte data)
{
   I2C_Start();               
   I2C_SendAddr(DS1307);      //send bus address
   I2C_Write(deviceRegister); //first byte = device register aaddress
   I2C_Write(data);           //second byte = data for device register
   I2C_Stop();
}

byte I2C_ReadRegister(byte deviceRegister)
{
   byte data = 0;
   I2C_Start();
   I2C_SendAddr(DS1307);       //send device bus address
   I2C_Write(deviceRegister);  //set register pointer
   I2C_Start(); 
   I2C_SendAddr(DS1307+READ);  //restart as a read operation
   data = I2C_ReadNACK();      //read the register data
   I2C_Stop();                 //stop
   return data;
}

void I2C_Init(void)
{
   TWSR =0;
   TWBR = ((F_CPU/F_SCL)-16)/2;
   
}

byte I2C_Detect(byte addr)
{
   TWCR = TW_START;
   while(!TW_READY);
      TWDR = addr;
   TWCR = TW_SEND;
   while(!TW_READY);
   return (TW_STATUS == 0x18);
}

/*byte I2C_FindDevice(byte start)
{
   for(byte addr = start; addr < 0xFF;addr++)
   {
      if(I2C_Detect(addr))
      return addr;
   }
   return 0;
}
*/

#define SECONDS_REGISTER 0x00
#define MINUTES_REGISTER 0x01
#define HOURS_REGISTER   0x02 
#define DAYOFWK_REGISTER 0x03
#define DAYS_REGISTER    0x04
#define MONTHS_REGISTER  0x05
#define YEARS_REGISTER   0x06

void DS1307_GetTime(byte *hours, byte *minutes, byte *seconds)
{
   *hours   = I2C_ReadRegister(HOURS_REGISTER); //*hours   = I2C_ReadRegister(DS1307,HOURS_REGISTER);
   *minutes = I2C_ReadRegister(MINUTES_REGISTER);//*minutes = I2C_ReadRegister(DS1307,MINUTES_REGISTER);
   *seconds = I2C_ReadRegister(SECONDS_REGISTER);// *seconds = I2C_ReadRegister(DS1307,SECONDS_REGISTER);
   if(*hours & 0x04)           //12hrs mode
   {
      *hours &= 0x1F;
   }
    else
   {
    *hours &= 0x3F; 
   }
}

void DS1307_GetDate(byte *months, byte *days, byte *years)
{
   *months = I2C_ReadRegister(MONTHS_REGISTER); //   *months = I2C_ReadRegister(DS1307,MONTHS_REGISTER);
   *days   = I2C_ReadRegister(DAYS_REGISTER); //*days   = I2C_ReadRegister(DS1307,DAYS_REGISTER);
   *years  = I2C_ReadRegister(YEARS_REGISTER);  //*years  = I2C_ReadRegister(DS1307,YEARS_REGISTER);
}

void SetTimeDate(void)
{
   I2C_WriteRegister(MONTHS_REGISTER,0x08); //I2C_WriteRegister(DS1307,MONTHS_REGISTER,0x08);
   I2C_WriteRegister(DAYS_REGISTER,0x31); //I2C_WriteRegister(DS1307,DAYS_REGISTER,0x31);
   I2C_WriteRegister(YEARS_REGISTER,0x13);  //I2C_WriteRegister(DS1307,YEARS_REGISTER,0x13);
   I2C_WriteRegister(HOURS_REGISTER,0x08+0x04); //I2C_WriteRegister(DS1307,HOURS_REGISTER,0x08+0x04);
   I2C_WriteRegister(MINUTES_REGISTER,0x51); //I2C_WriteRegister(DS1307,MINUTES_REGISTER,0x51);
   I2C_WriteRegister(SECONDS_REGISTER,0x00); //I2C_WriteRegister(DS1307,SECONDS_REGISTER,0x00);
}

void SetTime(void)
{  
	DS1307_GetTime(&hours,&minutes,&seconds);
	byte a = hours ;
	
	//byte a = 0x01 ;
	uint8_t i=1;
	byte b = minutes;
	
	//byte b = 0x00;
	uint8_t j=0;

		if(bit_is_clear(PINC,5))
		{
			a += 0x01;
			i += 1;
			_delay_ms(50);
			if((i%10)==0)
			{
					a += 0x06;
			}
			if(i==25)
			{
					a = 0x01;
					i = 0;
			}
			PORTA = a;
   			PORTB = b;
   			I2C_WriteRegister(HOURS_REGISTER,a); //I2C_WriteRegister(DS1307,HOURS_REGISTER,0x08+0x04);
   			I2C_WriteRegister(MINUTES_REGISTER,b); //I2C_WriteRegister(DS1307,MINUTES_REGISTER,0x51);
   			I2C_WriteRegister(SECONDS_REGISTER,0x00); //I2C_WriteRegister(DS1307,SECONDS_REGISTER,0x00);
   
		}

		if(bit_is_clear(PINC,6))
		{
				b += 0x01;
				j += 1;
			_delay_ms(50);
			if((j%10)==0)
			{
					b += 0x06;
			}	
			 if( j>60)
				{
				  b = 0x01;
				}
			PORTA = a;
   			PORTB = b;
   			I2C_WriteRegister(HOURS_REGISTER,a); //I2C_WriteRegister(DS1307,HOURS_REGISTER,0x08+0x04);
   			I2C_WriteRegister(MINUTES_REGISTER,b); //I2C_WriteRegister(DS1307,MINUTES_REGISTER,0x51);
   			I2C_WriteRegister(SECONDS_REGISTER,0x00); //I2C_WriteRegister(DS1307,SECONDS_REGISTER,0x00);
   
		}

   
}


void WriteTime(void)
{
   byte hours, minutes ,seconds;
   DS1307_GetTime(&hours,&minutes,&seconds);
   PORTD = seconds;
   PORTB = minutes;
   PORTA = hours;
}

int main(void)
 { 
	DDRD = 0xFF;
	DDRB = 0xFF;
	DDRA = 0xFF;

	DDRC &= 0x87;
 
   PORTC |= 0x78;
   I2C_Init();
   _delay_ms(400);



   while (1)
   {
     //if(bit_is_clear(PINC,3))
	 //{
	 SetTime();
	 //}
    WriteTime();
   _delay_ms(.1);
   }



 }