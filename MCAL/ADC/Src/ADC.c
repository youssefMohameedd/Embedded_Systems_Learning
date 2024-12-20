/*
 * ADC.c
 *
 * Created: 12/17/2024 5:29:09 PM
 *  Author: Youssef
 */ 

#include <ADC.h>


void ADC_Init (void)
{
	//Reference Voltage Config - AVCC 
	ADMUX_REG &= ADC_VOLTAGE_REF_CLR_MASK;
	ADMUX_REG |= ADC_VOLTAGE_REF;

	//Prescalar Division Factor
	ADCSRA_REG &= PRESCALER_CLR_MASK;
	ADCSRA_REG |= PRESCALAR_FACTOR;

	//Mode Selection 
	#if ADC_MODE == ADC_MODE_SINGLE_CONVERSION
	CLR_BIT(ADCSRA_REG,ADATE_BIT);
	#elif ADC_MODE == ADC_MODE_AUTO_TRIGGERED
	SET_BIT(ADCSRA_REG,ADATE_BIT);
	SFIOR_REG &= ADC_TRIGGERING_SOURCE_CLEAR_MASK;
	SFIOR_REG |= ADC_TRIGGERING_MODE
	#endif

	/*Disable ADC Interrupt and Clear The Flag*/
	CLR_BIT(ADCSRA_REG,ADEN_BIT);
	CLR_BIT(ADCSRA_REG,3);
	SET_BIT(ADCSRA_REG,4);
	SET_BIT(ADCSRA_REG,ADEN_BIT); 
	
		
	
}

uint16 ADC_Read (ADC_Channels Channel)
{
	float val ;

	//ADC Channel Selection
	ADMUX_REG &= ADC_CHANNEL_CLEAR_MASK;
	ADMUX_REG |= Channel;

	//ADC Start Conversion
	SET_BIT(ADCSRA_REG,ADSC_BIT);
	while(GET_BIT(ADCSRA_REG,ADSC_BIT) == 1 ) ;
	val = ADCLH_REG; // values are right adjusted by default

	//Result Transformation into appropriate values
	val = (val/1024.0)*5.0; // voltage value
	val =  val * 100.0 ;// Degree Celsius (Change it depending on the sensitivity of the existing sensor,i.e: 10mV/C)
	
	return val;
	
}
