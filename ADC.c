
#include "ADC.h"

void ADC_Init(void)
{
	// Global Enable/ Disable Interrupt
	SREG = (Global_INT << 7) | (SREG & 0X7F);
	
	// Preipheral Enable/ Disable Interrupt
	ADCSRA = (ADC_INT << 3) | (ADCSRA & 0XF7); 
	
	// ADC Voltage Reference / Data Adjust
	ADMUX = (ADC_Volt_Ref << 6) | (ADC_Data_Adjust << 5) | (ADMUX & 0X1F);
	
	// ADC Mode / CLK Source
	ADCSRA = (ADC_Mode << 5) | (ADC_CLK_Source) | (ADCSRA & 0XD8);
	
	// ADC Auto Trigger Mode
	SFIOR = (ADC_AT_Mode << 5) | (SFIOR & 0X1F);
	
	// ADC Enable
	Set_Bit(ADCSRA, 7);
}
Uint16 ADC_Read(Uint8 Channel)
{
	Uint16 Value;	//Uint16 since ADC returns 10 bit values
	// ADC Select Channel
	ADMUX = Channel | (ADMUX & 0XF8);
	
	// ADC Start of Conversion
	Set_Bit(ADCSRA, 6);
	while(!Get_Bit(ADCSRA, 4));
	
	Value = ADCR;
	
	return Value;
}