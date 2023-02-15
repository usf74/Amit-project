



#include "EEPROM.h"



void EEPROM_INIT(void)
{
    EECR |= EEPROM_INT<<EERIE;	//Interrupt setting
}

void EEPROM_WriteByte(Uint16 Addr , Uint8 Data)
{
    while (EECR & 1<<EEWE);    // To Await previous write operation finish
    // Write data and address registers
    EEDR=Data;
    EARL=(Uint8)Addr;
    EARH=(Uint8)(Addr>>8);
    // Start Write
    EECR |= (1<<EEMWE);
    EECR |= (1<<EEWE);
}
Uint8  EEPROM_ReadByte(Uint16 Addr)
{
    EARL=(Uint8)Addr;
    EARH=(Uint8)(Addr>>8);
    EECR |= (1<<EERE);
    return EEDR;
}
