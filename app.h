
#ifndef APP_H_
#define APP_H_


#include "LED.h"
#include "Timers.h"
#include "S7.h"
#include "EXT_INT.h"
#include "EEPROM.h"
#include "Temp_Sensor.h"
#include "Cooling_Element.h"
#include "Heating_Element.h"

#define OFF 0
#define ON 1
#define SET 2
#define Addr 0x500

// Parameters
#define T_Temp 100
#define T_Blink 500
#define T_Set   5000

#define MAX_TEMP 75
#define MIN_TEMP 35
#define Thresh_Temp 5   //Threshold temperature

//Func prototypes
Uint8 AVG(Uint8 *Data);
void State_Set_Temp();
void State_On();
void State_Off();
void App_Init();


#endif