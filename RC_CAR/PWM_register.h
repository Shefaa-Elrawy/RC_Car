/*
 * PWM_register.h
 *
 *  Created on: Sep 5, 2023
 *      Author: ELBOSTAN
 */

#ifndef PWM_REGISTER_H_
#define PWM_REGISTER_H_

#define  TCCR1A          *((volatile u8*) (0x4F))
#define  TCCR1B          *((volatile u8*) (0x4E))
#define  TCNT1L  	     *((volatile u16*)(0x4C))
#define  TCNT1H  	     *((volatile u8*) (0x4D))

#define  OCR1A           *((volatile u16*)(0x4A))
#define  OCR1B           *((volatile u16*)(0x4B))
#define  OCR1AH          *((volatile u8*) (0x4B))
#define  OCR1AL          *((volatile u8*) (0x4A))

#define  ICR1      		 *((volatile u16*)(0x46))
#define  ICR1H    	     *((volatile u8*) (0x47))

#define  TIMSK           *((volatile u8*)(0x59))
#define  TIFR            *((volatile u8*)(0x58))
#define  TCCR0           *((volatile u8*)(0x53))
#define  TCNT0           *((volatile u8*)(0x52))
#define  OCR0            *((volatile u8*)(0x5C))






#endif /* PWM_REGISTER_H_ */
