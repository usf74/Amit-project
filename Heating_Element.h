
#ifndef HEATING_ELEMENT_H_
#define HEATING_ELEMENT_H_

#include "Relay.h"

#define Heating_Element_Init() (Relay1_Init())
#define Heating_Element_ON()  (Relay1_ON())
#define Heating_Element_OFF() (Relay1_OFF())

#endif