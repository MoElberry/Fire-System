

#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "ADC_Interface.h"

static u8 ADC_BusyFlag;
void ADC_Init(ADC_VoltRef_type vref,ADC_Prescaler_type scaler){
	/*v ref */
	switch(vref){
		case VREF_AREF:
		    CLR_BIT(ADMUX,REFS0);
		    CLR_BIT(ADMUX,REFS1);
		    break;
		case VREF_AVCC:
		    SET_BIT(ADMUX,REFS0);
		    CLR_BIT(ADMUX,REFS1);
		    break;
		case VREF_256V:
		    SET_BIT(ADMUX,REFS0);
		    SET_BIT(ADMUX,REFS1);
		    break;   
      }
	/*prescaler*/
	ADCSRA&=0xf8; 
	scaler&=0x07; 
	ADCSRA=ADCSRA|scaler;
	
	/*enable_ADC*/
	SET_BIT(ADCSRA,ADEN);
	
}


u16 ADC_Read(ADC_Channel_type CH){
	u16  H=0,L=0,result;
	
	/*set channel mux */
	 ADMUX &=0xE0;  //11100000
	 ADMUX=ADMUX|CH;
	 
	
	/*start conversion */
	SET_BIT(ADCSRA,ADSC);
	
	/*wait ADC finish */
	
  //	_delay_ms(1);
     while(READ_BIT(ADCSRA,ADSC));
	
	/*get read */
	
	CLR_BIT(ADMUX,ADLAR);
	L=ADCL;    
	H=ADCH<<8;
	result=H|L;
	/* mood 2   ADL=1*/
	/*  L=ADCL>>6;
	    H=ADCH<<2;
		result=H|L;
	*/
	 return result;
	
}

/*    return m volt        */
u16 ADC_VoltRead(ADC_Channel_type CH){
	
	u16 adc,volte;
	adc=ADC_Read(CH);
	volte=((u32)adc*5000)/1024;    // return mv 
	return volte;
	
	
}

void ADC_StartConversion(ADC_Channel_type CH){
	
	if (ADC_BusyFlag==0)
	{
		
		/*set channel mux */
		ADMUX &=0xE0;  //11100000
		ADMUX=ADMUX|CH;
		
		
		/*start conversion */
		SET_BIT(ADCSRA,ADSC);
		ADC_BusyFlag=1;
	}
}
u8 ADC_GetReadPerodic(u16 *pdata){
	if(!READ_BIT(ADCSRA,ADSC)){
		
		*pdata = ADC;
		ADC_BusyFlag=0;
	    return 1;
	}
	    return 0;
}

u16 ADC_GetRead(void){
	
	  while(READ_BIT(ADCSRA,ADSC));
	  return ADC;
	
}



u16 ADC_GetReaNoblock(void){
	
	return ADC ;
}