/*
 * LCD_Cfg.h
 *
 * Created: 6/14/2023 7:00:41 PM
 *  Author: Mohamed
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#define  _8_BIT  1
#define  _4_BIT  0

 /**********    _8_BIT OR  _4_BIT **********************/
 
#define  LCD_MODE  _4_BIT

#define  RS  PIND0
#define  EN  PIND1

/*************   4_BIT  mode only *******************/
#define  D4  PINC4
#define  D5  PINC5
#define  D6  PINC6
#define  D7  PINC7



/*************   8_BIT  mode only *******************/
#define LCD_PORT PC 



#endif /* LCD_CFG_H_ */