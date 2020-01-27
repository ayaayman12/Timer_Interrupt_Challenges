/*
 * GPIO_REQ12_REQ8.c
 *
 * Created: 1/25/2020 2:54:49 PM
 * Author : A_ayman
 */ 

#include "gpio.h"
#include "pushButton.h"
#include "led.h"
#include "timers.h"


int main(void)
{
	
	Led_Init(LED_0);
	pushButtonInit(BTN_0);
	/* Replace with your application code */
	timer0Init(T0_NORMAL_MODE,T0_OC0_DIS,T0_PRESCALER_8,6,0,T0_INTERRUPT_NORMAL);
	timer0Start();
	sei();
	while (1)
	{
		 
		BTN_status=pushButtonGetStatus(BTN_0);
		Led_On(LED_0);
		if (BTN_status==Pressed)
		{
			 
			count++;
			while (count!=0)
			{
				count--;
				while(sec<5)
				{
					 Led_On(LED_0);
		      } 
			}  
		}
		else
		{
			Led_Off(LED_0);
		}
	}
}
