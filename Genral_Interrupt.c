/*
 * Genral_Interrupt.c
 *
 *  Created on: ??�/??�/????
 *      Author: inter
 */

#include "Genral_InterruptMemMap.h"
#include "Genral_Interrupt.h"

void GenralInterruptEnable(void)
{
	SET_BIT(SREG_REG,I_bit);
}

void GenralInterruptDisable(void)
{
	CLEAR_BIT(SREG_REG,I_bit);
}
