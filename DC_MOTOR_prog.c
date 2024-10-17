/*
 * DC_MOTOR_prog.c
 *
 * Created: 9/13/2024 2:44:11 PM
 *  Author: bebo
 */ 
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TIMER_1/TIM1_interface.h"
#include "../../LIB/STD_TYPE.h"
#include "DC_MOTOR_config.h"
#include "DC_MOTOR_interface.h"




void DCMOTOR_voidCW(u8 copy_u8dc){
	
	/*  SET DIR DC*/
	DIO_voidSetPinDir(H_EN1_port,H_EN1_pin,OUTPUT);
	DIO_voidSetPinDir(H_A1_port,H_A1_pin,OUTPUT);
	DIO_voidSetPinDir(H_A2_port,H_A2_pin,OUTPUT);
	
	/*  SET VAL DC*/
	TIMER1_voidFastPWM10BitRes(OC1B_PIN,copy_u8dc);
	DIO_voidSetPinVal(H_A1_port,H_A1_pin,HIGH);
	DIO_voidSetPinVal(H_A2_port,H_A2_pin,LOW);
	
	
}
void DCMOTOR_voidACW(u8 copy_u8dc){
	
	/*  SET DIR DC*/
	DIO_voidSetPinDir(H_EN1_port,H_EN1_pin,OUTPUT);
	DIO_voidSetPinDir(H_A1_port,H_A1_pin,OUTPUT);
	DIO_voidSetPinDir(H_A2_port,H_A2_pin,OUTPUT);
	
	/*  SET VAL DC*/
	TIMER1_voidFastPWM10BitRes(OC1B_PIN,copy_u8dc);
	DIO_voidSetPinVal(H_A1_port,H_A1_pin,LOW);
	DIO_voidSetPinVal(H_A2_port,H_A2_pin,HIGH);

	
	
}
	
	
	
	
void DCMOTOR_voidStop(u8 copy_u8dc){
	
	/*  SET DIR DC*/
	DIO_voidSetPinDir(H_EN1_port,H_EN1_pin,OUTPUT);
	DIO_voidSetPinDir(H_A1_port,H_A1_pin,OUTPUT);
	DIO_voidSetPinDir(H_A2_port,H_A2_pin,OUTPUT);
	
	/*  SET VAL DC*/
	TIMER1_voidFastPWM10BitRes(OC1B_PIN,copy_u8dc);
	DIO_voidSetPinVal(H_A1_port,H_A1_pin,LOW);
	DIO_voidSetPinVal(H_A2_port,H_A2_pin,LOW);
	
	
}

