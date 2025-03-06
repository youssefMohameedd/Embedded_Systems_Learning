/*
 * Stepper.c
 *
 * Created: 12/16/2024 2:24:21 PM
 *  Author: Youssef
 */ 

#include <Stepper.h>
#include <util/delay.h>
#include <stdlib.h>

// make sure to connect the coils in the correct order in the nibble to match the given control seqeunce

uint8 wave_step_sequence[4] = {0b1110,0b1101,0b1011,0b0111};
uint8 full_step_sequence[4] = {0b1100,0b1001,0b0011,0b0110};
uint8 half_step_sequence[8] = {0b1110,0b1100,0b1101,0b1001,
							   0b1011,0b0011,0b0111,0b0110};
							   
//below function is implemented as you cannot pass a run-time variable to _delay_ms() function
void delay_ms_variable(uint16 ms)
{
    while (ms--)
        _delay_us(1000); // 1ms delay
}

void Stepper_Init(void)
{
	Set_Nibble_Direction(STEPPER_PORT,STEPPER_SIG,0xF);
	Write_Nibble(STEPPER_PORT,STEPPER_SIG,0xF);//0x0:Stall,0xF:Loose (because common wire is connected to  ground)

}

void Stepper_Rotate(sint16 angle,uint16 speed)
{
	sint16 steps, step_sequence_size ,direction; 
	uint8 * step_sequence;
	uint8 step_index = 0;
	uint16 speed_delay = 1000.0 / (1.0 * speed);
	 
	#if (STEPPING == 2) // Wave Stepping
	step_sequence_size = 4;
	step_sequence = wave_step_sequence;
	steps = abs(angle * (32.0 / 360.0));
	 
	#elif (STEPPING == 1) // Full Stepping
	step_sequence_size = 4;
	step_sequence = full_step_sequence;
	steps = abs(angle * (32.0 / 360.0));

	#elif (STEPPING == 0) // Half-Stepping
	step_sequence_size = 8;
	step_sequence = half_step_sequence;
	steps = abs(angle * (64.0 / 360.0));
	 
	#endif
	 
	//steps = steps *GR		Uncomment this line during physical operation to compensate Gear Ratio effect
	
	if(angle>0)
	{
		direction = 1;
		step_index = 0;
	}
	else
	{
		direction = -1;
		step_index = step_sequence_size - 1;
	}
	  
	for (uint16 i = 0; i < steps; i++)
	{
		Write_Nibble(STEPPER_PORT, STEPPER_SIG, step_sequence[step_index]);
		delay_ms_variable(speed_delay);  // Full delay to hold the coil activation
		step_index = (step_index + direction +step_sequence_size)%step_sequence_size;
	}
	
}
