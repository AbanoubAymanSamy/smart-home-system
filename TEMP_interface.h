/*
 * TEMP_interface.h
 *
 * Created: 9/19/2024 11:28:39 PM
 *  Author: bebo
 */ 


#ifndef TEMP_INTERFACE_H_
#define TEMP_INTERFACE_H_

#include "../../LIB/STD_TYPE.h"

#define   ADC_MAX_VALUE   1023
#define   VREF            5.0

f32 LM35_f32GetTemperature(u8 channel);






#endif /* TEMP_INTERFACE_H_ */