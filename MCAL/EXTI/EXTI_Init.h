/*
 * EXTI_Init.h
 *
 *  Created on: Aug 17, 2023
 *      Author: ENG.AbdelrhmanEslam
 */

#ifndef MCAL_EXTI_EXTI_INIT_H_
#define MCAL_EXTI_EXTI_INIT_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../DIO/DIO.h"

#define EXTI_Line0	0
#define EXTI_Line1	1
#define EXTI_Line2	2


#define EXTI_LOWLEVEL 0
#define EXTI_ONChange 1
#define EXTI_Falling  2
#define EXTI_Rising   3

void MEXTI_voidSenseControl(u8 A_u8EXTI_Line, u8 A_u8EXTI_Sense);
void MEXTI_voidEnable      (u8 A_u8EXTI_Line);
void MEXTI_voidDisEnable   (u8 A_u8EXTI_Line);



#endif /* MCAL_EXTI_EXTI_INIT_H_ */
