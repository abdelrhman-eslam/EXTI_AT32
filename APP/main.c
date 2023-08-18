/*
 * main.c
 *
 *  Created on: Aug 13, 2023
 *      Author: ENG.AbdelrhmanEslam
 */

#include "../MCAL/EXTI/GIE_Init.h"
#include "../MCAL/EXTI/EXTI_Init.h"
#include <util/delay.h>

volatile u8 global_u8Flag;

void main() {

	MDIO_voidSetPinDirection(PORTD,PIN2, INPUT);
	MDIO_voidSetPinDirection(PORTD,PIN0, OUTPUT);
	MDIO_voidSetPinValue(PORTD, PIN2, HIGH);

	MGIR_voidEnable();
	MEXTI_voidSenseControl(EXTI_Line0, EXTI_Falling);
	MEXTI_voidEnable(EXTI_Line0);


	while(1){

	}

}



void __vector_1 (void) __attribute__ ((signal));

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
}

