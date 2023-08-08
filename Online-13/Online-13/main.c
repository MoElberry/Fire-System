

#define INTERPOLATION  1
#include "MemMap.h"
#include "StdTypes.h"
#include "Utils.h"


#include "DIO_Inteface.h"
#include "MOTOR_Interface.h"
#include "KeyPad_Interface.h"
#include "LCD_Interface.h"
#include "KeyPad_Cfg.h"
#include "ADC_Interface.h"
#include "Sensors_Interface.h"
#include "EX_Interrupt_Interface.h"
#include "Timers.h"
#include "Timers_Services.h"
#include "EEPROM_Interface.h"



typedef enum{
	FINE,
	HEAT,
	FIRE
}System_State_type;

u8 password=123;

int main(void)
{
	u8 k;
	u16 num=0;
      DIO_Init();
	  MOTOR_Init();
	  LCD_Init();
	  KEYPAD_Init();
	  
    ADC_Init(VREF_AVCC,ADC_SCALER_64);

	 u8 flag=0;
	
	 System_State_type state=FINE;
	 u8 temp;
	 u8 Smoke;
    while(1){
		temp=ADC_Read(CH_1);
		if (temp<=100)
		{
			state=FINE;
		}else if(temp>100 && Smoke<90){
			state=HEAT;
		}else if(temp>100 && Smoke>90){
		    state=FIRE;
	    }
		
		
		
		if (state==FINE)
		{
			 /** print state on lcd */
			 
			 LCD_GoTo(0,5);
			 LCD_WriteString("FINE");
			 /** print temp degree on lcd */
			 LCD_GoTo(1,0);
			 LCD_WriteString("H:");
			 
			 LCD_GoTo(1,2);
			 temp=ADC_Read(CH_1);
			 LCD_WriteNumber(temp);
			 LCD_WriteString("  ");
			 /* tern on led Green*/
			DIO_WritePin(PINC0,HIGH);
			
			/* tern off yellow and red*/
		  //  DIO_WritePin(PINC1,LOW);
			DIO_WritePin(PINC2,LOW);
			
	}else if (state==HEAT)
	 {
		 /** print state on lcd */
		 
		LCD_GoTo(0,5);
		LCD_WriteString("HEAT");
		/** print temp degree on lcd */
		LCD_GoTo(1,0);
		LCD_WriteString("H:");
		
		LCD_GoTo(1,2);
		temp=ADC_Read(CH_1);
		LCD_WriteNumber(temp);
		LCD_WriteString("  ");
		/* tern on led yellow*/
		DIO_WritePin(PINC2,HIGH);
		
		/* tern off green and red*/
		DIO_WritePin(PINC0,LOW);
	//	DIO_WritePin(PINC1,LOW);
		
		/** print smoke degree on lcd */
		LCD_GoTo(1,9);
		LCD_WriteString("S:");
		LCD_GoTo(1,11);
		Smoke=ADC_Read(CH_2);
		LCD_WriteNumber(Smoke);
		LCD_WriteString("  ");
	}
		 else if (state==FIRE)
		 {
			 flag=1;
			  /**********  Turen on motor **********/
			  MOTOR_CW(M1);
			 
			  /*********** tern on  red led*********/
			  DIO_WritePin(PINC1,HIGH);
			  
			  /* tern off green and yellow*/
			  DIO_WritePin(PINC0,LOW);
			  DIO_WritePin(PINC2,LOW);
			  
			  
			  /** print state on lcd */
			  
			  LCD_GoTo(0,5);
			  LCD_WriteString("FIRE");
			  /** print temp degree on lcd */
			  LCD_GoTo(1,0);
			  LCD_WriteString("H:");
			  
			  LCD_GoTo(1,2);
			  temp=ADC_Read(CH_1);
			  LCD_WriteNumber(temp);
			  LCD_WriteString("  ");
			  
			  
			  /** print smoke degree on lcd */
			  LCD_GoTo(1,9);
			  LCD_WriteString("S:");
			  LCD_GoTo(1,11);
			  Smoke=ADC_Read(CH_2);
			  LCD_WriteNumber(Smoke);
			  LCD_WriteString("  ");
			  
			  _delay_ms(2000);
			  
			   LCD_GoTo(0,0);
			   LCD_WriteString("enter password to stop ");
			  _delay_ms(1000);
			
			  
		 }   if (flag==1){
			  u8 i=0;
				 k=KEYPAD_GetKey();
				 if (k!=NO_KEY)
					 {   
						  if(k>='0'&&k<='9'){
							
						    num=num*10+(k-'0');
							LCD_GoTo(0,i);
							LCD_WriteNumber(num);
								  
							 }
						   i++;
				        	if(k=='='){
							      if (num==password)
							      {
						 
								 MOTOR_STOP(M1);  // motor off
								 DIO_WritePin(PINC1,LOW);  // turn off red led 
								LCD_GoTo(0,0);
								LCD_WriteString("                             ");
								_delay_ms(3000);
								 num=0;
								 flag=0;
							     }
							     else
							     {
								     num=0;
							      }
					            }		
			            }					 
	             }
		
	   }  			
	}








/*********************************************from DIO To TIMERS **************************/
/*

void f1(void){
	DIO_TogglePin(PINC0);
}
int main(void)
{
	DIO_Init();
	LCD_Init();
	EXI_Init();
	ADC_Init(VREF_AVCC,ADC_SCALER_64);
	GLOBAL_ENABLE();
	EXI_TriggerEdge(EX_INT0,FALLING_EDGE);
	EXI_SetCallBack(EX_INT0,f1);
	//EXI_Enable(EX_INT0);
	
	TCCR0=0x02; // prescaller 8  , normal mode on 
	//OCR0=99;
	SET_BIT(TIMSK,0); // enable ov interrupt
	SET_BIT(TIMSK,1); // enable cu interrupt
	
	SET_BIT(TCCR0,COM01); // CLEAR OC0 on compare match  SET OC0 at TOP 
	SET_BIT(TCCR0,COM00);
	
	SET_BIT(TCCR0,WGM01); // FAST MODE
	SET_BIT(TCCR0,WGM00); // 
    LCD_WriteString("OCR0");
	//OCR0=49;
	u8 x =0;
	u16 adc;
	while(1){
    
       adc=ADC_Read(CH_0);
      OCR0=255-(adc/4);
	  
	  		
	}
	
	
}

ISR(TIMER0_OVF_vect){
	DIO_TogglePin(PINC0);
}

ISR(TIMER0_OC_vect){
	DIO_TogglePin(PINC1);
}


*/
/*
ISR(TIMER0_OVF_vect){
	
	static u8 flag=0;
	
	
	
	if (flag==0)
	{
		DIO_WritePin(PINC0,HIGH);
		flag=1;
		TCNT0=216;
		
	}
	else if (flag==1)
	{
	   DIO_WritePin(PINC0,LOW);
	   flag=0;
	   TCNT0=96;
		
	}
}

*/

/*
ISR(TIMER0_OVF_vect){
	
	static u8 c=0;
	TCNT0=6;
	c++;
	
	if (c==60)
	{
		DIO_WritePin(PINC0,HIGH);
		
		
	}
	else if (c==80)
	{
		DIO_WritePin(PINC0,LOW);
		c=0;
		
	}
}

*/
 /* 
ISR(TIMER0_OVF_vect){
	
	static u16 c=0;
	static u16 c2=0;
   TCNT0=6;
	c++;
	c2++;
	if (c==4000)
	{
		DIO_TogglePin(PINC0);
		c=0;
		
	}
	if (c2==2000)
	{
		DIO_TogglePin(PINC1);
		c2=0;
		
	}
}

*/


/******************************** external interrupts  ********************************/
/*
void fun1(void){
	DIO_TogglePin(PINC0);
	//LCD_GoTo(0,0);
	//LCD_WriteString("INT 0");
	
}

void fun2(void){
	
		DIO_TogglePin(PINC1);
		//LCD_GoTo(1,0);
		//LCD_WriteString("INT 1");
}

int main(void)
{
      DIO_Init();
	  LCD_Init();
	  EXI_Init();
	  
	GLOBAL_ENABLE();   
	EXI_TriggerEdge(EX_INT0,FALLING_EDGE);
	EXI_Enable(EX_INT0);
    
   
	ADC_Init(VREF_AVCC,ADC_SCALER_64);
	ADC_StartConversion(CH_0);
	//u16 f;
 
   u8 x =0,f=0;
    while(1){
		
			LCD_GoTo(0,0); 
		    LCD_WriteNumber(x);
			x++;
			_delay_ms(200);	
			if(x==10){
				if (f==0)
				{
					 EXI_SetCallBack(EX_INT0,fun1);
					 f=1;
				}else{
					EXI_SetCallBack(EX_INT0,fun2);
					f=0;
				}
				x=0;
			}		
			
		    }  	
				
				
}


*/

/*
 ISR(ADC_vect){
	 
	u8 f=ADC_GetReaNoblock();
	 LCD_GoTo(1,0);
	 LCD_WriteNumber(f);
	 ADC_StartConversion(CH_0);
 }
 */
 /* ***********************  external interrup******************* */
 
    /*  //external interrupt
   MCUCR=0x0e;  //inte1 rising  int0 falling
   sei();       // enable global interrupt
   SET_BIT(GICR,INT1);  //enable int1
   SET_BIT(GICR,INT0);  //enable int0
   
   */

/*********************   task in session 46  ********************
LCD_GoTo(0,0);
LCD_WriteString("Char :");
LCD_WriteChar(x);
LCD_GoTo(1,0);
LCD_WriteString("ASCII:");
LCD_WriteNumber(x);
_delay_ms(300);
x++;

*/

/****************************** lcd***************************/
/*
  u8 P1[]={0x0E,0x0A,0x04,0x0E,0x15,0x0A,0x1B,0x00};
  u8 p2[] = {  0x00,0x1B,0x07,0x1E,0x05,0x05,0x00,0x00};
  //DIO_Initpin(BUTTON3,INPULL);
  
  //u8 name[]="Mohamed Elbery";
  //LCD_WriteString(name);
  
  //u8 x=65;
  LCD_CustomChar(0,P1);
  LCD_CustomChar(1,p2);
  LCD_GoTo(0,0);
  LCD_WriteChar(0);
  LCD_GoTo(0,15);
  LCD_WriteChar(0);
  
  
  
  u8 i=1;
  
  while (1)
  {
	  LCD_GoTo(0,i);
	  LCD_WriteChar('>');
	  _delay_ms(300);
	  LCD_GoTo(0,i);
	  LCD_WriteChar(' ');
	  i++;
	  if (i==15)
	  {
		  i=0;
		  LCD_GoTo(0,15);
		  LCD_WriteChar(0);
		  _delay_ms(300);
		  LCD_GoTo(0,15);
		  LCD_WriteChar(1);
		  
	  }
  }
  
  */

/************************** KEY PAD*********************/
/*
	
	
int main(void)
{
    
	 u8 k;
	 u8 flag=0;
	 u16 num=0;
    while (1) 
		{
			
			k=KEYPAD_GetKey();
			if (k!=NO_KEY)
			{
				if (k>='0'&&k<='9')
				{
					if (flag==0)
					{
						LCD_GoTo(0,0);
						LCD_WriteString("    ");
						LCD_GoTo(0,0);
						flag=1;
					}
					
					num=num*10+(k-'0');
			    	LCD_WriteChar(k);
					
					
				}
				else if(k=='='){
					LCD_GoTo(1,0);
					LCD_WriteHex(num);
					LCD_WriteString("   ");
					 num=0;
					flag=0;
				}
			}	
		}
}


	
	*/