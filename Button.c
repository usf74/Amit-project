/*
 * Button.c
 *
 * Created: 10/6/2022 7:24:07 PM
 *  Author: AMIT
 */ 

#include "Button.h"

//Button0 Functions
void Button0_Init(void)
{
	DIO_SetPin_Dir(Button0_Port, Button0_PIN, DIO_PIN_IN);
}
Uint8 Button0_GetVal(void)
{
	Uint8 val = 0;
	val = DIO_GetPin_val(Button0_Port, Button0_PIN);
	while(DIO_GetPin_val(Button0_Port, Button0_PIN));
	return val;		
}

//Button1 Functions
void Button1_Init(void)
{
	DIO_SetPin_Dir(Button1_Port, Button1_PIN, DIO_PIN_IN);
}
Uint8 Button1_GetVal(void)
{
	Uint8 val = 0;
	val = DIO_GetPin_val(Button1_Port, Button1_PIN);
	while(DIO_GetPin_val(Button1_Port, Button1_PIN));
	return val;
}

//Button2 Functions
void Button2_Init(void)
{
	DIO_SetPin_Dir(Button2_Port, Button2_PIN, DIO_PIN_IN);
}
Uint8 Button2_GetVal(void)
{
	Uint8 val = 0;
	val = DIO_GetPin_val(Button2_Port, Button2_PIN);
	while(DIO_GetPin_val(Button2_Port, Button2_PIN));
	return val;
}



