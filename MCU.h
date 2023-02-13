
#ifndef MCU_H_
#define MCU_H_

#include "std.h"

// ---------------------> DIO <---------------------
#define PORTA	*((volatile Uint8*)(0x3B))
#define DDRA	*((volatile Uint8*)(0x3A))
#define PINA	*((volatile Uint8*)(0x39))

#define PORTB	*((volatile Uint8*)(0x38))
#define DDRB	*((volatile Uint8*)(0x37))
#define PINB	*((volatile Uint8*)(0x36))

#define PORTC	*((volatile Uint8*)(0x35))
#define DDRC	*((volatile Uint8*)(0x34))
#define PINC	*((volatile Uint8*)(0x33))

#define PORTD	*((volatile Uint8*)(0x32))
#define DDRD	*((volatile Uint8*)(0x31))
#define PIND	*((volatile Uint8*)(0x30))

// ---------------------> EXT INT <---------------------
#define SREG	*((volatile Uint8*)(0x5F))
#define GICR	*((volatile Uint8*)(0x5B))
#define GIFR	*((volatile Uint8*)(0x5A))
#define MCUCR	*((volatile Uint8*)(0x55))
#define MCUCSR	*((volatile Uint8*)(0x54))

// ---------------------> ADC <---------------------
#define SFIOR	*((volatile Uint8*)(0x50))
#define ADMUX	*((volatile Uint8*)(0x27))
#define ADCSRA	*((volatile Uint8*)(0x26))
#define ADCH	*((volatile Uint8*)(0x25))
#define ADCL	*((volatile Uint8*)(0x24))
#define ADCR	*((volatile Uint16*)(0x24))

// ---------------------> TIMER0 <---------------------
#define OCR0	*((volatile Uint8*)(0x5C))
#define TIMSK	*((volatile Uint8*)(0x59))
#define TIFR	*((volatile Uint8*)(0x58))
#define TCCR0	*((volatile Uint8*)(0x53))
#define TCNT0	*((volatile Uint8*)(0x52))

// ---------------------> TIMER2 <---------------------
#define TCCR2	*((volatile Uint8*)(0x45))
#define TCNT2	*((volatile Uint8*)(0x44))
#define OCR2	*((volatile Uint8*)(0x43))

// ---------------------> EEPROM <---------------------
#define EARL    *((volatile Uint8*)(0x3E))
#define EARH    *((volatile Uint8*)(0x3F))
#define EEAR    *((volatile Uint16*)(0x3E))
#define EEDR    *((volatile Uint8*)(0x3D))
#define EECR    *((volatile Uint8*)(0x3C))








#endif /* MCU_H_ */