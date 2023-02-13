/*
 * DIO.h
 *
 * Created: 9/29/2022 10:02:16 PM
 *  Author: AMIT
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "MCU.h"
#include "Bit_Math.h"

/*DIO PORTs*/
#define DIO_PORTA		0
#define DIO_PORTB		1
#define DIO_PORTC		2
#define DIO_PORTD		3

/*DIO Port Pins*/
#define DIO_PIN_0		0
#define DIO_PIN_1		1
#define DIO_PIN_2		2
#define DIO_PIN_3		3
#define DIO_PIN_4		4
#define DIO_PIN_5		5
#define DIO_PIN_6		6
#define DIO_PIN_7		7

/*DIO Pin Directions*/
#define DIO_PIN_IN		0
#define DIO_PIN_OUT		1

/*DIO Pin Values*/
#define DIO_PIN_OFF		0
#define DIO_PIN_ON		1

/*DIO Pin Pull_up val*/
#define DIO_PULLUP_OFF	0
#define DIO_PULLUP_ON	1

void DIO_SetPin_Dir(Uint8 port, Uint8 pin, Uint8 dir);

void DIO_SetPin_Val(Uint8 port, Uint8 pin, Uint8 val);

void DIO_TogglePin(Uint8 port, Uint8 pin);

Uint8 DIO_GetPin_val(Uint8 port, Uint8 pin);

void DIO_SetPullUp_val(Uint8 port, Uint8 pin, Uint8 val);

#endif /* DIO_H_ */