/*
 * ADC.c
 *
 * Created: 12/17/2024 5:29:09 PM
 *  Author: Youssef
 */ 

#include <ADC.h>
#include <util/delay.h>

PTR_FN ADC_PTR = NULL;

void ADC_Init (ADC_Channels Channel)
{
	
	//Enable ADC
	SET_BIT(ADCSRA_REG,ADEN_BIT);

	//Reference Voltage Config - AREF
	ADMUX_REG &= ADC_VOLTAGE_REF_CLEAR_MASK;
	ADMUX_REG |= ADC_VOLTAGE_REF;

	//Prescalar Division Factor
	ADCSRA_REG &= PRESCALER_CLR_MASK;
	ADCSRA_REG |= PRESCALAR_FACTOR;

	//Mode Selection. Note : We used #if macro because the bit manipulation meant for 1 bit only, otherwise we
	//use nomral bit masking.
	//ADC Interrupt Selection. Note: Interrupt Flag gets cleared by writing digital logic 1 and vice versa

	#if   (ADC_MODE == ADC_MODE_SINGLE_CONVERSION)
	CLR_BIT(ADCSRA_REG,ADIE_BIT);
	CLR_BIT(ADCSRA_REG,ADATE_BIT);
	#elif (ADC_MODE == ADC_MODE_AUTO_TRIGGERED)
	
	GI_Enable();
	SET_BIT(ADCSRA_REG,ADIE_BIT);
	SET_BIT(ADCSRA_REG,ADATE_BIT);
	SFIOR_REG &= ADC_TRIGGERING_SOURCE_CLEAR_MASK;
	SFIOR_REG |= ADC_TRIGGERING_MODE;
	
	ADC_Start_Conversion(Channel); // Start Conversion (You may change this later due to use of multiple sensors)

	
	
	#endif


	
	
	
}

void ADC_Start_Conversion (ADC_Channels Channel)
{

	//ADC Channel Selection
	ADMUX_REG &= ADC_CHANNEL_CLEAR_MASK;
	ADMUX_REG |= Channel;
 
	//ADC Start Conversion
	SET_BIT(ADCSRA_REG,ADSC_BIT);
	if(ADC_MODE == ADC_MODE_SINGLE_CONVERSION)	while(GET_BIT(ADCSRA_REG,ADSC_BIT) == 1 ) ;// could be #if
	
}
/**
 * @brief Retrieves the ADC conversion result and converts it to a voltage value.
 *
 * This function reads the ADC conversion result from the ADCLH register,
 * converts it to a voltage value using the predefined resolution factor,
 * and returns the result as a 16-bit unsigned integer.
 *
 * @return uint16 The ADC conversion result in voltage representation
 */
float ADC_GetResult(void)
{
	float Result = ADCLH_REG * ADC_VOLT_RESOLUTION_FACTOR;
	return  Result;

}

void ADC_Interrupt_Enable(void)
{
	//Enable ADC Interrupt
	SET_BIT(ADCSRA_REG,ADIE_BIT);
	//Enable Global Interrupt
	GI_Enable();
}
void ADC_Interrupt_Disable(void)
{
	//Disable ADC Interrupt
	CLR_BIT(ADCSRA_REG,ADIE_BIT);
}
void ADC_Set_Callback(PTR_FN CB_Address)
{
	ADC_PTR = CB_Address;
}

void __vector_16(void) __attribute__((signal,used));
void __vector_16(void)
{

	if(ADC_PTR != NULL)	ADC_PTR() ;
}