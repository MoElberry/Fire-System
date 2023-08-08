/*
 * EEPROM.c
 *
 * Created: 8/7/2023 6:56:35 PM
 *  Author: Mohamed
 */ 

#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "EEPROM_Interface.h"


void EEPROM_write(u16 uiAddress, u8  ucData)
{
	/* Wait for completion of previous write */
	/* use read bit */
	while(EECR & (1<<EEWE))
	;
	/* Set up address and data registers */
	EEAR = uiAddress;
	EEDR = ucData;
	/* Write logical one to EEMWE */
	EECR |= (1<<EEMWE);
	/* Start eeprom write by setting EEWE */
	EECR |= (1<<EEWE);
}



u8 EEPROM_read(u16 uiAddress)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE))
	;
	/* Set up address register */
	EEAR = uiAddress;
	/* Start eeprom read by writing EERE */
	EECR |= (1<<EERE);
	/* Return data from data register */
	return EEDR;
}