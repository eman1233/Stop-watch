/*
 * Genral_InterruptMemMap.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: inter
 */

#ifndef GENRAL_INTERRUPTMEMMAP_H_
#define GENRAL_INTERRUPTMEMMAP_H_

#include "Platform_Types.h"

#define SREG_REG              *((volatile u8*)0X5F)

#define I_bit  7

#define READ_BIT(PORT,BIT)    ((PORT>>BIT)&1)
#define SET_BIT(PORT,BIT)    (PORT=PORT|(1<<BIT))
#define CLEAR_BIT(PORT,BIT)  (PORT&=~(1<<BIT))
#define TOGGLE_BIT(PORT,BIT) (PORT^=(1<<BIT))
#endif /* GENRAL_INTERRUPTMEMMAP_H_ */
