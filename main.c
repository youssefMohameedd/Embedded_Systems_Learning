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


	LED_Init(LED0);
	Set_Channel_Direction(PD5,LOW);
	Write_Channel(PD5,HIGH);
	STD_Level Status  = 0;

	while(1)
	{
		Status = Read_Channel(PD5);
		if(Status == 0) Write_LED(LED0 , HIGH);
		else Write_LED(LED0,LOW);
	}
	
	return 0;   
}