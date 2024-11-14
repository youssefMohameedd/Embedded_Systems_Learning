/*
 * LED.c
 *
 * Created: 11/11/2024 11:10:34 PM
 *  Author: master
 */ 

#include <STD_Types.h>
#include <DIO.h>
#include <LED_CFG.h>


void LED_Init(DIO_Channel LED)
{
	Set_Channel_Direction(LED,OUTPUT);
}
void PushB_Init(DIO_Channel PushB)
{
	Set_Channel_Direction(PushB,INPUT);	
}
void Write_LED (DIO_Channel LED , STD_Level Level)
{
	Write_Channel(LED,Level);
}
STD_Level Read_PushB (DIO_Channel PushB)
{
	STD_Level Level = Read_Channel(PushB);
	return Level;
}

void Toggle_LED(DIO_Channel LED)
{
	
}