/*
 * DIO_drive.h
 *
 *  Created on: Aug 12, 2023
 *      Author: Al-toukhi
 */

#ifndef DIO_H_
#define DIO_H_

#define PORTA   0
#define PORTB   1
#define PORTC   2
#define PORTD   3

#define PIN0    0
#define PIN1    1
#define PIN2    2
#define PIN3    3
#define PIN4    4
#define PIN5    5
#define PIN6    6
#define PIN7    7

#define Input   0
#define Output  1

#define Low     0
#define High    1

void MDIO_voidPortMode(u8 port_ID , u8 mode) ;
void MDIO_voidPortOutput(u8 port_ID  , u8 value) ;

void MDIO_voidPinMode(u8 port_ID , u8 pin_ID , u8 mode) ;
void MDIO_voidPinOutput(u8 port_ID , u8 pin_ID , u8 value) ;

u8 MDIO_u8PinRead(u8 port_ID , u8 pin_ID ) ;
void MDIO_voidPortValue(u8 A_u8Port , u8 A_u8Value) ;

#endif /* DIO_DRIVE_H_ */
