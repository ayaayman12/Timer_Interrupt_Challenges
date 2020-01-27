/*
 * timers.c
 *
 * Created: 1/20/2020 10:53:02 PM
 *  Author: A_ayman
 */ 

#include "timers.h"
typedef struct
{
	uint64_t delay_counts;
	uint16_t OV_count;
	uint8_t timer_init_value;
	
}delay_parameters_t;

volatile uint8_t machine_number=0;
uint16_t ov_counts=0;
uint8_t prescal=0;
uint8_t re_prescal=0;

void timer0Init(En_timer0Mode_t en_mode,En_timer0OC_t en_OC0,En_timer0perscaler_t en_prescal, uint8_t u8_initialValue, uint8_t u8_outputCompare, En_timer0Interrupt_t en_interruptMask)
{
	TCCR0|=en_mode;
	TCCR0|=en_OC0;
	prescal=en_prescal;
	re_prescal=en_prescal;
	TCNT0=u8_initialValue;
	OCR0=u8_outputCompare;
	TIMSK|=en_interruptMask;
}

void timer0Set(uint8_t u8_value)
{
	TCNT0=u8_value; 
}

uint8_t timer0Read(void)
{
	volatile uint8_t timer0_Read= TCNT0;
	 return timer0_Read;
}
void timer0Start(void)
{
	TCCR0|=prescal;
}

void timer0Stop(void)
{
	TCCR0&=~(0x07);
	TCCR0|=T0_NO_CLOCK;
	
}
	
void timer0DelayMs(uint16_t u16_delay_in_ms)
{
	/* this function based on prescaller =8 and fcpu=8Mhz*/
	/* timer freq 1 MHZ */
	/* each tick =1us */
	uint16_t i=0;
	uint16_t j=0;
	delay_parameters_t timer_delay ;
	switch (prescal)
	{
		case (T0_PRESCALER_8):
		timer_delay.delay_counts=1000; //it will count 2000 ticks to get 1 msec
		timer_delay.OV_count=3;
		timer_delay.timer_init_value=24;
		break;
		default:
		break;
	}	
	timer0Start();
	for (i=0;i<u16_delay_in_ms;i++)
	{
		TCNT0=timer_delay.timer_init_value;	
		for( j=0;j<=timer_delay.OV_count;j++)
		{
			//while((TIFR>>TOV0)&1==0);
			while((TIFR & 1)!=1);
			TIFR|=0x01;
		}
	}
	timer0Stop();
}

void timer0DelayUs(uint32_t u32_delay_in_us)
{
	/* this function based on prescaller =8 and fcpu=8 Mhz*/
	/* timer freq 1 MHZ */
	/* each tick =1 us */
	/* this function take around 11.84 us for calling and context switching so we will not be able to get the exact delay for values less than 12 us*/
	uint16_t j=0;
	delay_parameters_t timer_delay ;
	timer0Start();
	if (u32_delay_in_us<15)
	{
		
	}
	else if (20<=u32_delay_in_us&&u32_delay_in_us<=256)
	{
		TCNT0=272-u32_delay_in_us;
		while((TIFR & 1)!=1);
		TIFR|=0x01;
	}
	
	
	else
	{
		switch  (prescal)
		{
			case (T0_PRESCALER_8):
			timer_delay.delay_counts=(u32_delay_in_us-15);
			timer_delay.OV_count=(timer_delay.delay_counts)/256;
			timer_delay.timer_init_value=255-((timer_delay.delay_counts)%256);
			break;
			default:
			break;
		}
		TCNT0=timer_delay.timer_init_value;
		for( j=0;j<=timer_delay.OV_count;j++)
		{
			//while((TIFR>>TOV0)&1==0);
			while(!(TIFR & 1));
			TIFR|=0x01;
		}
	}		
}



void timer0SwPWM(uint8_t u8_dutyCycle,uint8_t u8_frequency)
{
	uint8_t pwm_period=(1000/u8_frequency);
	uint8_t Ton=(u8_dutyCycle*pwm_period)/100;
	uint8_t Toff=pwm_period-Ton;
	gpioPinWrite(GPIOB,BIT4,HIGH);
	Led_On(LED_0);
	timer0DelayMs(Ton);
	gpioPinWrite(GPIOB,BIT4,LOW);
	timer0DelayMs(Toff);	
}



ISR(TIMER0_OVF_vect)
{
	 ov_counts++;
	 TCNT0=6;
	 if(ov_counts==4000) //we need 4000 over flow to get 1 sec//
	 {
		  ov_counts=0;
		  machine_number++;
		  if (machine_number==3)
		  {
				machine_number=0;
	     }
	 }	 
}
/////////////////////////////timer1///////////////////////
void timer1Init(En_timer1Mode_t en_mode,En_timer1OC_t en_OC,En_timer1perscaler_t en_prescal, uint16_t u16_initialValue, uint16_t u16_outputCompareA, uint16_t u16_outputCompareB,uint16_t u16_inputCapture, En_timer1Interrupt_t en_interruptMask)
{
	 
}


