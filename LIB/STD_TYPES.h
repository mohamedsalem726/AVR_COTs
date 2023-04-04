#ifndef _STD_TYPES_H
#define _STD_TYPES_H

typedef char                char_t;
typedef unsigned char       u8;
typedef signed char         s8;
typedef unsigned short int u16;
typedef signed short int   s16;
typedef unsigned long int  u32;
typedef signed long int    s32;
typedef float              f32;
typedef double             f64;

#define NULL  (void *)0

typedef enum
{
	ERROR,
	NO_ERROR,
	OUT_OF_RANGE_VALUE,
	NULL_POINTER,
	BUSY_FUNC
}Error_State;

#endif
