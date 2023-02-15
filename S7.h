

#ifndef S7_H_
#define S7_H_

#include "S7_CFG.h"



// S7 Functions
void S7_Init(void);
void S7_Display(Uint8 data);
void S7_Turn_Off();
void S7_Turn_ON();
void S7_Toggle();
//Status macros
#define ON 1
#define OFF 0

#endif /* S7_H_ */