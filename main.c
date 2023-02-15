
#include "app.h"



Uint8 state=OFF,Set_Temp=60,Avg_Temp=74;
Uint8 Temp_Arr[10]={10,10,0,50,60,30,10,50,50,50};


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
	{
		Set_Temp=MAX_TEMP;
	}
	EEPROM_WriteByte(Addr,Set_Temp);
    T0_Delay(T_Set);
    T0_Start();

}

ISR(INT2_vect)
{
	state=SET;
	Set_Temp -= 5;
	if (Set_Temp<MIN_TEMP)
	{
		Set_Temp=MIN_TEMP;
	}
	EEPROM_WriteByte(Addr,Set_Temp);
    T0_Delay(T_Set);
    T0_Start();

}