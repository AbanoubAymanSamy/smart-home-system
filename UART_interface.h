/*
 * UART_interface.h
 *
 * Created: 9/20/2024 3:57:47 PM
 *  Author: Dell
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_
#include "../../LIB/STD_TYPE.h"

void UART_voidInit() ;
void UART_voidTx(u8 copy_u8data) ;
u8 UART_u8Rx(void) ;
u8 UART_u8Available(void);
u8 UART_u8TransmitString(const char* str);

#endif /* UART_INTERFACE_H_ */