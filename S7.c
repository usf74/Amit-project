

#define F_CPU 16000000
#include <util/delay.h>

#include "S7.h"
// S7 Functions
Uint8 Nums[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
void S7_Init(void)
{
	// S7 Data Pins Direction
	DIO_SetPin_Dir(S7_Data_Port, S7_Data_PIN0, DIO_PIN_OUT);
	DIO_SetPin_Dir(S7_Data_Port, S7_Data_PIN1, DIO_PIN_OUT);
	DIO_SetPin_Dir(S7_Data_Port, S7_Data_PIN2, DIO_PIN_OUT);
	DIO_SetPin_Dir(S7_Data_Port, S7_Data_PIN3, DIO_PIN_OUT);
	DIO_SetPin_Dir(S7_Data_Port, S7_Data_PIN4, DIO_PIN_OUT);
	DIO_SetPin_Dir(S7_Data_Port, S7_Data_PIN5, DIO_PIN_OUT);
	DIO_SetPin_Dir(S7_Data_Port, S7_Data_PIN6, DIO_PIN_OUT);
	
	// S7 Data Pins Direction
	DIO_SetPin_Dir(S7_Control_Port, S7_E1_PIN, DIO_PIN_OUT);
	DIO_SetPin_Dir(S7_Control_Port, S7_E2_PIN, DIO_PIN_OUT);
	
	// S7 DP Pin Direction
	DIO_SetPin_Dir(S7_DP_Port, S7_DP_PIN, DIO_PIN_OUT);
	
	// S7 Data Pins Value
	DIO_SetPin_Val(S7_Data_Port, S7_Data_PIN0, DIO_PIN_ON);
	DIO_SetPin_Val(S7_Data_Port, S7_Data_PIN1, DIO_PIN_ON);
	DIO_SetPin_Val(S7_Data_Port, S7_Data_PIN2, DIO_PIN_ON);
	DIO_SetPin_Val(S7_Data_Port, S7_Data_PIN3, DIO_PIN_ON);
	DIO_SetPin_Dir(S7_Data_Port, S7_Data_PIN4, DIO_PIN_ON);
	DIO_SetPin_Dir(S7_Data_Port, S7_Data_PIN5, DIO_PIN_ON);
	DIO_SetPin_Dir(S7_Data_Port, S7_Data_PIN6, DIO_PIN_ON);
	
	// S7 Enable & DP Pins Value
	DIO_SetPin_Val(S7_Control_Port, S7_E1_PIN, DIO_PIN_ON);
	DIO_SetPin_Val(S7_Control_Port, S7_E2_PIN, DIO_PIN_ON);
	DIO_SetPin_Val(S7_DP_Port, S7_DP_PIN, DIO_PIN_ON);
	
}
void S7_Display(Uint8 data)
{
	Uint8 Ones = 0, Tens = 0;
	data = (data >= 0) && (data < 100) ? data : 0;
	Ones = data % 10;
	Tens = data / 10;
	S7_Data_Bus  = Nums[Ones];
	DIO_SetPin_Val(S7_Control_Port, S7_E1_PIN, DIO_PIN_OFF);
	DIO_SetPin_Val(S7_Control_Port, S7_E2_PIN, DIO_PIN_ON);
	_delay_ms(5);
	S7_Data_Bus  = Nums[Tens];
	DIO_SetPin_Val(S7_Control_Port, S7_E1_PIN, DIO_PIN_ON);
	DIO_SetPin_Val(S7_Control_Port, S7_E2_PIN, DIO_PIN_OFF);
	_delay_ms(5);
}

void S7_Turn_Off()
{
	DIO_SetPin_Val(S7_Control_Port, S7_E1_PIN, DIO_PIN_ON);
	DIO_SetPin_Val(S7_Control_Port, S7_E2_PIN, DIO_PIN_ON);
}
void S7_Turn_ON()
{
	DIO_SetPin_Val(S7_Control_Port, S7_E1_PIN, DIO_PIN_OFF);
	DIO_SetPin_Val(S7_Control_Port, S7_E2_PIN, DIO_PIN_OFF);
}
void S7_Toggle()
{
	DIO_TogglePin(S7_Control_Port, S7_E1_PIN);
	DIO_TogglePin(S7_Control_Port, S7_E2_PIN);
}