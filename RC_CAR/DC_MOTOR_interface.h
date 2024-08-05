/*
 * DC_MOTOR_interface.h
 *
 *  Created on: Aug 22, 2023
 *      Author: ELBOSTAN
 */

#ifndef DC_MOTOR_INTERFACE_H_
#define DC_MOTOR_INTERFACE_H_

void DC_MOTOR_voidInit(void);

void DC_MOTOR_voidRotateCW(u16 Copy_u16_Speed);
void DC_MOTOR_voidRotateACW(u16 Copy_u16_Speed);

void DC_MOTOR_MovingRight(u16 Copy_u16_SpeedRight,u16 Copy_u16_SpeedLeft);
void DC_MOTOR_MovingLeft(u16 Copy_u16_SpeedRight,u16 Copy_u16_SpeedLeft);

void DC_1_MOTOR_voidStop(u16 Copy_u16_Speed);
void DC_2_MOTOR_voidStop(u16 Copy_u16_Speed);
void DC_MOTOR_voidStop(u16 Copy_u16_Speed);

#endif /* DC_MOTOR_INTERFACE_H_ */
