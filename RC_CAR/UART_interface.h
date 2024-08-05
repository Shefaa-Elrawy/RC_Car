/*
 * UART_interface.h
 *
 *  Created on: Sep 12, 2023
 *      Author: ELBOSTAN
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

typedef enum{
	UART_Rx_INTERRUPT =0 ,
	UART_UDRE_INTERRUPT,
	UART_Tx_INTERRUPT
}UART_INTERRUPTS;

void  UART_voidInit(void);

void  UART_voidSendData_SyncBlocking(u8 Copy_u8Data);
void  UART_voidSendData_SyncNonBlocking(u8 Copy_u8Data);

void  UART_voidSendString_SyncNonBlocking(u8 *u8String);
void UART_receiveString(u8 *u8String)	;

void  UART_voidSendData_Async(u8 Copy_u8Data);

u8  UART_voidReceiveData_SyncBlocking(void);
u8  UART_voidReceiveData_Async(void);

void UART_voidSetCallBack(UART_INTERRUPTS InterruptSource,void(*PtoFunc)(void));

void __vector_13(void) __attribute__((signal));
void __vector_14(void) __attribute__((signal));
void __vector_15(void) __attribute__((signal));

#endif /* UART_INTERFACE_H_ */
