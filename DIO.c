
#include "DIO.h"

void DIO_SetPin_Dir(Uint8 port, Uint8 pin, Uint8 dir)
{
	switch (dir)
	{
		case DIO_PIN_IN:
		switch(port)
		{
			case DIO_PORTA:
			Clear_Bit(DDRA, pin);
			break;
			
			case DIO_PORTB:
			Clear_Bit(DDRB, pin);
			break;
			
			case DIO_PORTC:
			Clear_Bit(DDRC, pin);
			break;
			
			case DIO_PORTD:
			Clear_Bit(DDRD, pin);
			break;
			
			default:
			break;	
		}
		break;
		
		case DIO_PIN_OUT:
		switch(port)
		{
			case DIO_PORTA:
			Set_Bit(DDRA, pin);
			break;
			
			case DIO_PORTB:
			Set_Bit(DDRB, pin);
			break;
			
			case DIO_PORTC:
			Set_Bit(DDRC, pin);
			break;
			
			case DIO_PORTD:
			Set_Bit(DDRD, pin);
			break;
			
			default:
			break;
		}
		break;
		
		default:
		break;
	}
}

void DIO_SetPin_Val(Uint8 port, Uint8 pin, Uint8 val)
{
	switch (val)
	{
		case DIO_PIN_OFF:
		switch(port)
		{
			case DIO_PORTA:
			Clear_Bit(PORTA, pin);
			break;
			
			case DIO_PORTB:
			Clear_Bit(PORTB, pin);
			break;
			
			case DIO_PORTC:
			Clear_Bit(PORTC, pin);
			break;
			
			case DIO_PORTD:
			Clear_Bit(PORTD, pin);
			break;
			
			default:
			break;
		}
		break;
		
		case DIO_PIN_ON:
		switch(port)
		{
			case DIO_PORTA:
			Set_Bit(PORTA, pin);
			break;
			
			case DIO_PORTB:
			Set_Bit(PORTB, pin);
			break;
			
			case DIO_PORTC:
			Set_Bit(PORTC, pin);
			break;
			
			case DIO_PORTD:
			Set_Bit(PORTD, pin);
			break;
			
			default:
			break;
		}
		break;
		
		default:
		break;
	}		
}

void DIO_TogglePin(Uint8 port, Uint8 pin)
{
	switch(port)
	{
		case DIO_PORTA:
		Toggle_Bit(PORTA, pin);
		break;
		
		case DIO_PORTB:
		Toggle_Bit(PORTB, pin);
		break;
		
		case DIO_PORTC:
		Toggle_Bit(PORTC, pin);
		break;
		
		case DIO_PORTD:
		Toggle_Bit(PORTD, pin);
		break;
		
		default:
		break;
	}
	
}

Uint8 DIO_GetPin_val(Uint8 port, Uint8 pin)
{
	Uint8 val = 0;
	switch(port)
	{
		case DIO_PORTA:
		val = Get_Bit(PINA, pin);
		break;
		
		case DIO_PORTB:
		val = Get_Bit(PINB, pin);
		break;
		
		case DIO_PORTC:
		val = Get_Bit(PINC, pin);
		break;
		
		case DIO_PORTD:
		val = Get_Bit(PIND, pin);
		break;
		
		default:
		break;
	}
	return val;
}

void DIO_SetPullUp_val(Uint8 port, Uint8 pin, Uint8 val)
{
	switch(val)
	{
		case DIO_PULLUP_OFF:
		switch(port)
		{
			case DIO_PORTA:
			Clear_Bit(PORTA, pin);
			break;
			
			case DIO_PORTB:
			Clear_Bit(PORTB, pin);
			break;
			
			case DIO_PORTC:
			Clear_Bit(PORTC, pin);
			break;
			
			case DIO_PORTD:
			Clear_Bit(PORTD, pin);
			break;
			
			default:
			break;
		}
		break;
		
		case DIO_PULLUP_ON:
		switch(port)
		{
			case DIO_PORTA:
			Set_Bit(PORTA, pin);
			break;
			
			case DIO_PORTB:
			Set_Bit(PORTB, pin);
			break;
			
			case DIO_PORTC:
			Set_Bit(PORTC, pin);
			break;
			
			case DIO_PORTD:
			Set_Bit(PORTD, pin);
			break;
			
			default:
			break;
		}
		break;
		
		default:
		break;
	}
}