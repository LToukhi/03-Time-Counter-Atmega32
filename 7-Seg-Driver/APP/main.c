/*
 * main.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Al-toukhi
 */
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../HAL/7_Seg/7_Seg.h"
#include "../MCAL/DIO/DIO.h"
#include <util/delay.h>

void main()
{
	u8 i=0 , j=0 , k=0 ;

	HSS_voidInit(PORTC) ;
	HSS_voidInit(PORTA) ;
	HSS_voidInit(PORTB) ;
	HSS_voidInit(PORTD) ;

	while(1)
	{
		while(i<6)
		{
			HSS_voidCountUp(PORTD ,0) ;
			i++ ;
			HSS_viodDisplayValue(PORTC ,i) ;
		}
		if(i==6)
		{
			HSS_viodDisplayValue(PORTD ,0) ;
			HSS_viodDisplayValue(PORTC ,0) ;
			i=0 ;
		}
			j++ ;
			HSS_viodDisplayValue(PORTB ,j) ;

		if (j>9)
		{
			j=0 ;
			HSS_viodDisplayValue(PORTB ,0) ;
			k++ ;
			HSS_viodDisplayValue(PORTA ,k) ;
			if(k>9)
			{
				k=0 ;
				HSS_viodDisplayValue(PORTA ,0) ;
			}
		}

	}

}


