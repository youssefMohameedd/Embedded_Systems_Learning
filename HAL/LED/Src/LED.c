/*
 * LED.c
 *
 * Created: 11/11/2024 11:10:34 PM
 *  Author: master
 */ 

#include <STD_Types.h>
#include <DIO.h>
#include <LED_CFG.h>
#include <util/delay.h>


void LED_Init(DIO_Channel LED)
{
	Set_Channel_Direction(LED,OUTPUT);
	Write_Channel(LED,LOW);
}
void PushB_Init(DIO_Channel PushB)
{
	Set_Channel_Direction(PushB,INPUT);	
}
void Buzzer_Init()
{
	Set_Channel_Direction(Buzzer,OUTPUT);
	Write_Channel(Buzzer,LOW);
}

void Write_LED (DIO_Channel LED , STD_Level Level)
{
	Write_Channel(LED,Level);
}

void Write_Buzzer(DIO_Channel Buzzer ,STD_Level Level)
{
	Write_Channel(Buzzer,Level);
}


STD_Level Debounced_Read_PushB (DIO_Channel PushB)
{
	
	if(Read_Channel(PushB)== HIGH)
	{
		_delay_ms(50);
		if(Read_Channel(PushB) == HIGH)
		{
			return HIGH;
		}
	}
	return LOW;

}

void Toggle_LED(DIO_Channel LED)
{
	Toggle_Channel(LED);
}

