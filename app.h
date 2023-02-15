
#ifndef APP_H_
#define APP_H_

#define F_CPU 16000000
#include <util/delay.h>
#include <avr/interrupt.h>

//Components inclusion
#include "app_CFG.h"
#include "LED.h"
#include "Timers.h"
#include "S7.h"
#include "EXT_INT.h"
#include "EEPROM.h"
#include "Temp_Sensor.h"
#include "Cooling_Element.h"
#include "Heating_Element.h"
//Macros
#define OFF 0
#define ON 1
#define SET 2
#define Addr 0x0


//Func prototypes
Uint8 AVG(Uint8 *Data);
void State_Set_Temp();
void State_On();
void State_Off();
void App_Init();


#endif