/*
 * Project_Test.c
 *
 * Created: 10/27/2024 10:29:19 PM
 * Author : Youssef Mohamed
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>
#include <Bit_Math.h>
#include <util/delay.h>
#include <STD_Types.h>
//#include <DIO.h>
//#include <LED.h>
#include <SSD_CFG.h>

void SSD_INIT(SSD_Num x)
{

	PORTB = 0b00000010 << x;

	
}
	
void SSD_WTD(uint8  value)
{
	uint8 First_Digit = value%10;
	uint8 Second_Digit = value/10;
	
	//Write Digit 2 
	First_Digit <<= 4;
	PORTA = (PORTA & 0x0F ) | First_Digit;
	SSD_INIT(SSD_1);
	_delay_ms(10);
	
	//Enable EN2
	Second_Digit <<= 4;
	PORTA = (PORTA & 0x0F ) | Second_Digit;
	SSD_INIT(SSD_2);
	_delay_ms(10);
	
	
}

int main(void)
{	
	DDRB = 0x0F;  // Set PORTB as output for SSD control
	DDRA = 0xFF;  // Set upper nibble of PORTA as output for segments
	PORTB = 0x00;
	PORTA = 0x00; 
	SSD_INIT(SSD_1);

	while(1)
	{	
		for (uint8 i = 99; i > 0 ; i--)
		{
			for(uint8 counter = 0 ; counter < 50 ; counter++)
			{
				SSD_WTD(i);
				
			}
		}
	}
	
	return 0;   
}
/*	uint8 SSD_Val = 12;
uint8 PushB0_Status = 0;
uint8 PushB1_Status = 0;

PushB_Init(PushB0);
PushB_Init(PushB1);

SSD_init();


while(1)
{
if(Read_PushB(PushB0) && PushB0_Status==0) SSD_Val++;
if(Read_PushB(PushB1) && PushB1_Status==0) SSD_Val--;
Write_Two_Digits(SSD_Val);
_delay_ms(50);


}
*/