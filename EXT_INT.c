/*
 * EXT_INT.c
 *
 * Created: 10/18/2022 9:58:44 PM
 *  Author: AMIT
 */ 

#include "EXT_INT.h"

// EXT INT Functions
void EXT0_INT_Init(void)
{
	// Global Enable/ Disable Interrupt
	SREG = (Global_INT << 7) | (SREG & 0X7F);
	
	// Preipheral Enable/ Disable Interrupt
	GICR = (EXT0_INT << 6) | (GICR & 0XBF);
	
	// EXT0 INT Pin Direction
	DIO_SetPin_Dir(DIO_PORTD, DIO_PIN_2, DIO_PIN_IN);
	
	// EXT0 INT Tirgger
	MCUCR = EXT0_INT_Trigger | (MCUCR & 0XFC);
}

