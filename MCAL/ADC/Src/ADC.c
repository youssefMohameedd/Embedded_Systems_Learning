/*
 * ADC.c
 *
 * Created: 12/17/2024 5:29:09 PM
 *  Author: Youssef
 */ 

#include <ADC.h>


void ADC_Init (void)
{
	SET_BIT(ADCSRA_REG,ADEN_BIT);

	//Reference Voltage Config - AREF
	ADMUX_REG &= ADC_VOLTAGE_REF_CLEAR_MASK;
	ADMUX_REG |= ADC_VOLTAGE_REF;

	//Prescalar Division Factor
	ADCSRA_REG &= PRESCALER_CLR_MASK;
	ADCSRA_REG |= PRESCALAR_FACTOR;

	//Mode Selection 
	#if   (ADC_MODE == ADC_MODE_SINGLE_CONVERSION)
	CLR_BIT(ADCSRA_REG,ADATE_BIT);
	#elif (ADC_MODE == ADC_MODE_AUTO_TRIGGERED)
	SET_BIT(ADCSRA_REG,ADATE_BIT);
	SFIOR_REG &= ADC_TRIGGERING_SOURCE_CLEAR_MASK;
	SFIOR_REG |= ADC_TRIGGERING_MODE;
	#endif

	//ADC Interrupt Selection 
	#if   (ADC_Interrupt == false)
	CLR_BIT(ADCSRA_REG,ADIE_BIT);
	CLR_BIT(ADCSRA_REG,ADIF_BIT);
	#elif (ADC_Interrupt == true)
	SET_BIT(ADCSRA_REG,ADIE_BIT);
	SET_BIT(ADCSRA_REG,ADIF_BIT);
	#endif
	
	
	
}

void ADC_Start_Conversion (ADC_Channels Channel)
{


	//ADC Channel Selection
	ADMUX_REG &= ADC_CHANNEL_CLEAR_MASK;
	ADMUX_REG |= Channel;

	//ADC Start Conversion
	SET_BIT(ADCSRA_REG,ADSC_BIT);
	while(GET_BIT(ADCSRA_REG,ADSC_BIT) == 1 ) ;
	
}
