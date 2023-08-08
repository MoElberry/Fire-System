
#define KEYPAD_PRG 1

#include "StdTypes.h"
#include "DIO_Inteface.h"
#include "KeyPad_Interface.h"

#include "KeyPad_Cfg.h" 


void KEYPAD_Init(void){
	
	for(u8 r=0;r<ROWS;r++){
	
	DIO_WritePin(FIRIST_OUTPUT+r,HIGH);
	}
	
}

u8 KEYPAD_GetKey(void){
	
	u8 r ,c ,key=NO_KEY;
	for(r=0;r<ROWS;r++){
		DIO_WritePin(FIRIST_OUTPUT+r,LOW);
		for(c=0;c<COLS;c++){
			if (DIO_ReadPin(FIRIST_INPUT+c)==LOW)
			{
				key=KEYPAD_ARR[r][c];
				_delay_ms(10);
				while(DIO_ReadPin(FIRIST_INPUT+c)==LOW);
				_delay_ms(10);
			}
		}
		     DIO_WritePin(FIRIST_OUTPUT+r,HIGH);
		
	}
	return key;
	
}