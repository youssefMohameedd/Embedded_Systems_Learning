/*
 * LM35.c
 *
 * Created: 3/13/2025 2:22:27 AM
 *  Author: Youssef
 */ 

#include <Sensors.h>
#include <util/delay.h>


typedef struct {
	ADC_Channels Channel;
	float Resistance_Sensitivity;
	float Resistance_Bias;
	float Temperature_Sensitivity;
	float Temperature_Bias;
	
}Sensor_Config;

const Sensor_Config Sensors[] =
{
	{ADC_Channel0 ,1,0,100.0,0},	//LM35
	{ADC_Channel0 ,5.3,-2.8,-5.4,72.5 },//NTC : this parameters works with NTC 10k Ohm(25 C) and 3950B
	//Strain-gage // load-Cell 
};


float Sensor_Read(ADC_Channels Index) 
{
	ADC_Start_Conversion(Sensors[Index].Channel);
	
	float VADC = ADCLH_REG  * ADC_VOLT_RESOLUTION_FACTOR  ;// get Sensor O/P Voltage
	float Resistance = (VADC * Sensors[Index].Resistance_Sensitivity) + Sensors[Index].Resistance_Bias; //get resistance if required
	float Result = (Resistance * Sensors[Index].Temperature_Sensitivity) + Sensors[Index].Temperature_Bias; // get Physical Reading

	return  Result ;
	
}
