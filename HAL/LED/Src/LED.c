/*
 * LED.c
 *
 * Created: 11/11/2024 11:10:34 PM
 *  Author:Youssef
 */ 

#include <LED.h>

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
	Set_Channel_Direction(BUZZER,OUTPUT);
	Write_Channel(BUZZER,LOW);
}

void Write_LED (DIO_Channel LED , STD_Level Level)
{
	Write_Channel(LED,Level);
}

void Write_Buzzer(DIO_Channel Buzzer ,STD_Level Level)
{
	Write_Channel(Buzzer,Level);
}


STD_Level Read_PushB (DIO_Channel PushB)
{
	//Debouncing Logic
	if(Read_Channel(PushB)== HIGH)
	{
		_delay_ms(25);
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

