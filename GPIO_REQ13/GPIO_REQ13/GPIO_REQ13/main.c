/*
 * GPIO_REQ13.c
 *
 * Created: 1/25/2020 11:38:25 PM
 * Author : A_ayman
 */ 

#include "gpio.h"
#include "std_types.h"
#include "registers.h"
#include "led.h"
#include "timers.h"



void periodic_state_machine(void)
{
	switch(machine_number)
	{
		case(0):
		Led_Off(LED_2);
		Led_On(LED_1);         // it means go..
		BTN_status=pushButtonGetStatus(BTN_0);
		break;
		case (1):
		Led_Off(LED_1);
		Led_Off(LED_2);
		Led_On(LED_3);        // it means stop.
		BTN_status=pushButtonGetStatus(BTN_0);
		break;
		case (2):
		Led_Off(LED_3);
		Led_On(LED_2);       // it means get ready.
		BTN_status=pushButtonGetStatus(BTN_0);
		break;
		default:
		break;
		
	}
	
	
}



int main(void)
{
	/* Replace with your application code */
	Led_Init(LED_1);
	Led_Init(LED_0);
	Led_Init(LED_2);
	Led_Init(LED_3);
	timer0Init(T0_NORMAL_MODE,T0_OC0_DIS,T0_PRESCALER_8,6,0,T0_INTERRUPT_NORMAL);
	timer0Start();
	pushButtonInit(BTN_0);
	Enable_Global_Interrupt();
	while (1)
	{
		periodic_state_machine();
		/*BTN_status=pushButtonGetStatus(BTN_0);*/
		
	}
}

