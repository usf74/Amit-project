
#ifndef EXT_INT_H_
#define EXT_INT_H_

#include "EXT_INT_CFG.h"

// EXT0 INT Triggers
#define EXT0_Low_Level					0
#define EXT0_Any_Logical_Change			1
#define EXT0_Falling_Edge				2
#define EXT0_Rising_Edge				3

#define EXT2_Falling_Edge				0
#define EXT2_Rising_Edge				1


// EXT INT Functions
void EXT0_INT_Init(void);
void EXT1_INT_Init(void);
void EXT2_INT_Init(void);


#endif /* EXT_INT_H_ */