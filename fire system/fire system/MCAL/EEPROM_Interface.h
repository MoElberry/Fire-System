/*
 * EEPROM_Interface.h
 *
 * Created: 8/7/2023 8:59:56 PM
 *  Author: Mohamed
 */ 


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_write(u16 uiAddress, u8  ucData);

u8 EEPROM_read(u16 uiAddress);


#endif /* EEPROM_INTERFACE_H_ */