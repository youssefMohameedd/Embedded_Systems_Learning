/*
 * Keypad.c
 *
 * Created: 12/6/2024 4:07:10 PM
 *  Author: Youssef
 */ 

#include <DIO.h>
#include <Keypad.h>
#include <util/delay.h>

uint8 rows[4] = {r1,r2,r3,r4};
uint8 cols[4] = {c1,c2,c3,c4};
	
uint8 KeyPad[4][4]= {{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}};


void Keypad_Init(void)
{
	//Keypad Pinout (From Left to Right) r1-r2-r3-r4-c1-c2-c3-c4
	Set_Port_Direction(PD,0xF0);
	Write_Port(PD,0xFF);
	_delay_ms(2);
}

// we needn't use the debounced Push-Button function, as halting CPU performance wouldn't
//affect the Data Display of the LCD
uint8 Keypad_Read_Char(void)
{
	
	for (uint8 i = 0 ; i<4 ; i++)
	{
		Write_Channel(rows[i],LOW);
		
		for(uint8 j = 0 ; j<4 ;j++)
		{
			if(Read_Channel(cols[j])==0)
			{
				while(Read_Channel(cols[j])==0);
				return KeyPad[i][j];
			}
			
		}
		
		Write_Channel(rows[i],HIGH);
		
	}
	return 'N';
	
}