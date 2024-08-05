/*
 * DC_MOTOR_program.c
 *
 *  Created on: Aug 22, 2023
 *      Author: ELBOSTAN
 */


#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"DIO_interface.h"

#include"DC_MOTOR_config.h"
#include"DC_MOTOR_interface.h"
#include"DC_MOTOR_private.h"

#include "PWM_interface.h"


void DC_MOTOR_voidInit(void)
{
	//Motor1
	DIO_voidSetPinDirection(DC_1_MOTOR_PORT,DC_1_MOTOR_PIN0,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(DC_1_MOTOR_PORT,DC_1_MOTOR_PIN1,DIO_u8OUTPUT);
	//Motor2
	DIO_voidSetPinDirection(DC_1_MOTOR_PORT,DC_2_MOTOR_PIN0,DIO_u8OUTPUT);
	DIO_voidSetPinDirection(DC_1_MOTOR_PORT,DC_2_MOTOR_PIN1,DIO_u8OUTPUT);

}

/*          DC_MOTOR Move Forward         */

void DC_MOTOR_voidRotateCW(u16 Copy_u16_Speed)
{
	// Motor1
	DIO_voidSetPinValue(DC_1_MOTOR_PORT,DC_1_MOTOR_PIN1,DIO_u8HIGH);
	DIO_voidSetPinValue(DC_1_MOTOR_PORT,DC_1_MOTOR_PIN0,DIO_u8LOW);
	// Motor2
	DIO_voidSetPinValue(DC_2_MOTOR_PORT,DC_2_MOTOR_PIN1,DIO_u8HIGH);
	DIO_voidSetPinValue(DC_2_MOTOR_PORT,DC_2_MOTOR_PIN0,DIO_u8LOW);
	//Control Speed
	PWM_voidOCRValue_0_(Copy_u16_Speed);
	PWM_voidOCRValue_1_(Copy_u16_Speed);

}

/*             Moving Right            */

void DC_MOTOR_MovingRight(u16 Copy_u16_SpeedRight,u16 Copy_u16_SpeedLeft)
{
	//  Motor1
	DIO_voidSetPinValue(DC_1_MOTOR_PORT,DC_1_MOTOR_PIN1,DIO_u8HIGH);
	DIO_voidSetPinValue(DC_1_MOTOR_PORT,DC_1_MOTOR_PIN0,DIO_u8LOW);
	//  Motor2
	DIO_voidSetPinValue(DC_2_MOTOR_PORT,DC_2_MOTOR_PIN1,DIO_u8HIGH);
	DIO_voidSetPinValue(DC_2_MOTOR_PORT,DC_2_MOTOR_PIN0,DIO_u8LOW);
	//Control Speed
	PWM_voidOCRValue_0_(Copy_u16_SpeedRight);
	PWM_voidOCRValue_1_(Copy_u16_SpeedLeft);

}
/*             Moving Left            */

void DC_MOTOR_MovingLeft(u16 Copy_u16_SpeedRight,u16 Copy_u16_SpeedLeft)
{
	//  Motor1
	DIO_voidSetPinValue(DC_1_MOTOR_PORT,DC_1_MOTOR_PIN1,DIO_u8HIGH);
	DIO_voidSetPinValue(DC_1_MOTOR_PORT,DC_1_MOTOR_PIN0,DIO_u8LOW);
	//  Motor2
	DIO_voidSetPinValue(DC_2_MOTOR_PORT,DC_2_MOTOR_PIN1,DIO_u8HIGH);
	DIO_voidSetPinValue(DC_2_MOTOR_PORT,DC_2_MOTOR_PIN0,DIO_u8LOW);
	//Control Speed
	PWM_voidOCRValue_0_(Copy_u16_SpeedRight);
	PWM_voidOCRValue_1_(Copy_u16_SpeedLeft);

}

/*          DC_MOTOR Move Backward          */

void DC_MOTOR_voidRotateACW(u16 Copy_u16_Speed)
{
	//  Motor1
	DIO_voidSetPinValue(DC_1_MOTOR_PORT,DC_1_MOTOR_PIN1,DIO_u8LOW);
	DIO_voidSetPinValue(DC_1_MOTOR_PORT,DC_1_MOTOR_PIN0,DIO_u8HIGH);
	//  Motor2
	DIO_voidSetPinValue(DC_2_MOTOR_PORT,DC_2_MOTOR_PIN1,DIO_u8LOW);
	DIO_voidSetPinValue(DC_2_MOTOR_PORT,DC_2_MOTOR_PIN0,DIO_u8HIGH);
	//Control Speed
	PWM_voidOCRValue_0_(Copy_u16_Speed);
	PWM_voidOCRValue_1_(Copy_u16_Speed);

}
/*     DC_1_MOTOR Stop ------------> Rotate left       */

void DC_1_MOTOR_voidStop(u16 Copy_u16_Speed)
{
	//  Motor1
	DIO_voidSetPinValue(DC_1_MOTOR_PORT,DC_1_MOTOR_PIN0,DIO_u8LOW);
	DIO_voidSetPinValue(DC_1_MOTOR_PORT,DC_1_MOTOR_PIN1,DIO_u8LOW);
	//  Motor2
	DIO_voidSetPinValue(DC_2_MOTOR_PORT,DC_2_MOTOR_PIN0,DIO_u8LOW);
	DIO_voidSetPinValue(DC_2_MOTOR_PORT,DC_2_MOTOR_PIN1,DIO_u8HIGH);
	//Control Speed
	PWM_voidOCRValue_0_(0);
	PWM_voidOCRValue_1_(Copy_u16_Speed);

}
/*     DC_2_MOTOR Stop  -------------> Rotate Right        */

void DC_2_MOTOR_voidStop(u16 Copy_u16_Speed)
{
	//  Motor1
	DIO_voidSetPinValue(DC_1_MOTOR_PORT,DC_1_MOTOR_PIN0,DIO_u8LOW);
	DIO_voidSetPinValue(DC_1_MOTOR_PORT,DC_1_MOTOR_PIN1,DIO_u8HIGH);
	//  Motor2
	DIO_voidSetPinValue(DC_2_MOTOR_PORT,DC_2_MOTOR_PIN0,DIO_u8LOW);
	DIO_voidSetPinValue(DC_2_MOTOR_PORT,DC_2_MOTOR_PIN1,DIO_u8LOW);
	//Control Speed
	PWM_voidOCRValue_0_(Copy_u16_Speed);
	PWM_voidOCRValue_1_(0);

}
/*         The two DC_MOTOR Stop          */

void DC_MOTOR_voidStop(u16 Copy_u16_Speed)
{
	//  Motor1
	DIO_voidSetPinValue(DC_1_MOTOR_PORT,DC_1_MOTOR_PIN0,DIO_u8LOW);
	DIO_voidSetPinValue(DC_1_MOTOR_PORT,DC_1_MOTOR_PIN1,DIO_u8LOW);
	//  Motor1
	DIO_voidSetPinValue(DC_2_MOTOR_PORT,DC_2_MOTOR_PIN0,DIO_u8LOW);
	DIO_voidSetPinValue(DC_2_MOTOR_PORT,DC_2_MOTOR_PIN1,DIO_u8LOW);
	//Control Speed
	PWM_voidOCRValue_0_(Copy_u16_Speed);
	PWM_voidOCRValue_1_(Copy_u16_Speed);

}
