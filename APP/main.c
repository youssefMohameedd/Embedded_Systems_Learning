/*
 * Project_Test.c
 *
 * Created: 10/27/2024 10:29:19 PM
 * Author : Youssef Mohamed
 */ 
/**
 * @brief Main entry point of the application.
 * This function initializes the Segment Display (SSD), Buzzer, and three push buttons (PushB0, PushB1, PushB2).
 * It then enters a main loop that handles the following functionality:
 * - Keeps the value within the range of 0 to 99
 * - Increments the value when PushB0 is pressed
 * - Decrements the value when PushB1 is pressed
 * - Sets a flag when PushB2 is pressed, which triggers a countdown from the current value to 0
 * - Displays the current value on the SSD
 * The function returns 0 to indicate successful execution.
 */

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <STD_Types.h>
#include <DIO.h>
#include <LED.h>
#include <SSD.h>
#include <util/delay.h>


int main(void)
{	
	SSD_init();
	Buzzer_Init();
	PushB_Init(PushB0);
	PushB_Init(PushB1);
	PushB_Init(PushB2);
	
	uint8 PushB0_Status = 0 ;
	uint8 PushB1_Status = 0 ;
	uint8 PushB2_Status = 0 ;
	uint8 Flag = 0 ;
	sint8 value = 26 ;
	
	while(1)
	{
		if(value > 99 ) value = 0;
		if(value < 0  ) value = 99;
		
		if(PushB0_Status == 0 && Debounced_Read_PushB(PushB0))
		{
			PushB0_Status = 1;
			value++ ;
		}
		else if(!Debounced_Read_PushB(PushB0) == 1) PushB0_Status = 0;
		if(PushB1_Status == 0 && Debounced_Read_PushB(PushB1))
		{
			PushB1_Status = 1;
			value-- ;
		}
		else if(!Debounced_Read_PushB(PushB1) == 1) PushB1_Status = 0;
	
		
		if(PushB2_Status == 0 && Debounced_Read_PushB(PushB2))
		{
			PushB2_Status = 1;
			Flag = 1;

			
		}
		
		else if(!Debounced_Read_PushB(PushB2) == 1)	 
			PushB2_Status = 0;
			
	
		if(Flag)
		{
			for(value ; value >=0 ; value--)
			{
				for(uint8 counter = 0 ; counter <50 ; counter ++)
				{
					SSD_Write_Two_Digits(value);
					if(!Debounced_Read_PushB(PushB2)) PushB2_Status = 0 ;
	
					if(PushB2_Status == 0 && Debounced_Read_PushB(PushB2))
					{
						Flag = 0 ;
						while(Debounced_Read_PushB(PushB2));
						break;
					
					}
					
				}
				if(!Flag) break;
			}
			
		}
		
		SSD_Write_Two_Digits(value);
	}
	
	return 0;   
}
