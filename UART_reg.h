/*
 * UART_reg.h
 *
 * Created: 9/20/2024 3:58:18 PM
 *  Author: Dell
 */ 


#ifndef UART_REG_H_
#define UART_REG_H_


#define  UDR_REG     *((volatile u8*)0x2C)
#define  UCSRA_REG   *((volatile u8*)0x2B)
#define  UCSRB_REG   *((volatile u8*)0x2A)
#define  UCSRC_REG   *((volatile u8*)0x40)
#define  UBRRH_REG   *((volatile u8*)0x40)
#define  UBRRL_REG   *((volatile u8*)0x29)




#endif /* UART_REG_H_ */