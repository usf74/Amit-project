
#include "app.h"



Uint8 state=OFF,Avg_Temp;
Uint8 Temp_Arr[10];	//Array of 10 temperature values to measure the average
Uint8 Set_Temp;	//Temperature set by user

int main(void)
{
	App_Init();	//Initialize all components
	
	while(1)	//Switch case between the 3 states by the state variable
	{
		switch (state)
		{
			case ON:
			State_On(); break;
			case OFF:
			State_Off(); break;
			case SET:
			State_Set_Temp(); break;
		}
	}
}

ISR(INT0_vect)	// ON/OFF Button interrupt
{
	state= !state;
}

ISR(INT1_vect)	// UP button interrupt
{
	if (state==SET || state==ON)
	{
		state=SET;	//change current state
		Set_Temp += 5;	//increase set temp by 5
		if (Set_Temp>MAX_TEMP)	//Max temperature set limit
		{
			Set_Temp=MAX_TEMP;
		}
		EEPROM_WriteByte(Addr,Set_Temp);	//Save new temperature
		//Start timer of 5 seconds.
		//The timer start is situated here because the 5 seconds need to start from beginning every time the button is pressed
		T0_Delay(T_Set);	
		T0_Start();
	}

}

ISR(INT2_vect)
{
	if (state==SET || state==ON)
	{
		state=SET;	//change current state
		Set_Temp -= 5;	//Decrease set temp by 55;
		if (Set_Temp<MIN_TEMP)	//Min temperature set limit
		{
			Set_Temp=MIN_TEMP;
		}
		EEPROM_WriteByte(Addr,Set_Temp);
		//Start timer of 5 seconds.
		//The timer start is situated here because the 5 seconds need to start from beginning every time the button is pressed
		T0_Delay(T_Set);
		T0_Start();
	}

}