
#ifndef Heating_Element_H_
#define Heating_Element_H_

#include "Relay.h"

#define Cooling_Element_Init() (Relay0_Init())
#define Cooling_Element_ON()  (Relay0_ON())
#define Cooling_Element_OFF() (Relay0_OFF())

#endif