/*
 * PWM_program.c
 *
 *  Created on: Sep 5, 2023
 *      Author: ELBOSTAN
 */

#include "STD_TYPES.h"
#include"BIT_MATH.h"

#include"PWM_config.h"
#include"PWM_interface.h"
#include"PWM_private.h"
#include"PWM_register.h"

#include "DIO_interface.h"

void PWM_voidInit_1_(void)
{
	/*  clear on compare match , set at top for channel A   */

	SET_BIT(TCCR1A,7);
	CLR_BIT(TCCR1A,6);

	/*   select PWM mode  */

	CLR_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,4);
	SET_BIT(TCCR1B,3);

  /*   Select pre_scalar  : divide by 8   */

	CLR_BIT(TCCR1B,2);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,0);


}
void PWM_voidInit_0_(void)
{
	  // CLR_BIT(TCCR0,7);

/*       Select Mode => Fast PWM Mode        */

		SET_BIT(TCCR0,6);
		SET_BIT(TCCR0,3);

/*       Select HW Action On OC0Pin => Non Inverting      */

		SET_BIT(TCCR0,5);
		CLR_BIT(TCCR0,4);

/*       Select pre_scalar  : divide by 8       */

		CLR_BIT(TCCR0,2);
		SET_BIT(TCCR0,1);
		CLR_BIT(TCCR0,0);

		DIO_voidSetPinDirection(DIO_u8PORTB,3,DIO_u8OUTPUT);
}
void PWM_voidSetTopValue_1_(u16 Copy_u16Value)
{

	ICR1 = Copy_u16Value;
}

void PWM_voidOCRValue_1_(u16 Copy_u16Value)
{

	OCR1A=Copy_u16Value;


}
void PWM_voidOCRValue_0_(u16 Copy_u16Value)
{
	OCR0 = Copy_u16Value;
}



