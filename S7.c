
#include "S7.h"
#define F_CPU 16000000
#include <util/delay.h>

// S7 Functions
void S7_Init(void)
{
	// S7 Data Pins Direction
	DIO_SetPin_Dir(S7_Data_Port, S7_Data_PIN0, DIO_PIN_OUT);
	DIO_SetPin_Dir(S7_Data_Port, S7_Data_PIN1, DIO_PIN_OUT);
	DIO_SetPin_Dir(S7_Data_Port, S7_Data_PIN2, DIO_PIN_OUT);
	DIO_SetPin_Dir(S7_Data_Port, S7_Data_PIN3, DIO_PIN_OUT);
	
	// S7 Data Pins Direction
	DIO_SetPin_Dir(S7_Control_Port, S7_E1_PIN, DIO_PIN_OUT);
	DIO_SetPin_Dir(S7_Control_Port, S7_E2_PIN, DIO_PIN_OUT);
	
	// S7 DP Pin Direction
	DIO_SetPin_Dir(S7_DP_Port, S7_DP_PIN, DIO_PIN_OUT);
	
	// S7 Data Pins Value
	DIO_SetPin_Val(S7_Data_Port, S7_Data_PIN0, DIO_PIN_OFF);
	DIO_SetPin_Val(S7_Data_Port, S7_Data_PIN1, DIO_PIN_OFF);
	DIO_SetPin_Val(S7_Data_Port, S7_Data_PIN2, DIO_PIN_OFF);
	DIO_SetPin_Val(S7_Data_Port, S7_Data_PIN3, DIO_PIN_OFF);
	
	// S7 Enable & DP Pins Value
	DIO_SetPin_Val(S7_Control_Port, S7_E1_PIN, DIO_PIN_OFF);
	DIO_SetPin_Val(S7_Control_Port, S7_E2_PIN, DIO_PIN_OFF);
	DIO_SetPin_Val(S7_DP_Port, S7_DP_PIN, DIO_PIN_OFF);
	
}
void S7_Display(Uint8 data)
{
	Uint8 Ones = 0, Tens = 0;
	data = (data >= 0) && (data < 100) ? data : 0;
	Ones = data % 10;
	Tens = data / 10;
	S7_Data_Bus  = (Ones << 4) | (S7_Data_Bus & 0X0F);
	DIO_SetPin_Val(S7_Control_Port, S7_E1_PIN, DIO_PIN_OFF);
	DIO_SetPin_Val(S7_Control_Port, S7_E2_PIN, DIO_PIN_ON);
	_delay_ms(5);
	S7_Data_Bus  = (Tens << 4) | (S7_Data_Bus & 0X0F);
	DIO_SetPin_Val(S7_Control_Port, S7_E1_PIN, DIO_PIN_ON);
	DIO_SetPin_Val(S7_Control_Port, S7_E2_PIN, DIO_PIN_OFF);
	_delay_ms(5);
}

void S7_Turn_Off()
{
	DIO_SetPin_Val(S7_Control_Port, S7_E1_PIN, DIO_PIN_OFF);
	DIO_SetPin_Val(S7_Control_Port, S7_E2_PIN, DIO_PIN_OFF);
}
void S7_Turn_ON()
{
	DIO_SetPin_Val(S7_Control_Port, S7_E1_PIN, DIO_PIN_ON);
	DIO_SetPin_Val(S7_Control_Port, S7_E2_PIN, DIO_PIN_ON);
}
void S7_Toggle()
{
	DIO_TogglePin(S7_Control_Port, S7_E1_PIN);
	DIO_TogglePin(S7_Control_Port, S7_E2_PIN);
}