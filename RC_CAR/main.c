/*
 * main.c
 *
 *  Created on: Sep 12, 2023
 *      Author: ELBOSTAN
 */


#include "STD_TYPES.h"
#include"BIT_MATH.h"

#include"UART_interface.h"
#include"DIO_interface.h"


int main(void)
{

	    char Data_in;
	    DIO_voidSetPortDirection(DIO_u8PORTA,0b11111111);
		DIO_voidSetPortDirection(DIO_u8PORTD,0b00000010) ;/* make PORT as output port */
		UART_voidInit();	/* initialize USART with 9600 baud rate */

		Data_in = UART_voidReceiveData_Async();  /* receive data from Bluetooth device*/
		while(1)
		{

			if(Data_in =='F')
			{
				DIO_voidSetPinValue(DIO_u8PORTA,0,1);	/* Turn ON LED */

			}
			else if(Data_in =='B')
			{
				DIO_voidSetPinValue(DIO_u8PORTA,1,1);	/* Turn ON LED */

			}
		}



}

