/*
 * ADC.c
 *
 * Created: 12/17/2024 5:29:09 PM
 *  Author: Youssef
 */ 

#include <STD_Types.h>
#include <ADC_HW.h>
#include <ADC_CFG.h>
#include <util/delay.h>
#include <Bit_Math.h>



void ADC_Init (void)
{
	//Reference Voltage Config - AVCC 
	CLR_BIT(ADMUX_REG,REFS1_BIT);
	SET_BIT(ADMUX_REG,REFS0_BIT);
	//Prescalar Division Factor
	SET_BIT(ADCSRA_REG,ADPS2_BIT);
	SET_BIT(ADCSRA_REG,ADPS1_BIT);
	SET_BIT(ADCSRA_REG,ADPS0_BIT);
	//Mode Selection : Single Conversion				Automatic Triggering - Free Running mode
	CLR_BIT(ADCSRA_REG,ADATE_BIT); // Set for Automatic Triggering and uncomment below 3 lines
	//CLR_BIT(SFIOR_REG,ADTS0_BIT);
	//CLR_BIT(SFIOR_REG,ADTS1_BIT);
	//CLR_BIT(SFIOR_REG,ADTS2_BIT);
	//Adjustment Selection - Right Adjustment by default
	// Empty
	//Set Interrupt Flag bit to 1
	// Empty 
	//ADC Enable ( use #if to check Mode selection first) 
	CLR_BIT(ADCSRA_REG,ADEN_BIT);
	/*	Disable ADC Interrupt and Clear The Flag			*/
	CLR_BIT(ADCSRA_REG,3);
	SET_BIT(ADCSRA_REG,4);
	SET_BIT(ADCSRA_REG,ADEN_BIT); 
	
}

uint16 ADC_Read (ADC_Channels Channel)
{
	float val ;
	//Don't Forget ADMUX Masking ADMUX &= 0b11100000
	SET_BIT(ADMUX_REG,0);
	CLR_BIT(ADMUX_REG,1);
	CLR_BIT(ADMUX_REG,2);
	CLR_BIT(ADMUX_REG,3);
	CLR_BIT(ADMUX_REG,4);
	
	
	SET_BIT(ADCSRA_REG,ADSC_BIT);
	
	while(GET_BIT(ADCSRA_REG,ADSC_BIT) == 1 ) ;
	
	val = ADCLH_REG;
	
	//val = (val/1024.0)*5.0; // voltage value
	//val =  val * 100.0 ;// Degree Celsius
	
	
	
	return val;
	
}
