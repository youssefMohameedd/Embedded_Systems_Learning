/*
 * Test.c
 *
 * Created: 12/20/2024 5:40:32 PM
 *  Author: Youssef

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
			Set_Channel_Direction(cols[i],PULL_UP);
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



uint8 Keypad_Read_Char(void)
{
	#if(KEYPAD_INIT_MODE == PULL_UP)
	{
		for (uint8 i = 0 ; i<NUM_OF_ROWS ; i++)
		{
			Write_Channel(rows[i],LOW);
	
			for(uint8 j =0 ; j<NUM_OF_COLS ; j++)
			{
				if(Read_Channel(cols[j])==LOW) // equivalent to !Read_Channel(cols[j])
				{
					_delay_ms(15);  // Debouncing logic
   					if (Read_Channel(cols[j]) == LOW)
					{
					while(Read_Channel(cols[j])== LOW); // halt CPU Operation untill button is released
					return KeyPad[i][j];
					}
				}
			}
		
			Write_Channel(rows[i],HIGH);
		}
	}
	#elif(KEYPAD_INIT_MODE == INPUT)
	{
		for (uint8 i = 0 ; i<NUM_OF_ROWS ; i++)
		{
			Write_Channel(rows[i],HIGH);
	
			for(uint8 j = 0 ; j <NUM_OF_COLS ; j++)
			{
				if(Read_Channel(cols[j]))
				{
					_delay_ms(15); // for debouncing
					
					if(Read_Channel(cols[j]))
					{
						while(Read_Channel(cols[j])); // halt CPU Operation
						return KeyPad[i][j];
					}
				}
				
			}
			
			Write_Channel(rows[i],LOW);
		}
	}
	#endif
	
	return 'N';
	
}
