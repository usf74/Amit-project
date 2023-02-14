#ifndef TEMP_SENSOR_H_
#define TEMP_SENSOR_H_

#include "std.h"
#include "MCU.h"
#include "Interrupts.h"
#include "ADC.h"

#include "Temp_Sensor_CFG.h"

#define Temp_Sensor_Init() (ADC_Init())
#define Temp_Sensor_Read() (Uint8)((ADC_Read(Temp_Sensor_PIN))*1024.0/0.01)   //Return temperature in degrees

#endif