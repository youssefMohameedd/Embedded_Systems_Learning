/*
 * Project_Test.c
 *
 * Created: 10/27/2024 10:29:19 PM
 * Author : Youssef Mohamed
*/

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <util/delay.h>
#include <SSD.h>
#include <LED.h>
#include <LCD.h>
#include <Keypad.h>
#include <Stepper.h>
#include <Sensors.h>

void PushB_ISR()
{
	Write_LED(LED0,HIGH);
	_delay_ms(1000);
	Write_LED(LED0,LOW);
	_delay_ms(1000);

}

int main(void)
{
	
	LED_Init(LED0);
	PushB_Init(PushB0);
	EXTI_Init();
	EXTI0_Set_Callback(&PushB_ISR);
	

	while(1)
	{
	
		
		
	}
	
	return 0;
}
