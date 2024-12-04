
/*
 * SSD.c
 *
 * Created: 11/15/2024 6:27:37 PM
 *  Author: master
 */ 

#define F_CPU 16000000UL

#include <DIO.h>
#include <SSD_CFG.h>
#include <Bit_Math.h>
#include <util/delay.h>
#include <DIO_HW.h>


void SSD_init(void)
{
	Set_Channel_Direction(EN1 , OUTPUT);
	Set_Channel_Direction(EN2 , OUTPUT);
	Write_Channel(EN1,HIGH);
	Write_Channel(EN2,LOW);
	DDRA_REG |= 0xF0;  // for better practice you may define Get_Port_Direction Function and do extra operations
	Write_Nibble(SSD_PORT,HIGH,0x0);// for better practice you may use Set_Port_Direction Function and do extra operations
	
}
void SSD_Write_One_Digit(SSD_Num SSD_Number , uint8 value)
{

	// Modify the below statements to use Write_Nibble Funcion;
	if(  value >= 0 && value < 10  )
	{
		uint8 PortData = Read_Port(PA) & 0x0F; 
		value = value << 4 ;
		PortData = PortData | value ;
		Write_Port(PA,PortData);
	}
	else	PORTA_REG &= 0x0F;
	
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