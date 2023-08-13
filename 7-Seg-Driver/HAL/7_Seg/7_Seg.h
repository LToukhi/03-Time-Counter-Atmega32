/*
 * 7_Seg.h
 *
 *  Created on: Aug 13, 2023
 *      Author: Al-toukhi
 */

#ifndef HAL_7_SEG_7_SEG_H_
#define HAL_7_SEG_7_SEG_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO.h"

void HSS_voidInit(u8 A_u8Port) ;
void HSS_viodDisplayValue(u8 A_u8Port , u8 A_u8Value) ;
void HSS_voidCountUp(u8 A_u8Port , u8 A_u8Value) ;
void HSS_voidCountDown(u8 A_u8Port , u8 A_u8Value) ;
void HSS_voidTurnOff(u8 A_u8Port) ;

#endif /* HAL_7_SEG_7_SEG_H_ */
