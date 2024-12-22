/*
 * Test.c
 *
 * Created: 12/20/2024 5:40:32 PM
 *  Author: maste

*/
#include <Keypad.h>
#include <Keypad_CFG.h>


void Keypad_Init(void)
{
	for(uint8 i = 0 ; i<4 ; i++) Set_Channel_Direction(rows[i],OUTPUT);	
	
	#if(KEYPAD_INIT_MODE == PULL_UP)
	{
		for(uint8 i = 0 ; i<4 ; i++)
		{
			//theoretically you can initialize columns using 1 command only,as : PULL_UP 
			//but for some reason it didn't work for me :(
			Set_Channel_Direction(cols[i],INPUT);
			Write_Channel(cols[i],HIGH);
			Write_Channel(rows[i],HIGH);
			
		}
	}
	#elif (KEYPAD_INIT_MODE == INPUT)
	{
		for(uint8 i = 0 ; i<4 ; i++)
		{
			Set_Channel_Direction(cols[i],INPUT);
			Write_Channel(rows[i],LOW);
		}
	}
	
	#endif
	_delay_ms(5);
}


// we needn't use the debounced Push-Button function, as halting CPU performance wouldn't
//affect the Data Display of the LCD
uint8 Keypad_Read_Char(void)
{
	#if(KEYPAD_INIT_MODE == PULL_UP)
	{
		for (uint8 i = 0 ; i<NUM_OF_ROWS ; i++)
		{
			Write_Channel(rows[i],LOW);
			_delay_ms(2);
		
			for(uint8 j =0 ; j<NUM_OF_COLS ; j++)
			{
				if(Read_Channel(cols[j])==LOW)
				{
					_delay_ms(20);  // Debouncing logic
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
	}
	#elif(KEYPAD_INIT_MODE == INPUT)
	{
		for (uint8 i = 0 ; i<NUM_OF_ROWS ; i++)
		{
			Write_Channel(rows[i],HIGH);
			_delay_ms(2);
			
			for(uint8 j =0 ; j<NUM_OF_COLS ; j++)
			{
				if(Read_Channel(cols[j])==HIGH)
				{
					_delay_ms(20);  // Wait for debounce
					if (Read_Channel(cols[j]) == HIGH)
					{
						while(Read_Channel(cols[j])== HIGH);
						return KeyPad[i][j];
					}
				}
			}
			Write_Channel(rows[i],LOW);
			_delay_ms(2);
		}
	}
	#endif
	
	return 'N';
	
}
