/*
 * 7_Seg.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Al-toukhi
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO.h"
#include "7_Seg.h"
#include <util/delay.h>

//choose type////////////////////////////////////////
#define Cathode 1
#define Anode   2

#define Type    Cathode
//////////////////////////////////////////////////////
static const u8 SS_u8ArrValue[10]={
		0b0111111 , //zero
		0b0000110 , //one
		0b1011011 , //two
		0b1001111 , //three
		0b1100110 , //four
		0b1101101 , //five
		0b1111101 , //six
		0b0000111 , //seven
		0b1111111 , //eight
		0b1101111 , //nine
};

//Initialize 7-segment
void HSS_voidInit(u8 A_u8Port)
{
	if(A_u8Port <= PORTD)
	{
		MDIO_voidPortMode(A_u8Port , Output) ;
	}
}

//display value on 7-segment
void HSS_viodDisplayValue(u8 A_u8Port , u8 A_u8Value)
{
	if((A_u8Port <= PORTD) && (A_u8Value<=9))
	{
		#if Type == Cathode
			MDIO_voidPortValue(A_u8Port , SS_u8ArrValue[A_u8Value]) ;
		#elif Type == Anode
			MDIO_voidPortValue(A_u8Port , ~SS_u8ArrValue[A_u8Value]) ;
		#endif
	}
}

//make 7-segment count up
void HSS_voidCountUp(u8 A_u8Port , u8 A_u8Value)
{
	if((A_u8Port <= PORTD) && (A_u8Value<=9))
	{
		for(u8 counter=A_u8Value ; counter<10 ; counter++)
		{
			HSS_viodDisplayValue(A_u8Port , counter) ;
			_delay_ms(100) ;
		}
	}
}

//make 7-segment count down
void HSS_voidCountDown(u8 A_u8Port , u8 A_u8Value)
{
	if(A_u8Port <= PORTD && (A_u8Value<=9))
	{
		for(u8 counter=A_u8Value ; counter>=0 ; counter--)
		{
			HSS_viodDisplayValue(A_u8Port , counter) ;
			_delay_ms(100) ;
		}
	}
}

//turn off 7-segment
void HSS_voidTurnOff(u8 A_u8Port)
{
	if(A_u8Port <= PORTD)
	{
		#if Type == Cathode
		MDIO_voidPortValue(A_u8Port , 0x00) ;
		#elif Type == Anode
		MDIO_voidPortValue(A_u8Port , 0xff) ;
		#endif
	}
}
