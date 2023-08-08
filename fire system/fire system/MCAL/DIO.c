
#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "DIO_Cfg.h"
#include "DIO_Inteface.h"
#include "DIO_Private.h"


void DIO_Initpin2(DIO_Port_type port,u8 pin_num,DIO_PinStatus_type status) {
	
	switch(status){
		case OUTPUT:
		switch(port){
			case PA:
			SET_BIT(DDRA,pin_num);
			CLR_BIT(PORTA,pin_num);
			break;
			case PB:
			SET_BIT(DDRB,pin_num);
			CLR_BIT(PORTB,pin_num);
			break;
			case PC:
			SET_BIT(DDRC,pin_num);
			CLR_BIT(PORTC,pin_num);
			break;
			case PD:
			SET_BIT(DDRD,pin_num);
			CLR_BIT(PORTD,pin_num);
			break;
		}
		break;
		case INFREE:
		 switch(port){
			 case PA:
			 CLR_BIT(DDRA,pin_num);
			 CLR_BIT(PORTA,pin_num);
			 break;
			 case PB:
			 CLR_BIT(DDRB,pin_num);
			 CLR_BIT(PORTB,pin_num);
			 break;
			 case PC:
			 CLR_BIT(DDRC,pin_num);
			 CLR_BIT(PORTC,pin_num);
			 break;
			 case PD:
			 CLR_BIT(DDRD,pin_num);
			 CLR_BIT(PORTD,pin_num);
			 break;
		 }
		 break;
		case INPULL:
		   switch(port){
			   case PA:
			   CLR_BIT(DDRA,pin_num);
			   SET_BIT(PORTA,pin_num);
			   break;
			   case PB:
			   CLR_BIT(DDRB,pin_num);
			   SET_BIT(PORTB,pin_num);
			   break;
			   case PC:
			   CLR_BIT(DDRC,pin_num);
			   SET_BIT(PORTC,pin_num);
			   break;
			   case PD:
			   CLR_BIT(DDRD,pin_num);
			   SET_BIT(PORTD,pin_num);
			   break;
		   }
		   break;
	}
	
}


static void DIO_Initpin(DIO_Pin_type pin,DIO_PinStatus_type status){
	DIO_Port_type port=pin/8;
	u8 pin_num=pin%8;
	switch(status){
		case OUTPUT:
		switch(port){
			case PA:
			SET_BIT(DDRA,pin_num);
			CLR_BIT(PORTA,pin_num);
			break;
			case PB:
			SET_BIT(DDRB,pin_num);
			CLR_BIT(PORTB,pin_num);
			break;
			case PC:
			SET_BIT(DDRC,pin_num);
			CLR_BIT(PORTC,pin_num);
			break;
			case PD:
			SET_BIT(DDRD,pin_num);
			CLR_BIT(PORTD,pin_num);
			break;
		}
		break;
		case INFREE:
		switch(port){
			case PA:
			CLR_BIT(DDRA,pin_num);
			CLR_BIT(PORTA,pin_num);
			break;
			case PB:
			CLR_BIT(DDRB,pin_num);
			CLR_BIT(PORTB,pin_num);
			break;
			case PC:
			CLR_BIT(DDRC,pin_num);
			CLR_BIT(PORTC,pin_num);
			break;
			case PD:
			CLR_BIT(DDRD,pin_num);
			CLR_BIT(PORTD,pin_num);
			break;
		}
		break;
		case INPULL:
		switch(port){
			case PA:
			CLR_BIT(DDRA,pin_num);
			SET_BIT(PORTA,pin_num);
			break;
			case PB:
			CLR_BIT(DDRB,pin_num);
			SET_BIT(PORTB,pin_num);
			break;
			case PC:
			CLR_BIT(DDRC,pin_num);
			SET_BIT(PORTC,pin_num);
			break;
			case PD:
			CLR_BIT(DDRD,pin_num);
			SET_BIT(PORTD,pin_num);
			break;
		}
		break;
	}
	
}

void DIO_WritePin(DIO_Pin_type pin,DIO_PinVoltage_type volte){
	
	DIO_Port_type port=pin/8;
	u8 pin_num=pin%8;
	if (volte==HIGH)
	{
		switch(port){
			case PA:
			SET_BIT(PORTA,pin_num);
			break;
			case PB:
			SET_BIT(PORTB,pin_num);
			break;
			case PC:
			SET_BIT(PORTC,pin_num);
			break;
			case PD:
			SET_BIT(PORTD,pin_num);
			break;
			
		}
	}else{
		
			switch(port){
				case PA:
				CLR_BIT(PORTA,pin_num);
				break;
				case PB:
				CLR_BIT(PORTB,pin_num);
				break;
				case PC:
				CLR_BIT(PORTC,pin_num);
				break;
				case PD:
				CLR_BIT(PORTD,pin_num);
				break;
		
		
	      }
       }
	}
DIO_PinVoltage_type DIO_ReadPin(DIO_Pin_type pin){
	DIO_Port_type port=pin/8;
	u8 pin_num=pin%8;
	DIO_PinVoltage_type volte=LOW;
	
	switch(port){
		case PA:
		volte=READ_BIT(PINA,pin_num);
		break;
		case PB:
		volte=READ_BIT(PINB,pin_num);
		break;
		case PC:
		volte=READ_BIT(PINC,pin_num);
		break;
		case PD:
		volte=READ_BIT(PIND,pin_num);
		break;
	
   }
       return volte;
}
	

void DIO_WritePort(DIO_Port_type port,u8 data){

    switch(port){
		case PA:
		    PORTA=data;
		    break;
	    case PB:
		  	PORTB=data;
		  	break;
		case PC:
			PORTC=data;
			break;
		case PD:
			PORTD=data;
		 	break;
		
	}
}


u8 DIO_ReadPort(DIO_Port_type port){
	u8 data=0;
	switch(port){
		case PA:
		     data=PINA;
		     break;
		case PB:
		     data=PINB;
		     break;
		case PC:
		     data=PINC;
		     break;
		case PD:
		     data=PIND; 
		     break;
		
	}
	return data;
}


void DIO_Init(void){

DIO_Pin_type i;
for (i=PINA0;i<TOTAL_PINS;i++)
{
	DIO_Initpin(i,DIO_PinsStatusArr[i]);
}

}
void DIO_TogglePin(DIO_Pin_type pin){

	DIO_Port_type port=pin/8;
	u8 pin_num=pin%8;
	
	
	switch(port){
		case PA:
		TOGGLE_BIT(PORTA,pin_num);
		break;
		case PB:
		TOGGLE_BIT(PORTB,pin_num);
		break;
		case PC:
		TOGGLE_BIT(PORTC,pin_num);
		break;
		case PD:
		TOGGLE_BIT(PORTD,pin_num);
		break;
		
	}

}
