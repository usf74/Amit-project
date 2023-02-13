#include "std.h"
#include "MCU.h"
#include "Interrupts.h"
#include "ADC.h"

#include "Temp_Sensor_CFG.h"

#define Temp_Sensor_Init() (ADC_Init())
#define Temp_Sensor_Read() (Uint8)((ADC_Read(Temp_sensor_PIN))*1024/0.01)   //Return temperature in degrees