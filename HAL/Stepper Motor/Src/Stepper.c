/*
 * Stepper.c
 *
 * Created: 12/16/2024 2:24:21 PM
 *  Author: maste
 */ 


#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <STD_Types.h>
#include <DIO.h>
#include <util/delay.h>



//in future versions we may modify the speed value and angle and polarity and angle to be passed in the app. layer
//Motor type may be defined as a global macro

#define STEPPER_PORT PD
#define STEPPER_SIG HIGH

#define IN1 PD4
#define IN2 PD5
#define IN3 PD6
#define IN4 PD7

#define POLARITY 0  // 0 or 1
#define SPEED 50	// ( 1  - 100)


#define SPEED_DELAY 100.0/SPEED

uint8 coils[4] = {IN1,IN2,IN3,IN4};

void Stepper_Init(void)
{	// Set_Channel_Direction(IN1,OUTPUT);
	// Set_Channel_Direction(IN2,OUTPUT);
	// Set_Channel_Direction(IN3,OUTPUT);
	// Set_Channel_Direction(IN4,OUTPUT);
	Set_Nibble_Direction(STEPPER_PORT,STEPPER_SIG,OUTPUT);	
	for(uint8 i = 0 ; i < 4 ; i++)	Write_Channel(coils[i],HIGH);
			
}

void Stepper_Full_wave(void)
{
	#if (0 == POLARITY )
		for (sint8 i = 0; i <4 ; i++)
		{
			Write_Channel(coils[i],LOW);
			_delay_ms(SPEED_DELAY);
			Write_Channel(coils[i],HIGH);
			_delay_ms(SPEED_DELAY);
		}
	#elif ( 1 == POLARITY )
		// notice the use of signed integer !!!! very important when
		// comparing descendingly
		for ( sint8 i = 3; i >=0 ; i--)
		{
			Write_Channel(coils[i],LOW);
			_delay_ms(SPEED_DELAY);
			Write_Channel(coils[i],HIGH);
			_delay_ms(SPEED_DELAY);
		}
	#endif

}

void Stepper_Hold(void)
{
	for(uint8 i = 0 ; i < 4 ; i++)
	{
		Write_Channel(coils[i],HIGH);
	}
}