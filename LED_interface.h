/*
 * LED_interface.h
 *
 * Created: 8/10/2024 4:25:53 PM
 *  Author: bebo
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"

#include "../../MCAL/DIO/DIO_reg.h"
#include "../../MCAL/DIO/DIO_interface.h"


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#define LedOn	1
#define LedOff	0


/*****************************************************************************
* Function Name: LED_voidon
* Purpose      :  on the led
* Parameters   : u8 PORT,u8 PIN
* Return value : void
********************************************************************/
void LED_voidOn(u8 copy_u8port,u8 copy_u8pin);
/*****************************************************************************
* Function Name: LED_voidoff
* Purpose      :  off the led
* Parameters   : u8 PORT,u8 PIN
* Return value : void
********************************************************************/
void LED_voidOff(u8 copy_u8port,u8 copy_u8pin);
/*****************************************************************************
* Function Name: LED_voidToggle
* Purpose      :  toggle the led
* Parameters   : u8 PORT,u8 PIN
* Return value : void
********************************************************************/
void LED_voidToggle(u8 copy_u8port,u8 copy_u8pin);

#endif /* LED_INTERFACE_H_ */