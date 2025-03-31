/*
 * GIE.c
 *
 * Created: 3/28/2025 12:25:08 AM
 *  Author: Youssef
 */ 

#include <GIE.h>

// CORRECTION: I-Bit gets set to enable interrupts, cleared to disable

void GI_Enable(void)
{
	SET_BIT(SREG_REG,I_BIT);  // Set I-bit to enable global interrupts
}

void GI_Disable(void)
{
	CLR_BIT(SREG_REG,I_BIT);  // Clear I-bit to disable global interrupts
}