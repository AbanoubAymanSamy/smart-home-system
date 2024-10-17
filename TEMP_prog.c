/*
 * TEMP_prog.c
 *
 * Created: 9/19/2024 11:27:19 PM
 *  Author: bebo
 */ 


#include "../../LIB/STD_TYPE.h"
#include "../../MCAL/ADC/ADC_interface.h"
#include "TEMP_interface.h"


f32 LM35_f32GetTemperature(u8 copy_u8channel){
	u16 adc_value = ADC_u16ReadChannel(copy_u8channel);
	f32 voltage = (adc_value * VREF) / ADC_MAX_VALUE;
	f32 temperature = voltage * 100;
	return temperature;
}

