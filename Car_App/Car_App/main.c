/*
 * Car_App.c
 *
 * Created: 1/27/2020 2:40:53 PM
 * Author : A_ayman
 */ 
#include "gpio.h"
#include "interrupts.h"
#include "timers.h"
#include "softwareDelay.h"
#include "dcMotor.h"
#include "led.h"

ISR(TIMER0_OVF_vect)
{
	
	
	if((ov_counts ) == (Gu8_dutyCycle)) ////
	{
		gpioPinWrite(MOTOR_EN_1_GPIO,MOTOR_EN_1_BIT,LOW) ;
		gpioPinWrite(MOTOR_EN_2_GPIO,MOTOR_EN_2_BIT,LOW) ;
	}
	else if(ov_counts ==100)
	{
		ov_counts=0;
		gpioPinWrite(MOTOR_EN_1_GPIO,MOTOR_EN_1_BIT,HIGH) ;
		gpioPinWrite(MOTOR_EN_2_GPIO,MOTOR_EN_2_BIT,HIGH) ;
	}
	ov_counts++;
	TCNT0=Timer_initial_value;
}


int main(void)
{
	 sei();
	 Led_Init(LED_0);
	 uint8_t i=0;
	 MotorDC_Init(MOT_1);
	 MotorDC_Init(MOT_2);
	 uint8_t count=0;
	 timer2Init(T2_NORMAL_MODE,T2_OC2_DIS,T2_PRESCALER_8,0, 0, 0,T2_POLLING);
    /* Replace with your application code */
   // while (1) 
    {   
	 
// 		  Led_On(LED_0);
// 		  timer2DelayMs(1);
// 		  Led_Off(LED_0);
// 		  timer2DelayMs(1);
				
				MotorDC_Dir(MOT_1, FORWARD);
				MotorDC_Dir(MOT_2, FORWARD);
				for (i=1;i<=5;i++)
				{
				 MotorDC_Speed_PollingWithT0(count);
				 timer2DelayMs(1000);
				 count+=20;
				}
			  for (i=1;i<=5;i++)
			  {
				  MotorDC_Speed_PollingWithT0(count);
				  timer2DelayMs(1000);
				  count-=20;
			  }
			  	MotorDC_Dir(MOT_1, STOP);
			  	MotorDC_Dir(MOT_2, STOP);
			   timer2DelayMs(1000);
				MotorDC_Dir(MOT_1, FORWARD);
				MotorDC_Dir(MOT_2, STOP);
				MotorDC_Speed_PollingWithT0(30);
				timer2DelayMs(500);
				
				
				
			 
			
// 				
// 				for (i=0;i<5;i++)
// 				{
// 					MotorDC_Dir(MOT_1, BACKWARD);
// 					MotorDC_Dir(MOT_2, BACKWARD);
// 					MotorDC_Speed_PollingWithT0(count);
// 					timer2DelayMs(1);
// 					count-=20;
// 				}
// 				

		  
		  
    }
}

