/*
 * Stepper.c
 *
 * Created: 12/16/2024 2:24:21 PM
 *  Author: Youssef
 */ 

#include <Stepper.h>
#include <util/delay.h>


uint8 coils[4] = {IN1,IN2,IN3,IN4};
uint8 wave_step_sequence[4] = {0b1110,0b1101,0b1011,0b0111};
uint8 full_step_sequence[4] = 
	{
		0b1100,
		0b1001,
		0b0011,
		0b0110,
		
	};
uint8 half_step_sequence[8] = 
	{
	0b1110,
	0b1100,
	0b1101,
	0b1001,
	0b1011,
	0b0011,
	0b0111,
	0b0110
	};
	
void delay_ms_variable(uint16 ms)
{
    while (ms--)
        _delay_us(1000); // 1ms delay
}

void Stepper_Init(void)
{
	
	for(uint8 i = 0 ; i < 4 ; i++)
	{
		Set_Channel_Direction(coils[i],OUTPUT);
		Write_Channel(coils[i],HIGH); //LOW:Stall,HIGH:Loose (because common wire is connected to  ground)
	}
			
}

void Stepper_Rotate(sint16 angle,uint16 speed)
{
	 sint16 steps, step_sequence_size ; 
	 uint8 * step_sequence;
	 uint8 step_index = 0;
	 uint16 speed_delay = 1000.0 / (1.0 * speed);
	 
	 #if (STEPPING == 2) // Wave Stepping
	 step_sequence_size = 4;
	 step_sequence = wave_step_sequence;
	 steps = angle * (32.0 / 360.0);
	 
	 #elif (STEPPING == 1) // Full Stepping
	 step_sequence_size = 4;
	 step_sequence = full_step_sequence;
	 steps = angle * (32.0 / 360.0);

	 #elif (STEPPING == 0) // Half-Stepping
	 step_sequence_size = 8;
	 step_sequence = half_step_sequence;
	 steps = angle * (64.0 / 360.0);
	 
	 #endif
	 
	 for (uint16 i = 0; i < steps; i++)
	 {
		step_index = step_index%step_sequence_size;
		 Write_Nibble(STEPPER_PORT, STEPPER_SIG, step_sequence[step_index]);
		 delay_ms_variable(speed_delay);  // Full delay to hold the coil activation
		 step_index++;
	 }
	
}



/*
else if (steps<0)
{
	steps = -steps;
	
	for(uint16 i = 0 ; i < steps ; i++)
	{
		Write_Nibble(STEPPER_PORT,STEPPER_SIG,full_step_sequence[step_index]);
		delay_ms_variable(speed_delay);
		Write_Nibble(STEPPER_PORT,STEPPER_SIG,0x0);
		delay_ms_variable(speed_delay);
		step_index =(step_index+3)%4;
	}
	
}
*/