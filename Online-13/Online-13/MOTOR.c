
#include "MemMap.h"
#include "StdTypes.h"
#include "Utils.h"

#define MOTOR_PORT  DDRD
#define M1_IN1 0
#define M1_IN2 1
typedef enum{
	M1,
	M2,
	M3,
	M4
}MOTOR_type;


