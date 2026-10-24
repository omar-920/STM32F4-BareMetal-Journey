/*
 * STD_TYPE.h
 *
 * Created: 10/11/2026 12:10:08 AM
 *  Author: Omar
 */ 


#ifndef STD_TYPE_H_
#define STD_TYPE_H_

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long u64;


typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long s64;

typedef float f32;
typedef double f64;

typedef u8 std_ReturnType;

#define E_NOT_OK    (std_ReturnType) 0
#define E_OK        (std_ReturnType) 1


#endif /* STD_TYPE_H_ */