/*
 * LM35.c
 *
 * Created: 3/13/2025 2:22:27 AM
 *  Author: Youssef
 */ 

#include <Sensors.h>
#include <util/delay.h>

uint16 Sensor_Read(ADC_Channels Channel)
{
	ADC_Start_Conversion(Channel);
	uint16 result ;
	result = ADCLH_REG ;
	result = result  * ADC_VOLT_RESOLUTION_FACTOR * LM35_SENSITIVITY_FACTOR;
	return result;
	
}
