/*
 * Stepper.c
 *
 * Created: 12/16/2024 2:24:21 PM
 *  Author: maste
 */ 




#include <Stepper.h>


#define SPEED 20
#define SPEED_DELAY 100.0/SPEED


#define STEPPER_PORT PD
#define STEPPER_SIG HIGH

#define IN1 PD4
#define IN2 PD5
#define IN3 PD6
#define IN4 PD7

uint8 coils[4] = {IN1,IN2,IN3,IN4};

void Stepper_Init(void)
{
	// Set_Channel_Direction(IN1,OUTPUT);
	// Set_Channel_Direction(IN2,OUTPUT);
	// Set_Channel_Direction(IN3,OUTPUT);
	// Set_Channel_Direction(IN4,OUTPUT);
	Set_Nibble_Direction(STEPPER_PORT,STEPPER_SIG,OUTPUT);	
	for(uint8 i = 0 ; i < 4 ; i++)	Write_Channel(coils[i],HIGH);
			
}

void Stepper_Rotate(sint16 angle)
{

	sint16 steps = angle/11.25;
	steps = steps /4.0;

		if (angle > 0)
		{
			for(uint8 j = 0 ; j < steps ; j++)
			{
				for (sint8 i = 0; i <4 ; i++)
				{
					Write_Channel(coils[i],LOW);
					_delay_ms(SPEED_DELAY);
					Write_Channel(coils[i],HIGH);
					_delay_ms(SPEED_DELAY);
				}
			}
		}
	else if ( angle < 0  )
	{
		
		for(sint8 j = steps ; j < 0 ; j++)
			{
				// notice the use of signed integer !!!! very important 
				//when comparing descendingly
				for ( sint8 i = 3; i >=0 ; i--)
				{
					Write_Channel(coils[i],LOW);
					_delay_ms(SPEED_DELAY);
					Write_Channel(coils[i],HIGH);
					_delay_ms(SPEED_DELAY);
				}
			}
	}
	
	
	
}
