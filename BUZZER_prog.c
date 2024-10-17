/*
 * BUZZER_prog.c
 *
 * Created: 8/23/2024 7:58:20 PM
 *  Author: bebo
 */ 

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "BUZZER_interface.h"
#include "BUZZER_config.h"


void BUZZER_voidOnVal(void){
	DIO_voidSetPinVal(BUZZER_Port,BUZZER_Pin,HIGH);
}
void BUZZER_voidOffVal(void){
	DIO_voidSetPinVal(BUZZER_Port,BUZZER_Pin,LOW);
}
void BUZZER_voidToggleVal(void){
	
	DIO_voidTogglePinVal(BUZZER_Port,BUZZER_Pin);
	
	
	
}