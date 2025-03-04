
/*
 * SSD.c
 *
 * Created: 11/15/2024 6:27:37 PM
 *  Author: master
 */ 

#define F_CPU 16000000UL

#include <SSD.h>


void SSD_init(void)
{
	Set_Channel_Direction(EN1 , OUTPUT);
	Set_Channel_Direction(EN2 , OUTPUT);
	Write_Channel(EN1,LOW);
	Write_Channel(EN2,LOW);
	Set_Nibble_Direction(SSD_PORT,SSD_SIG,0xF);  
	Write_Nibble(SSD_PORT,SSD_SIG,0x0);
	
}
void SSD_Write_One_Digit(SSD_Num SSD_Number , uint8 value)
{

	if(  value >= 0 && value < 10  )
	{
		Write_Nibble(SSD_PORT,SSD_SIG,value);
	}
	else	Write_Nibble(SSD_PORT,SSD_SIG,0x0);
	
	switch(SSD_Number)
	{
		case SSD_1:
		Write_Channel(EN1,HIGH);
		Write_Channel(EN2,LOW);
		break;
		case SSD_2:
		Write_Channel(EN1,LOW);
		Write_Channel(EN2,HIGH);
		break;
	}
	
	_delay_ms(10);
	
}

void SSD_Write_Two_Digits(uint8 value)
{
	uint8 First_Digit = value % 10 ;
	uint8 Second_Digit = value / 10 ;
	
	SSD_Write_One_Digit(SSD_1,First_Digit);
	SSD_Write_One_Digit(SSD_2,Second_Digit);
	
}