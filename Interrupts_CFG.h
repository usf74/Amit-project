

#ifndef INTERRUPTS_CFG_H_
#define INTERRUPTS_CFG_H_

// ------------------> Global INT <--------------------- 
#define Global_INT				INT_Enable

// ------------------> EXT INT <---------------------
#define EXT0_INT				INT_Enable
#define EXT1_INT				INT_Enable
#define EXT2_INT				INT_Enable

// ------------------> ADC INT <---------------------
#define ADC_INT					INT_Disable

// ------------------> TIMER0 INT <---------------------
#define T0_OCF_INT				INT_Enable
#define T0_OVF_INT				INT_Disable

// ------------------> TIMER2 INT <---------------------
#define T2_OCF_INT				INT_Enable
#define T2_OVF_INT				INT_Disable

// ------------------> EEPROM INT <---------------------
#define EEPROM_INT INT_Disable 

#endif /* INTERRUPTS_CFG_H_ */