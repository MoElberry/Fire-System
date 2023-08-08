
#include "StdTypes.h"
#include "LCD_Interface.h"
#include "LCD_Cfg.h"
#include "DIO_Inteface.h"
#include "Utils.h"


#if LCD_MODE== _8_BIT

static void WriteInst(u8 ins){
	
	DIO_WritePin(RS,LOW);
	DIO_WritePort(LCD_PORT,ins);  // 8 bit
	
	//puls 
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	
} 
void LCD_Init(void){
	_delay_ms(50);         //delay as requirement for datasheet
	WriteInst(0x38);
	WriteInst(0x0c);  // 0x0e cursor on     // 0x0f   cursor on an flasher
	WriteInst(0x01);  // clear screen
	_delay_ms(1);
	WriteInst(0x06); //increase address
	
}

static void WriteData(u8 data){
	
	DIO_WritePin(RS,HIGH);
	DIO_WritePort(LCD_PORT,data);  // 8 bit
	
	// puls
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	
}

#else


static void WriteInst(u8 ins){
	
	DIO_WritePin(RS,LOW);
	
	DIO_WritePin(D7,READ_BIT(ins,7));
	DIO_WritePin(D6,READ_BIT(ins,6));
	DIO_WritePin(D5,READ_BIT(ins,5));
	DIO_WritePin(D4,READ_BIT(ins,4));
	
	//puls
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	
		
		DIO_WritePin(D7,READ_BIT(ins,3));
		DIO_WritePin(D6,READ_BIT(ins,2));
		DIO_WritePin(D5,READ_BIT(ins,1));
		DIO_WritePin(D4,READ_BIT(ins,0));
		
		//puls
		DIO_WritePin(EN,HIGH);
		_delay_ms(1);
		DIO_WritePin(EN,LOW);
		_delay_ms(1);
	
}
void LCD_Init(void){
	_delay_ms(50);          //delay as requirement for datasheet
	
	WriteInst(0x02);      
	WriteInst(0x28);
	
	WriteInst(0x0c);  // 0x0e cursor on     // 0x0f   cursor on and flasher
	
	WriteInst(0x01);  // clear screen
	_delay_ms(1);
	
	WriteInst(0x06); //increase address
	
}

static void WriteData(u8 data){
	
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(D7,READ_BIT(data,7));
	DIO_WritePin(D6,READ_BIT(data,6));
	DIO_WritePin(D5,READ_BIT(data,5));
	DIO_WritePin(D4,READ_BIT(data,4));
	
	//puls
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	
	
	DIO_WritePin(D7,READ_BIT(data,3));
	DIO_WritePin(D6,READ_BIT(data,2));
	DIO_WritePin(D5,READ_BIT(data,1));
	DIO_WritePin(D4,READ_BIT(data,0));
	
	//puls
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	
}


#endif




void LCD_Clear(void){
	WriteInst(0x01);
	_delay_ms(1);
}




void LCD_GoTo(u8 line,u8 cell){
	
	if(line==0){
		WriteInst(0x80 + cell);
	}else if(line==1){
		WriteInst(0x80 + 0x40 + cell);
	}
}

void LCD_WriteChar(u8 ch){
	
	WriteData(ch);
	
	
}

void LCD_WriteString(u8 *str){
	u8 i;
	for(i=0;str[i];i++){
		LCD_WriteChar(str[i]);
	}
	
	
}

void LCD_WriteNumber(s32 num){
	c8 str[20];
	u8 i=0;
	s8 j;
	if (num==0)
	{
		LCD_WriteChar('0');
	}
	if (num<0)
	{
		LCD_WriteChar('-');
		num=num*-1;
	}
	
	while(num){
		str[i]=num%10 +'0';
		i++;
		num=num/10;
	}
	for(j=i-1;j>=0;j--){
		LCD_WriteChar(str[j]);
	}

	
	
}

void LCD_Write_4D(u16 num){
	
	LCD_WriteChar( ((num%10000)/1000 )+'0');
	LCD_WriteChar( ((num%1000)/100 )+'0');
	LCD_WriteChar( ((num%100)/10) +'0');
	LCD_WriteChar( ((num%10)/1) +'0');
		
}
void LCD_WriteBinary(s32 num){
	s8 i;
	for(i=7;i>=0;i--){
		
		LCD_WriteChar(READ_BIT(num,i)+'0');
		
	
    }
}

/*
void LCD_WriteHex(s32 num){
	s32 rem;
	while(num){
			rem=num%16;
			if (rem<10)
			{
				LCD_WriteChar(rem+'0');
			}else if (rem>=10&&rem<16)
			{
				LCD_WriteChar(rem-10+'A');
		    }
			num=num/16;
	   }
	
}

*/
void LCD_WriteHex(u8 num){
	u8 HN,LN;
	HN=num>>4;
	LN=num&0x0f;
		
		if (HN<10)
		{
			LCD_WriteChar(HN+'0');
		}else 
		{
			LCD_WriteChar(HN-10+'A');
		}
		
		if (LN<10)
		{
			LCD_WriteChar(LN+'0');
		}else
		{
			LCD_WriteChar(LN-10+'A');
		}
	
	
}

void LCD_WriteStringGoto(u8 line,u8 cell,u8 *str){
	LCD_GoTo(line,cell);
	LCD_WriteString(str);
}

void LCD_ClearPosition(u8 line,u8 cell,u8 NumOfCell){
	
	LCD_GoTo(line,cell);
	for(u8 i=0;i<NumOfCell;i++)
	{
		
		LCD_WriteChar(' ');
	}
}

void LCD_CustomChar(u8 address,u8* pattern){
	WriteInst(0x40+address*8);
	u8 i;
	for(i=0;i<8;i++){
		WriteData(pattern[i]);
	}
	WriteInst(0x80);
}