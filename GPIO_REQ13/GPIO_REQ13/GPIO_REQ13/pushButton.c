/*
 * pushButton.c
 *
 * Created: 1/18/2020 6:08:45 PM
 *  Author: A_ayman
 */ 

#include "pushButton.h"
#include "softwareDelay.h"
#include <util/delay.h>
/* This function is implemented to configure pushButton Pins as INPUT*/
void pushButtonInit(En_buttonId_t en_butotn_id)
{
	switch (en_butotn_id)
	{
		case BTN_0:
		{
			gpioPinDirection(BTN_0_GPIO, BTN_0_BIT,INPUT);
			gpioPinWrite(BTN_0_GPIO, BTN_0_BIT,HIGH);     // to activate internal pull up resistor 
			break;
		}
		case BTN_1:
		{
			gpioPinDirection(BTN_1_GPIO, BTN_1_BIT, INPUT);
			gpioPinWrite(BTN_1_GPIO, BTN_1_BIT,HIGH);     // to activate internal pull up resistor 
			break;
		}
		case BTN_2:
		{
			gpioPinDirection(BTN_2_GPIO, BTN_2_BIT, INPUT);
			gpioPinWrite(BTN_2_GPIO, BTN_2_BIT,HIGH);     // to activate internal pull up resistor 
			
			break;
		}
		case BTN_3:
		{
			gpioPinDirection(BTN_3_GPIO, BTN_3_BIT, INPUT);
			gpioPinWrite(BTN_3_GPIO, BTN_3_BIT,HIGH);     // to activate internal pull up resistor 
			break;
		}
		default :
		break;
	}
}

 En_buttonStatus_t pushButtonGetStatus(En_buttonId_t en_butotn_id)
{
	
	uint8_t buttonStatus=-1;
	volatile uint8_t pin_read;

	switch (en_butotn_id)
	{
		case BTN_0:
		{
			pin_read=gpioPinRead(BTN_0_GPIO, BTN_0_BIT);
			if (pin_read==LOW)
			{
				/*SwDelay_ms(30);*/
				_delay_ms(30);
				pin_read=gpioPinRead(BTN_0_GPIO, BTN_0_BIT);
				if (pin_read==LOW)
				{
					buttonStatus= Pressed;
				}
				else
				{
					buttonStatus= Released;
				}
			}
			else
			{
				_delay_ms(30);
				pin_read=gpioPinRead(BTN_0_GPIO, BTN_0_BIT);
				if (pin_read==LOW)
				{
					buttonStatus= Pressed;
				
				}
				else
				{
					buttonStatus= Released;
				}
			
			}
			break;
		}
	
		case BTN_1:
		{
			pin_read=gpioPinRead(BTN_1_GPIO, BTN_1_BIT);
			if (pin_read==0)
			{
				SwDelay_ms(30);
				pin_read=gpioPinRead(BTN_1_GPIO, BTN_1_BIT);
			
				if (pin_read==0)
				{
					buttonStatus= Pressed;
				
				}
				else
				{
					buttonStatus= Released;
				}
			}
			else
			{
				SwDelay_ms(30);
				pin_read=gpioPinRead(BTN_1_GPIO, BTN_1_BIT);
				if (pin_read==0)
				{
					buttonStatus= Pressed;
				
				}
				else
				{
					buttonStatus= Released;
				}
			
			}
			break;
		}
		case BTN_2:
		{
			pin_read=gpioPinRead(BTN_2_GPIO, BTN_2_BIT);
			if (pin_read==0)
			{
				SwDelay_ms(30);
				pin_read=gpioPinRead(BTN_2_GPIO, BTN_2_BIT);
			
				if (pin_read==0)
				{
					buttonStatus= Pressed;
				
				}
				else
				{
					buttonStatus= Released;
				}
			}
			else
			{
				SwDelay_ms(30);
				pin_read=gpioPinRead(BTN_2_GPIO, BTN_2_BIT);
				if (pin_read==0)
				{
					buttonStatus= Pressed;
				
				}
				else
				{
					buttonStatus= Released;
				}
			
			}
			break;
		}
		case BTN_3:
		{
			pin_read=gpioPinRead(BTN_3_GPIO, BTN_3_BIT);
			if (pin_read==0)
			{
				SwDelay_ms(30);
				pin_read=gpioPinRead(BTN_3_GPIO, BTN_3_BIT);
			
				if (pin_read==0)
				{
					buttonStatus= Pressed;
				
				}
				else
				{
					buttonStatus= Released;
				}
			}
			else
			{
				SwDelay_ms(30);
				pin_read=gpioPinRead(BTN_3_GPIO, BTN_3_BIT);
				if (pin_read==0)
				{
					buttonStatus= Pressed;
				}
				else
				{
					buttonStatus= Released;
				}
			
			}
			break;
		}
		default :
		break;
	}
	return buttonStatus;

}
	