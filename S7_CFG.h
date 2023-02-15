
#ifndef S7_CFG_H_
#define S7_CFG_H_

#include "DIO.h"

// S7 Ports
#define S7_Data_Port		DIO_PORTC
#define S7_Data_Bus			PORTC
#define S7_Control_Port		DIO_PORTD
#define S7_DP_Port			DIO_PORTD	//Dot point

// S7 Data Pins
#define S7_Data_PIN0		DIO_PIN_0
#define S7_Data_PIN1		DIO_PIN_1
#define S7_Data_PIN2		DIO_PIN_2
#define S7_Data_PIN3		DIO_PIN_3
#define S7_Data_PIN4		DIO_PIN_4
#define S7_Data_PIN5		DIO_PIN_5
#define S7_Data_PIN6		DIO_PIN_6

// S7 Control Pins
#define S7_E1_PIN			DIO_PIN_1
#define S7_E2_PIN			DIO_PIN_0
#define S7_DP_PIN			DIO_PIN_6









#endif /* S7_CFG_H_ */