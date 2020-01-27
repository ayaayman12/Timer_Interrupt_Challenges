/*
 * GPIO_REQ10_REQ9.c
 *
 * Created: 1/25/2020 12:31:33 PM
 * Author : A_ayman
 */ 

#include "gpio.h"
#include "std_types.h"
#include "registers.h"
#include "led.h"
#include "timers.h"



void periodic_state_machine(void)
{
	static uint8_t machine_no=0;
	switch(machine_no)
	{
		case(0):
		Led_Off(LED_2);
		Led_On(LED_1);         // it means go..
		timer0DelayMs(1000);
		machine_no=1;
		break;
		case (1):
		Led_Off(LED_1);
		Led_On(LED_3);        // it means stop.
		timer0DelayMs(1000);
		machine_no=2;
		break;
		case (2):
		Led_Off(LED_3);
		Led_On(LED_2);
		timer0DelayMs(1000);     // it means get ready.
		machine_no=0;
		break;
		default:
		break;
		
	}
	
	
}



int main(void)
{
	/* Replace with your application code */
	Led_Init(LED_1);
	Led_Init(LED_2);
	Led_Init(LED_3);
	timer0Init(T0_NORMAL_MODE,T0_OC0_DIS,T0_PRESCALER_8,0,0,T0_INTERRUPT_NORMAL);
	timer0Start();
	while (1)
	{
		periodic_state_machine();
	}
}

