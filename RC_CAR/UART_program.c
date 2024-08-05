/*
 * UART_program.c
 *
 *  Created on: Sep 12, 2023
 *      Author: ELBOSTAN
 */
#include "STD_TYPES.h"
#include"BIT_MATH.h"

#include"UART_config.h"
#include"UART_interface.h"
#include"UART_private.h"
#include"UART_register.h"

#define  NULL    0
#define  F_CPU     8000000UL

static void (*funcptr[3])(void)={NULL,NULL,NULL};

void  UART_voidInit(void)
{
	u16 Local_u16BaudRate=BAUD_RATE;

//      Set BaudRate
	UBRRL = (u8) Local_u16BaudRate;
	UBRRH = (u8) (Local_u16BaudRate >>8);

//      Set Character Size 8_bit
	CLR_BIT(UCSRA,1);
	CLR_BIT(UCSRB,2);

/*      All select in Register UCSRC -------->   (1) Character Size  (2) Mode Asynchronous Operation
         (3) 1 Stop Mode              */
	UCSRC = CONC_BIT(1,0,0,0,0,1,1,0);

//      Enable Receiver
	SET_BIT(UCSRB,4);

//      Enable Transmitter
	SET_BIT(UCSRB,3);

}
void  UART_voidSendData_SyncBlocking(u8 Copy_u8Data)
{
//      Wait until UDR is empty
	while (GET_BIT(UCSRB,5)==0);

//   	Set Data into Tx Register and start Transmitter
	UDR=Copy_u8Data;

//      Wait until UDR is empty
	while (GET_BIT(UCSRB,5)==0);

//      Clear transmit interrupt flag
	SET_BIT(UCSRB,6);

}
void  UART_voidSendData_SyncNonBlocking(u8 Copy_u8Data)
{
	u32 local_u32TimeOut=0;

//        Wait until UDR is empty
	while (GET_BIT(UCSRB,5)==0)
	{
		local_u32TimeOut++;
		if (local_u32TimeOut==NON_BLOCKING_TIME_OUT)
		{
			break;
		}
	}

	if (local_u32TimeOut !=NON_BLOCKING_TIME_OUT )
		{
			local_u32TimeOut=0;
	       // 	  Set Data into Tx Register and start Transmitter
			UDR=Copy_u8Data;
			while (GET_BIT(UCSRB,5)==0)
			{
				local_u32TimeOut++;
				if (local_u32TimeOut==NON_BLOCKING_TIME_OUT)
				{
					break;
				}
			}
			//   Clear transmit interrupt flag
			SET_BIT(UCSRB,6);


		}
}
void  UART_voidSendString_SyncNonBlocking(u8 *u8String)
{
	while (*u8String > 0)
	{
		UART_voidSendString_SyncNonBlocking(*u8String++);
	}
}
void UART_receiveString(u8 *u8String)
{
	u8 i = 0;
	u8String[i] = UART_voidReceiveData_Async();
	while(u8String[i] != '#')
	{
		i++;
		u8String[i] = UART_voidReceiveData_Async();
	}
	u8String[i] = '\0';
}
void  UART_voidSendData_Async(u8 Copy_u8Data)
{
	if(GET_BIT(UCSRA,7)==0)
	{
		UDR = Copy_u8Data;
	}
}




u8  UART_voidReceiveData_SyncBlocking(void)
{
//        Wait for Rx flag
	while (GET_BIT(UCSRA,7)==0);
	return UDR ;
}
u8  UART_voidReceiveData_Async(void)
{
	return UDR ;
}
u8  UART_voidReceiveData_AsyncNonBlocking(void)
{
	u8 local_u8ReceiveData = NON_VALUE_RETURNED;
	u32 local_u32TimeOut = 0;

//         Wait for Rx flag
	while (GET_BIT(UCSRA,7)==0)
	{
		local_u32TimeOut++;
		if (local_u32TimeOut == NON_BLOCKING_TIME_OUT)
		{
			break;
		}
	}
	if(local_u32TimeOut != NON_BLOCKING_TIME_OUT)
	{
		local_u8ReceiveData = UDR;
	}
	return local_u8ReceiveData ;

}
void UART_voidSetCallBack(UART_INTERRUPTS InterruptSource,void(*PtoFunc)(void))
{
	if ((InterruptSource <= UART_Tx_INTERRUPT)&&(PtoFunc!=NULL))
	{
		funcptr[InterruptSource] = PtoFunc;
	}
}

void __vector_13(void)
{
	if(funcptr[UART_Rx_INTERRUPT]!=NULL)
	{
		funcptr[UART_Rx_INTERRUPT]();
	}
}
void __vector_14(void)
{
	if(funcptr[UART_UDRE_INTERRUPT]!=NULL)
		{
			funcptr[UART_UDRE_INTERRUPT]();
		}
}
void __vector_15(void)
{
	if(funcptr[UART_Tx_INTERRUPT]!=NULL)
		{
			funcptr[UART_Tx_INTERRUPT]();
		}
}










