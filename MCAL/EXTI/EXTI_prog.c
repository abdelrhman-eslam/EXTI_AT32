/*
 * EXTI_prog.c
 *
 *  Created on: Aug 17, 2023
 *      Author: ENG.AbdelrhmanEslam
 */
//Edge INT

#include "EXTI_Init.h"

#define REXTI_MCUCR_REG 	*((volatile u8 *) 0x55)
#define REXTI_MCUCSR_REG  	*((volatile u8 *) 0x54)
#define REXTI_GICR_REG	 	*((volatile u8 *) 0x5B)
#define REXTI_GIFR_REG	 	*((volatile u8 *) 0x5A)

//static void (*callback)(void);

void MEXTI_voidSenseControl(u8 A_u8EXTI_Line, u8 A_u8EXTI_Sense){
	switch(A_u8EXTI_Line)
	{
	// REXTI_MCUCR_REG = REXTI_MCUCR_REG & ~(0b1111<<0) | A_u8EXTI_Sense<<0
	case EXTI_Line0:
		switch(A_u8EXTI_Sense)
		{
		case EXTI_LOWLEVEL:
			CLR_BIT(REXTI_MCUCR_REG,0);
			CLR_BIT(REXTI_MCUCR_REG,1);
			break;
		case EXTI_ONChange:
					SET_BIT(REXTI_MCUCR_REG,0);
					CLR_BIT(REXTI_MCUCR_REG,1);
					break;
		case EXTI_Falling:
					CLR_BIT(REXTI_MCUCR_REG,0);
					SET_BIT(REXTI_MCUCR_REG,1);
					break;
		case EXTI_Rising:
					SET_BIT(REXTI_MCUCR_REG,0);
					SET_BIT(REXTI_MCUCR_REG,1);
			break;
		}
		break;

	case EXTI_Line1:
			switch(A_u8EXTI_Sense)
			{
			case EXTI_LOWLEVEL:
				CLR_BIT(REXTI_MCUCR_REG,2);
				CLR_BIT(REXTI_MCUCR_REG,3);
				break;
			case EXTI_ONChange:
				SET_BIT(REXTI_MCUCR_REG,2);
				CLR_BIT(REXTI_MCUCR_REG,3);
				break;
			case EXTI_Falling:
						CLR_BIT(REXTI_MCUCR_REG,2);
						SET_BIT(REXTI_MCUCR_REG,3);
						break;
			case EXTI_Rising:
						SET_BIT(REXTI_MCUCR_REG,2);
						SET_BIT(REXTI_MCUCR_REG,3);
				break;
			}
			break;
	case EXTI_Line2:
				switch(A_u8EXTI_Sense)
				{
				case EXTI_Falling:
							CLR_BIT(REXTI_MCUCSR_REG,6);
							break;
				case EXTI_Rising:
							SET_BIT(REXTI_MCUCSR_REG,6);
					break;
				}
				break;

	}
}

void MEXTI_voidEnable(u8 A_u8EXTI_Line)
{
	switch(A_u8EXTI_Line)
	{
	case EXTI_Line0: SET_BIT(REXTI_GICR_REG,6); break;
	case EXTI_Line1: SET_BIT(REXTI_GICR_REG,7); break;
	case EXTI_Line2: SET_BIT(REXTI_GICR_REG,5); break;
	}


}


void MEXTI_voidDisEnable(u8 A_u8EXTI_Line){

	switch(A_u8EXTI_Line)
		{
		case EXTI_Line0: CLR_BIT(REXTI_GICR_REG,6); break;
		case EXTI_Line1: CLR_BIT(REXTI_GICR_REG,7); break;
		case EXTI_Line2: CLR_BIT(REXTI_GICR_REG,5); break;
		}

		}

/*void __vector_1 (void)		__attribute__ ((signal));

void __vector_1 (void)
{
	if (global_u8Flag==0)
		{
			MDIO_voidSetPinValue(PORTD,PIN0,LOW);
			global_u8Flag=1;
		}
		else
		{
			MDIO_voidSetPinValue(PORTD,PIN0,HIGH);
			global_u8Flag=0;
		}
}*/
