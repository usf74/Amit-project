
#include "LED.h"

//LED0 Functions
void LED0_Init(void)
{
	DIO_SetPin_Dir(LED0_Port, LED0_PIN, DIO_PIN_OUT);
}
void LED0_ON(void)
{
	DIO_SetPin_Val(LED0_Port, LED0_PIN, DIO_PIN_ON);
}
void LED0_OFF(void)
{
	DIO_SetPin_Val(LED0_Port, LED0_PIN, DIO_PIN_OFF);
}
void LED0_Toggle(void)
{
	DIO_TogglePin(LED0_Port, LED0_PIN);
}


//LED1 Functions
void LED1_Init(void)
{
	DIO_SetPin_Dir(LED1_Port, LED1_PIN, DIO_PIN_OUT);
}
void LED1_ON(void)
{
	DIO_SetPin_Val(LED1_Port, LED1_PIN, DIO_PIN_ON);
}
void LED1_OFF(void)
{
	DIO_SetPin_Val(LED1_Port, LED1_PIN, DIO_PIN_OFF);
}
void LED1_Toggle(void)
{
	DIO_TogglePin(LED1_Port, LED1_PIN);
}

//LED2 Functions
void LED2_Init(void)
{
	DIO_SetPin_Dir(LED2_Port, LED2_PIN, DIO_PIN_OUT);
}
void LED2_ON(void)
{
	DIO_SetPin_Val(LED2_Port, LED2_PIN, DIO_PIN_ON);
}
void LED2_OFF(void)
{
	DIO_SetPin_Val(LED2_Port, LED2_PIN, DIO_PIN_OFF);
}
void LED2_Toggle(void)
{
	DIO_TogglePin(LED2_Port, LED2_PIN);
}