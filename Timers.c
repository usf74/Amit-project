

#include <avr/interrupt.h>
#include "app.h"
extern Uint8 state,Set_Temp,Avg_Temp;
extern Uint8 Temp_Arr[10];



// Timer0 variables
Uint16 T0_OVF_num = 0;
Uint16 T0_OCF_num = 0;
Uint8  T0_OVF_Init_val = 0;
Uint8  T0_OCF_Init_val = 0;
Uint8 T0_G_Val = 0;

// Timer2 variables
Uint16 T2_OVF_num = 0;
Uint16 T2_OCF_num = 0;
Uint8  T2_OVF_Init_val = 0;
Uint8  T2_OCF_Init_val = 0;
Uint8  T2_G_Val = 0;

/************************************************************************/
/*								TIMER 0                                 */
/************************************************************************/

// Timer0 Functions
void T0_Init(void)
{
	// Global Enable/ Disable Interrupt
	SREG = (Global_INT << 7) | (SREG & 0X7F);
	
	// Peripheral Enable/ Disable Interrupt
	TIMSK = (T0_OVF_INT) | (T0_OCF_INT << 1) | (TIMSK & 0XFC);
	
	// Timer0 Mode
	TCCR0 = (Get_Bit(Timer0_Mode, 0) << 6) | (Get_Bit(Timer0_Mode, 1) << 3) | (TCCR0 & 0XB7);
	
}
void T0_Delay(Uint32 delay_ms)
{
	f32 Tick_Time_us = (f32)(Timer0_PreSC) / F_OSC_MHZ;
	Uint32 Tick_num = (delay_ms * 1000)/ Tick_Time_us;
	
	#if Timer0_Mode == T0_OVF
	
	T0_OVF_num = Tick_num % 256 ? (Tick_num / 256) + 1 : (Tick_num / 256);
	
	T0_OVF_Init_val = 256 - (Tick_num % 256);
	TCNT0 = T0_OVF_Init_val;
	
	#elif Timer0_Mode == T0_CTC

	T0_OCF_num = Tick_num % 256 ? (Tick_num / 256) + 1 : (Tick_num / 256);
	
	T0_OCF_Init_val = (Tick_num % 256) - 1;
	OCR0 = T0_OCF_Init_val;

	#endif
}
void T0_Start(void)
{
	TCCR0 = Timer0_CLK | (TCCR0 & 0XF8);
}
void T0_Stop(void)
{
	TCCR0 &= 0XF8;		//	   1 1 0 1 | 0 1 0 1
	//	  &
	//     1 1 1 1 | 1 0 0 0
	//     -----------------
	//     1 1 0 1 | 0 0 0 0
}

ISR(TIMER0_OVF_vect)
{
	static Uint32 count = 0;
	count++;
	if (count == T0_OVF_num)
	{
		// ------------------Actual Function that will occur when set time happens--------------------
		//------------------------------------------------
		if (state==SET)	//In set mode this is the 5 seconds timer to change the state
		{
			state=ON;
		}
		else if (state==ON)
		{
			//In on state the timer measures the temperature each 100 ms 
			static Uint8 c=0;
			Temp_Arr[c%10]=Temp_Sensor_Read();	//Read sensor and store value in array
			c++;
			Avg_Temp=AVG(Temp_Arr);	//Calculate average temperature
			//Restart timer for next measurement
			T0_Delay(T_Temp);
			T0_Start();
		}
		//-----------End of the desired function-----------
		//---------------------------------------
		
		
		
		T0_G_Val++;
		count = 0;
		TCNT0 = T0_OVF_Init_val;
	}
	
}

ISR(TIMER0_COMP_vect)	//Used in comp mode 
{
	static Uint32 count = 0;
	count++;
	if (count == T0_OCF_num)
	{

		T0_G_Val++;
		
		
		count = 0;
		OCR0 = T0_OCF_Init_val;
	}
	else
	OCR0 = 255;
}

/************************************************************************/
/*								TIMER 2                                 */
/************************************************************************/

// Timer2 Functions
void T2_Init(void)
{
	// Global Enable/ Disable Interrupt
	SREG = (Global_INT << 7) | (SREG & 0X7F);
	
	// Peripheral Enable/ Disable Interrupt
	TIMSK = (T2_OVF_INT << 6) | (T2_OCF_INT << 7) | (TIMSK & 0X3F);
	
	// Timer2 Mode
	TCCR2 = (Get_Bit(Timer2_Mode, 0) << 6) | (Get_Bit(Timer2_Mode, 1) << 3) | (TCCR2 & 0XB7);
}
void T2_Delay(Uint32 delay_ms)
{
	f32 Tick_Time_us = (f32)(Timer2_PreSC) / F_OSC_MHZ;
	Uint32 Tick_num = (delay_ms * 1000)/ Tick_Time_us;
	
	#if Timer2_Mode == T2_OVF
	
	T2_OVF_num = Tick_num % 256 ? (Tick_num / 256) + 1 : (Tick_num / 256);
	
	T2_OVF_Init_val = 256 - (Tick_num % 256);
	TCNT2 = T2_OVF_Init_val;
	
	#elif Timer2_Mode == T2_CTC

	T2_OCF_num = Tick_num % 256 ? (Tick_num / 256) + 1 : (Tick_num / 256);
	
	T2_OCF_Init_val = (Tick_num % 256) - 1;
	OCR2 = T2_OCF_Init_val;

	#endif
}
void T2_Start(void)
{
	TCCR2 = Timer2_CLK | (TCCR2 & 0XF8);
}
void T2_Stop(void)
{
	TCCR2 &= 0XF8;		
}

ISR(TIMER2_OVF_vect)
{
	static Uint32 count = 0;
	count++;
	if (count == T2_OVF_num)
	{
		// ------------------Actual Function that will occur when set time happens--------------------
		//------------------------------------------------
		if(state==ON)	//In ON state this timer controls the blinking of LED in heating mode
		{
			LED0_Toggle();
			//Restart timer
			T2_Delay(T_Blink);
			T2_Start();
		}
		else if (state==SET)	//In set mode this timer blinks the 7 segment display
		{
			S7_Toggle();
			//Restart timer
			T2_Delay(T_Blink);
			T2_Start();
		}
		//-----------End of the desired function-----------
		//---------------------------------------
		
		
		
		
		T2_G_Val++;
		count = 0;
		TCNT2 = T2_OVF_Init_val;
	}
	
}

ISR(TIMER2_COMP_vect)	//Used in comp mode
{
	static Uint32 count = 0;
	count++;
	if (count == T2_OCF_num)
	{
		
		
		T2_G_Val++;
		count = 0;
		OCR2 = T2_OCF_Init_val;
	}
	else
	OCR2 = 255;
}







