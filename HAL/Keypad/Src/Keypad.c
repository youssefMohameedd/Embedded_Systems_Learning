/*
 * Keypad.c
 *
 * Created: 12/6/2024 4:07:10 PM
 *  Author: Youssef
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <DIO.h>
#include <util/delay.h>
// Important Note: 
// When you connect keypad to the board, make sure it doesn't interfere with any
//LED or PushButton pins as they disturb its operation.
//I have wasted 50 EGP for thinking that the keypad isn't functioning 
//and I hope you don't :)

#define r1 PB7
#define r2 PB6
#define r3 PB5
#define r4 PB4

#define c1 PC6
#define c2 PC5
#define c3 PC4
#define c4 PC3



uint8 rows[4] = {r1,r2,r3,r4};
uint8 cols[4] = {c1,c2,c3,c4};

uint8 KeyPad[4][4]={{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}};



void Keypad_Init(void)
{	
	Set_Channel_Direction(r1,OUTPUT);
	Set_Channel_Direction(r2,OUTPUT);
	Set_Channel_Direction(r3,OUTPUT);
	Set_Channel_Direction(r4,OUTPUT);
	
	Set_Port_Direction(PC,0x00);
	for(uint8 i = 0 ; i<4 ; i++)
	{
		Write_Channel(rows[i],HIGH);
		Write_Channel(cols[i],HIGH);
	}
	_delay_ms(5);
}

// we needn't use the debounced Push-Button function, as halting CPU performance wouldn't
//affect the Data Display of the LCD
uint8 Keypad_Read_Char(void)
{
	
	for (uint8 i = 0 ; i<4 ; i++)
	{
		Write_Channel(rows[i],LOW);
		_delay_ms(2);
		
		for(uint8 j =0 ; j<4 ; j++)
		{
			if(Read_Channel(cols[j])==LOW)
			{
				_delay_ms(20);  // Wait for debounce
   				if (Read_Channel(cols[j]) == LOW)
				{
				while(Read_Channel(cols[j])== LOW);
				return KeyPad[i][j];
				}
			}
		}
		
		Write_Channel(rows[i],HIGH);
		_delay_ms(2);
		
	}
	return 'N';
	
}