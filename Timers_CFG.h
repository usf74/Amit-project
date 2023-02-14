

#ifndef TIMERS_CFG_H_
#define TIMERS_CFG_H_

#include "DIO.h"
#include "Interrupts.h"

/************************************************************************/
/*								TIMER 0                                 */
/************************************************************************/

// Oscillator Frequency
#define F_OSC_MHZ			16

// Timer0 Mode
#define Timer0_Mode			T0_OVF

// Timer0 CLK
#define Timer0_CLK			T0_1024

// Timer0 Prescaller
#define Timer0_PreSC		T0_Pre_1024


/************************************************************************/
/*								TIMER 2                                 */
/************************************************************************/

// Timer2 Mode
#define Timer2_Mode			T2_CTC

// Timer2 CLK
#define Timer2_CLK			T2_1024

// Timer2 Prescaller
#define Timer2_PreSC		T2_Pre_1024

#endif /* TIMERS_CFG_H_ */