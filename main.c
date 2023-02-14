
#include "LED.h"

#include "EXT_INT.h"

#include "ADC.h"
#include "Timers.h"
#include "app.h"
#define F_CPU 16000000
#include <util/delay.h>

#include <avr/interrupt.h>

Uint8 state,Set_Temp=60,Avg_Temp;
Uint8 Temp_Arr[10];


int main(void)
{
	App_Init();
	
	while(1)
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

ISR(INT0_vect)
{
	state= !state;
}

ISR(INT1_vect)
{
	state=SET;
	Set_Temp += 5;
	if (Set_Temp>MAX_TEMP)
		Set_Temp=MAX_TEMP;
	EEPROM_WriteByte(Addr,Set_Temp);
}

ISR(INT2_vect)
{
	state=SET;
	Set_Temp -= 5;
	if (Set_Temp<MIN_TEMP)
		Set_Temp=MIN_TEMP;
	EEPROM_WriteByte(Addr,Set_Temp);
}
