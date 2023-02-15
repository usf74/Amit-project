
#include "app.h"
extern Uint8 state,Set_Temp,Avg_Temp;
void App_Init()
{
    T0_Init();
    T2_Init();
    Temp_Sensor_Init();
    Heating_Element_Init();
    Cooling_Element_Init();
    LED0_Init();
    EXT0_INT_Init();
    EXT1_INT_Init();
    EXT2_INT_Init();
	S7_Init();
    EEPROM_WriteByte(Addr,Set_Temp);

    state=OFF;
}
void State_Off()
{ 
    //Turn off and await on button
    T0_Stop();
    T2_Stop();
    S7_Turn_Off();
    LED0_OFF();
    Heating_Element_OFF();
    Cooling_Element_OFF();

    while (state==OFF); //Await interrupt of ON button
}
void State_On()
{
    S7_Turn_ON();
    Set_Temp=EEPROM_ReadByte(Addr);

    //Start timer for temp measurement
    T0_Delay(T_Temp);
	T0_Start();
    
    if (Avg_Temp<(Set_Temp-Thresh_Temp))
    {
        //Heating
        Cooling_Element_OFF();
        Heating_Element_ON();
        LED0_ON();
        while((Avg_Temp<Set_Temp) && (state==ON))
        {
            S7_Display(Avg_Temp);
        }
    }

    else if (Avg_Temp>(Set_Temp+Thresh_Temp))
    {
        //Start timer for LED Blinking
        T2_Delay(T_Blink);
	    T2_Start();
        //Start cooling
        Cooling_Element_ON();
        Heating_Element_OFF();
        while((Avg_Temp>Set_Temp) && (state==ON))
        {
            S7_Display(Avg_Temp);
        }
    }

    else
    {
        T2_Stop();
        Cooling_Element_OFF();
        Heating_Element_OFF();
        LED0_OFF();
        while ((Avg_Temp>=(Set_Temp-Thresh_Temp)) && ((Avg_Temp<=(Set_Temp+Thresh_Temp))) && (state==ON));    //Loop to await change in temperature with a +-5 threshold
    }

}
void State_Set_Temp()
{
    // 5 seconds timer start
    T0_Delay(T_Set);
    T0_Start();

    T2_Delay(T_Blink);
    T2_Start();
    while(state==SET);
}
Uint8 AVG(Uint8 *Data)
{
    Uint8 s=0;
    for(Uint8 i=0;i<10;i++)
    {
        s+=Data[i];
    }
    return s/10;
}