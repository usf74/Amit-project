
#ifndef ADC_H_
#define ADC_H_

#include "ADC_CFG.h"

// ADC Volatage References
#define ADC_VR_AVREF					0
#define ADC_VR_AVCC						1
#define ADC_VR_Reserved					2
#define ADC_VR_Internal_2_56			3

// ADC Data Adjust
#define ADC_Right_Adjust				0
#define ADC_Left_Adjust					1

// ADC CLK Sources
#define ADC_F_2							1
#define ADC_F_4							2
#define ADC_F_8							3
#define ADC_F_16						4
#define ADC_F_32						5
#define ADC_F_64						6
#define ADC_F_128						7

// ADC Mode
#define ADC_Single_Conv_Mode			0
#define ADC_Auto_Trigger_Mode			1

// ADC Auto Tirgger Modes
#define ADC_AT_Free_Running				0
#define ADC_AT_Analog_Comp				1
#define ADC_AT_EXT_INT0					2
#define ADC_AT_Timer0_Comp				3
#define ADC_AT_Timer0_OVF				4
#define ADC_AT_Timer1_Comp				5
#define ADC_AT_Timer1_OVF				6
#define ADC_AT_Timer1_Cap_Event			7

// ADC Pins
#define ADC_PIN0						DIO_PIN_0
#define ADC_PIN1						DIO_PIN_1
#define ADC_PIN2						DIO_PIN_2
#define ADC_PIN3						DIO_PIN_3
#define ADC_PIN4						DIO_PIN_4
#define ADC_PIN5						DIO_PIN_5
#define ADC_PIN6						DIO_PIN_6
#define ADC_PIN7						DIO_PIN_7

// ADC Functions
void ADC_Init(void);
Uint16 ADC_Read(Uint8 Channel);

#endif /* ADC_H_ */