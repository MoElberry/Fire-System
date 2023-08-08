

#include "StdTypes.h"
#include "ADC_Interface.h"
#include "Sensors_Cfg.h"
#include "Sensors_Interface.h"


u16 TEMP_Read(void){
	u16 volt;
	volt=ADC_VoltRead(LM35_CH);
	u16 temp;
	 temp=volt;
	 return temp;
	
}

u16 PRESURE_Read(void){
	u16 adc;
	adc=ADC_Read(MPX_CH);
	u16 presure;
	presure=((((u32)1000*(adc-55))+460)/921)+150;
	return presure;
	
}

/*
u8 POT_Read(void){
	// ????? ?????? ??????? ???????? ????????
}
*/