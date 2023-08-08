/*
 * MOTOR_Cfg.h
 *
 * Created: 6/13/2023 11:31:27 PM
 *  Author: Mohamed
 */ 
#ifndef MOTOR_CFG_H_
#define MOTOR_CFG_H_
/****************** PIN CONFIG*******************************/

/************M1**************/
#define  M1_IN1 PINB0
#define  M1_IN2 PINB1
/************M2**************/
#define  M2_IN1 PIND2
#define  M2_IN2 PIND3
/************M3**************/
#define  M3_IN1 PIND4
#define  M3_IN2 PIND5
/************M4**************/
#define  M4_IN1 PIND6
#define  M4_IN2 PIND7

/********************************** IN1   IN2  *********************/
DIO_Pin_type MotorPinArr[4][2]={ {M1_IN1,M1_IN2}  /*M1*/
	                            ,{M2_IN1,M2_IN2}  /*M2*/
						    	,{M3_IN1,M3_IN2}  /*M3*/
							    ,{M4_IN1,M4_IN2}};/*M4*/

#define  MOTOR_INIT_STATE  

#define MOTOR_MAX_SPEED  ((u16)150)


#endif /* MOTOR_CFG_H_ */