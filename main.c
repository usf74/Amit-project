
#include "app.h"



Uint8 state=OFF,Set_Temp=60,Avg_Temp=74;
Uint8 Temp_Arr[10]={60,60,60,60,60,60,60,60,60,60};


int main(void)
{
	App_Init();
	state=ON;
	T0_Init();
	Temp_Sensor_Init();
	//T0_Delay(T_Temp);
	//T0_Start();

	
	while(1)
	{

		S7_Display(Temp_Sensor_Read());
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
}

