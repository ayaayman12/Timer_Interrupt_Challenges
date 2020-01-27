/*
 * GPIO_REQ10_REQ8.c
 *
 * Created: 1/25/2020 12:12:15 PM
 * Author : A_ayman
 */ 
#include "gpio.h"
#include "pushButton.h"
#include "led.h"
#include "timers.h"


int main(void)
{
	uint8_t BTN_status;
	uint8_t count=1;
	Led_Init(LED_0);
	pushButtonInit(BTN_0);
	timer0Init(T0_NORMAL_MODE,T0_OC0_DIS,T0_PRESCALER_8,0,0,T0_INTERRUPT_NORMAL);
	timer0Start();
	/* Replace with your application code */
	
	while (1)
	{
		BTN_status=pushButtonGetStatus(BTN_0);
		if (BTN_status==Pressed)
		{
			count++;
			while (count!=0)
			{
				count--;
				
				Led_On(LED_0);
				timer0DelayMs(170);
				BTN_status=pushButtonGetStatus(BTN_0);
				if (BTN_status==Pressed)
				{
					count++;
				}
				timer0DelayMs(170);
				BTN_status=pushButtonGetStatus(BTN_0);
				if (BTN_status==Pressed)
				{
					count++;
				}
				timer0DelayMs(170);
				BTN_status=pushButtonGetStatus(BTN_0);
				if (BTN_status==Pressed)
				{
					count++;
				}
				timer0DelayMs(170);
				BTN_status=pushButtonGetStatus(BTN_0);
				if (BTN_status==Pressed)
				{
					count++;
				}
				timer0DelayMs(170);
				BTN_status=pushButtonGetStatus(BTN_0);
				if (BTN_status==Pressed)
				{
					count++;
				}
				
			}
			
		}
		else
		{
			Led_Off(LED_0);
		}
	}
}


