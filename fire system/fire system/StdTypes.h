 


#ifndef STDTYPES_H_
#define STDTYPES_H_

#define F_CPU 8000000
#include <util/delay.h>

/************************* null pointer**************************/
#define  NULLPTR ((void*)0)
#define NULL    ((char)0)
/************************* standard types ***********************/
typedef unsigned char u8;
typedef signed char s8;
typedef char c8;

typedef unsigned short u16;
typedef signed short s16;


typedef unsigned long u32;
typedef signed long s32;

/************************* standard MAX AND MIN RANGE ***********************/
#define MAX_U8 ((u8)255)
#define MIN_U8 ((u8)0)
#define MAX_S8 ((s8)127)
#define MIN_S8 ((s8)255)

#define ZERO_S8 ((s8)0)

typedef enum{
	FALSE,
	TRUE
	}Bool_t;
	
typedef enum{
		OK,
		NOK,
		NULL_PTR,
		OUTOFRANGE
	}Error_t;
	
	
	
	

#endif /* STDTYPES_H_ */