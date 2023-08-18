/*
 * GIE.c
 *
 *  Created on: Aug 17, 2023
 *      Author: ENG.AbdelrhmanEslam
 */
#include "GIE_Init.h"

#define GIE_SREG_REG 	*((volatile u8 *) 0x5F)

void MGIR_voidEnable()
{
	SET_BIT(GIE_SREG_REG,7);
}

void MGIR_voidDisEnable()
{
	CLR_BIT(GIE_SREG_REG,7);
}
