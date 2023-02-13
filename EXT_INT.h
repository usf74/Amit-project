/*
 * EXT_INT.h
 *
 * Created: 10/18/2022 9:59:05 PM
 *  Author: AMIT
 */ 


#ifndef EXT_INT_H_
#define EXT_INT_H_

#include "EXT_INT_CFG.h"

// EXT0 INT Triggers
#define EXT0_Low_Level					0
#define EXT0_Any_Logical_Change			1
#define EXT0_Falling_Edge				2
#define EXT0_Rising_Edge				3

// EXT INT Functions
void EXT0_INT_Init(void);
void EXT1_INT_Init(void);
void EXT2_INT_Init(void);


#endif /* EXT_INT_H_ */