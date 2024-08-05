/*
 * BIT_MATH.h
 *
 *  Created on: 14 Aug 2023
 *      Author: ????
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

# define SET_BIT(var, bit_num)       var|=(1<<bit_num)
# define CLR_BIT(var, bit_num)       var&=(~(1<<bit_num))
# define TOGGLE_BIT(var, bit_num)    var^=(1<<bit_num)
# define GET_BIT(var, bit_num)       ((var>>bit_num)&1)

#define WRITE_BIT(reg, bitnum, value) 				(reg = (reg & (~(1 << bitnum))) | (value << bitnum))
#define WRITE_BITS(reg, bitnum, bitmask, value) 	(reg = (reg & (~(bitmask << bitnum))) | (value << bitnum))
#define WRITE_BYTE(reg, value) 						(reg = value)

#define CONC_BIT(b7, b6, b5, b4, b3, b2, b1, b0) 	CONC_HELP(b7, b6, b5, b4, b3, b2, b1, b0)
#define CONC_HELP(b7, b6, b5, b4, b3, b2, b1, b0) 	0b##b7##b6##b5##b4##b3##b2##b1##b0

/* Rotate right the register value with specific number of rotates */
#define ROR(REG,num) ( REG= (REG>>num) | (REG<<(8-num)) )

/* Rotate left the register value with specific number of rotates */
#define ROL(REG,num) ( REG= (REG<<num) | (REG>>(8-num)) )

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )

#endif /* BIT_MATH_H_ */
