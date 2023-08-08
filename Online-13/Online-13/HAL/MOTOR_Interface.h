

#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_
#define  IN1  0
#define  IN2  1


typedef enum{
	M1,
	M2,
	M3,
	M4
}MOTOR_type;

void MOTOR_Init(void);

void MOTOR_STOP(MOTOR_type m);
void MOTOR_CW(MOTOR_type m);
void MOTOR_CCW(MOTOR_type m);

/*     speed (0:100)  */
void MOTOR_Seed(MOTOR_type m,u8 speed);


#endif /* MOTOR_INTERFACE_H_ */