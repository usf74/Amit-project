#ifndef EEPROM_H_
#define EEPROM_H_

#include "std.h"
#include "MCU.h"
#include "Interrupts.h"

#define EERE 0
#define EEMWE 2
#define EEWE 1
#define EERIE 4

void EEPROM_INIT(void);
void EEPROM_WriteByte(Uint16 Addr , Uint8 Data);
Uint8  EEPROM_ReadByte(Uint16 Addr);
#endif

