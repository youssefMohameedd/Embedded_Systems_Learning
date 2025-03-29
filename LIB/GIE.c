/*
 * GIE.c
 *
 * Created: 3/28/2025 12:25:08 AM
 *  Author: Youssef
 */ 

#include <GIE.h>


// Notice : I-Bit gets cleared when user write logical one on it 


void GI_Enable(void)
{
	CLR_BIT(SREG_REG,I_BIT);
}
void GI_Disable(void)
{
	SET_BIT(SREG_REG,I_BIT);
}