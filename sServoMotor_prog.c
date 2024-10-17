/*
 * sServoMotor_prog.c
 *
 * Created: 9/15/2024 12:40:04 PM
 *  Author: bebo
 */

 
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/TIMER_1/TIM1_interface.h"
#include "../../MCAL/TIMER_1/TIM1_reg.h"





void SERVO_voidSendDegree(u16 copy_u16degree){
	
	u16 step=1000 + (copy_u16degree * (4100/ 180));
	OCR1B_REG=step;


}
	
void SERVO_voidResetDegree(void){
	
	u16 step=1000 + (0 * (4100/ 180));
	OCR1B_REG=step;
	
	
	
}
