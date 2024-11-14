/*
 * Project_Test.c
 *
 * Created: 10/27/2024 10:29:19 PM
 * Author : Youssef Mohamed
 */ 


#define F_CPU 16000000UL

#include <Bit_Math.h>
#include <util/delay.h>
#include <STD_Types.h>
#include <DIO.h>
#include <LED.h>




int main(void)
{
	
	while(1)
	{

	}

	return 0;   
}



/*

#define MY_LED LED0

// LED  Toggle Code 
	LED_Init(MY_LED);
	PushB_Init(PushB0);
	
	uint8 LED_Status = 0;
	uint8 PushB_Status = 0;


	while(1){
		PushB_Status = Read_PushB(PushB0);
		if(PushB_Status == 1 && LED_Status == 0)
		{
			Write_LED(MY_LED,HIGH);
			LED_Status = 1;
		}
		else if (PushB_Status ==  1 && LED_Status == 1 )
		{
			Write_LED(MY_LED,LOW);
			LED_Status = 0;
		}
	}
	
*/