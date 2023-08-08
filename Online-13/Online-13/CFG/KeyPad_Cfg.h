/*
 * KeyPad_Cfg.h
 *
 * Created: 6/20/2023 10:40:35 PM
 *  Author: Mohamed
 */ 


#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

#define  ROWS  4
#define  COLS  4

#define NO_KEY  'T'

#define  FIRIST_OUTPUT  PINB4
#define  FIRIST_INPUT   PIND2

#if KEYPAD_PRG

      u8  KEYPAD_ARR[ROWS][COLS]={    {'7','8','9','/'},
	                                  {'4','5','6','*'},
									  {'1','2','3','-'},
									  {'C','0','=','+'}
	                                        };

#endif


#endif /* KEYPAD_CFG_H_ */