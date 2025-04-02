/*
 * EXTI.c
 *
 * Created: 3/25/2025 2:45:20 PM
 *  Author: Youssef
 */ 
#include <EXTI.h>

// Null Pointers Initialization for ISR

PTR_FN EXTI0_PTR = NULL;
PTR_FN EXTI1_PTR = NULL;
PTR_FN EXTI2_PTR = NULL;

void EXTI_Init(void)
{
	
	//Clear any previous config and Initialize sense control  with the corresponding Configuration.
	CLR_BIT(MCUCSR_REG,ISC2_BIT);
	
	MCUCR_REG &= EXTI_SENSE_CONTROL_CLEAR_MASK ;
	MCUCR_REG |= (EXTI0_SENSE_CONTROL | EXTI1_SENSE_CONTROL) ;
	MCUCSR_REG |= EXTI2_SENSE_CONTROL;

	
	GICR_REG &= EXTI_MODE_CLEAR_MASK;
	#if(EXTI0_MODE == ENABLE)
	SET_BIT(GICR_REG,INT0_BIT);
	#endif
	#if(EXTI1_MODE == ENABLE)
	SET_BIT(GICR_REG,INT1_BIT);
	#endif
	#if(EXTI2_MODE == ENABLE)
	SET_BIT(GICR_REG,INT2_BIT);
	#endif
	
	//Make sure flags are initially cleared
	GIFR_REG &= EXTI_FLAG_CLEAR_MASK;
	
	//Enable Global Interrupt
	GI_Enable();
	
}

void EXTI_Setup (uint8 INT , uint8 Mode , uint8 Sense)
{
	if(Mode == DISABLE)
	{
		switch(INT)
		{
			case EXTI0:
			CLR_BIT(GICR_REG,INT0_BIT);
			break;
			case EXTI1:
			CLR_BIT(GICR_REG,INT1_BIT);
			break;
			case EXTI2:
			CLR_BIT(GICR_REG,INT2_BIT);
			break;
		
		}
	}
	else if (Mode == ENABLE) 
	{
		switch(INT)
		{
			case EXTI0:
			SET_BIT(GICR_REG,INT0_BIT);
			CLR_BIT(MCUCR_REG,ISC00_BIT);
			CLR_BIT(MCUCR_REG,ISC01_BIT);
			MCUCR_REG |= Sense;
			break;
			case EXTI1:
			SET_BIT(GICR_REG,INT1_BIT);
			CLR_BIT(MCUCR_REG,ISC10_BIT);
			CLR_BIT(MCUCR_REG,ISC11_BIT);
			MCUCR_REG |= Sense;
			break;	
			case EXTI2:
			SET_BIT(GICR_REG,INT2_BIT);
			CLR_BIT(MCUCSR_REG,ISC2_BIT);
			MCUCSR_REG |= Sense;
			break;
		}
			
	}
	
}


void EXTI_Set_Callback(uint8 INT ,PTR_FN CB_Address)
{
	switch(INT)
	{
		case EXTI0:
		EXTI0_PTR = CB_Address;
		break;
		case EXTI1:
		EXTI1_PTR = CB_Address;
		break;
		case EXTI2:
		EXTI2_PTR = CB_Address;
		break;
	}
}

void __vector_1(void) __attribute__((signal,used));
void __vector_1(void)
{
	if(EXTI0_PTR != NULL)	EXTI0_PTR() ;
}

void __vector_2(void) __attribute__((signal,used));
void __vector_2(void)
{
	if(EXTI1_PTR != NULL)	EXTI1_PTR() ;
}

void __vector_3(void) __attribute__((signal,used));
void __vector_3(void)
{
	if(EXTI2_PTR != NULL)	EXTI2_PTR() ;
}

