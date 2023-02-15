#include "Relay.h"

//Relay0 Functions
void Relay0_Init(void)
{
	DIO_SetPin_Dir(Relay0_Port, Relay0_PIN, DIO_PIN_OUT);
}
void Relay0_ON(void)
{
	DIO_SetPin_Val(Relay0_Port, Relay0_PIN, DIO_PIN_ON);
}
void Relay0_OFF(void)
{
	DIO_SetPin_Val(Relay0_Port, Relay0_PIN, DIO_PIN_OFF);
}
void Relay0_Toggle(void)
{
	DIO_TogglePin(Relay0_Port, Relay0_PIN);
}
//Relay1 Functions
void Relay1_Init(void)
{
	DIO_SetPin_Dir(Relay1_Port, Relay1_PIN, DIO_PIN_OUT);
}
void Relay1_ON(void)
{
	DIO_SetPin_Val(Relay1_Port, Relay1_PIN, DIO_PIN_ON);
}
void Relay1_OFF(void)
{
	DIO_SetPin_Val(Relay1_Port, Relay1_PIN, DIO_PIN_OFF);
}
void Relay1_Toggle(void)
{
	DIO_TogglePin(Relay1_Port, Relay1_PIN);
}