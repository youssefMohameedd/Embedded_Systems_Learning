/*
 * Test.c
 *
 * Created: 12/20/2024 5:40:32 PM
 *  Author: maste

*/
#include <Keypad.h>


#define INPUT 0
#define PULL_UP 1

/*Important Note: When you connect keypad to the board, make sure it 
doesn't interfere with anyLED or PushButton pins as they disturb its
operation.I have wasted 50 EGP for thinking that the keypad
isn't functioning , and I hope you don't :)*/

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

#define KEYPAD_INIT_MODE PULL_UP

void Keypad_Init(void)
{
	for(uint8 i = 0 ; i<4 ; i++) Set_Channel_Direction(rows[i],OUTPUT);	
	
	#if(KEYPAD_INIT_MODE == PULL_UP)
	{
		for(uint8 i = 0 ; i<4 ; i++)
		{
			// for some reason, the keypad is not working properly with the pull-up configuration in the Set_Channel_Direction function
			// so I had to use the pull-down configuration
			// I'm not sure if this is a problem with the keypad or the board
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
	}
	#elif(KEYPAD_INIT_MODE == INPUT)
	{
		for (uint8 i = 0 ; i<4 ; i++)
		{
			Write_Channel(rows[i],HIGH);
			_delay_ms(2);
			
			for(uint8 j =0 ; j<4 ; j++)
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
