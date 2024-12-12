/*
 * Project_Test.c
 *
 * Created: 10/27/2024 10:29:19 PM
 * Author : Youssef Mohamed
*/

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <STD_Types.h>
#include <SSD.h>
#include <util/delay.h>
#include <LED.h>
#include <LCD.h>
#include <LCD_CFG.h>
#include <Bit_Math.h>
#include <Keypad.h>
#include <DIO.h>



int main(void)
{	

	LCD_Init();
	_delay_ms(10);
	Keypad_Init();
	_delay_ms(5);
	
	
	uint8 val = 'N';

	
	while(1)
	{
		val = Keypad_Read_Char();
		if(val!='N')
		{
			if(val=='*') LCD_Write_Cmd(DISPLAY_CLEAR);
			LCD_Write_Char(val);
			_delay_ms(100);
		}
	
		_delay_ms(5);
	
	}
	
	return 0;   
}


/*		PORTC = 0b11111111 ;
if(PINC == 0b01110111) LCD_Write_Char('1');
//if(PINC == 0b01111011) LCD_Write_Char('5');
if(PINC == 0b01111101) LCD_Write_Char('3');
if(PINC == 0b01111110) LCD_Write_Char('A');
_delay_ms(100);

val = Keypad_Read_Char();
if(val != 'N') LCD_Write_Char(val);
_delay_ms(5);
*/

	
