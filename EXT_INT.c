
#include "EXT_INT.h"

// EXT INT Functions
void EXT0_INT_Init(void)
{
	// Global Enable/ Disable Interrupt
	SREG = (Global_INT << 7) | (SREG & 0X7F);
	
	// Peripheral Enable/ Disable Interrupt
	GICR = (EXT0_INT << 6) | (GICR & 0XBF);
	
	// EXT0 INT Pin Direction
	DIO_SetPin_Dir(DIO_PORTD, DIO_PIN_2, DIO_PIN_IN);
	
	// EXT0 INT Trigger
	MCUCR = EXT0_INT_Trigger | (MCUCR & 0XFC);
}

void EXT1_INT_Init(void)
{
	// Global Enable/ Disable Interrupt
	SREG = (Global_INT << 7) | (SREG & 0X7F);
	
	// Peripheral Enable/ Disable Interrupt
	GICR = (EXT1_INT << 7) | (GICR & 0X7F);
	
	// EXT1 INT Pin Direction
	DIO_SetPin_Dir(DIO_PORTD, DIO_PIN_3, DIO_PIN_IN);
	
	// EXT1 INT Trigger
	MCUCR = EXT1_INT_Trigger | (MCUCR & 0XF3);
}

void EXT2_INT_Init(void)
{
	// Global Enable/ Disable Interrupt
	SREG = (Global_INT << 7) | (SREG & 0X7F);
	
	// Peripheral Enable/ Disable Interrupt
	GICR = (EXT2_INT << 5) | (GICR & 0XDF);
	
	// EXT2 INT Pin Direction
	DIO_SetPin_Dir(DIO_PORTB, DIO_PIN_2, DIO_PIN_IN);
	
	// EXT2 INT Trigger
	MCUCSR = EXT2_INT_Trigger | (MCUCSR & 0XBF);
}

