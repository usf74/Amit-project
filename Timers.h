/*
 * Timers.h
 *
 * Created: 10/27/2022 9:34:58 PM
 *  Author: AMIT
 */ 


#ifndef TIMERS_H_
#define TIMERS_H_

#include "Timers_CFG.h"
/************************************************************************/
/*								TIMER 0                                 */
/************************************************************************/
// Timer0 Modes
#define T0_OVF						0
#define T0_P_PWM					1
#define T0_CTC						2
#define T0_F_PWM					3

// Timer0 CLKs
#define T0_NO_CLK					0
#define T0_1						1
#define T0_8						2
#define T0_64						3
#define T0_256						4
#define T0_1024						5

// Timer0 Prescalers
#define T0_Pre_1					1
#define T0_Pre_8					8
#define T0_Pre_64					64
#define T0_Pre_256					256
#define T0_Pre_1024					1024

/************************************************************************/
/*								TIMER 2                                 */
/************************************************************************/
// Timer2 Modes
#define T2_OVF						0
#define T2_P_PWM					1
#define T2_CTC						2
#define T2_F_PWM					3

// Timer2 CLKs
#define T2_NO_CLK					0
#define T2_1						1
#define T2_8						2
#define T2_32						3
#define T2_64						4
#define T2_128						5
#define T2_256						6
#define T2_1024						7

// Timer2 Prescalers
#define T2_Pre_1					1
#define T2_Pre_8					8
#define T2_Pre_32					32
#define T2_Pre_64					64
#define T2_Pre_128					128
#define T2_Pre_256					256
#define T2_Pre_1024					1024

// Timer0 Functions
void T0_Init(void);
void T0_Delay(Uint32 delay_ms);
void T0_Start(void);
void T0_Stop(void);


// Timer2 Functions
void T2_Init(void);
void T2_Delay(Uint32 delay_ms);
void T2_Start(void);
void T2_Stop(void);






#endif /* TIMERS_H_ */