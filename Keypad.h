/*
 * Keypad.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: inter
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "Std_Types.h"
typedef enum
{
	zero=0,one,two,three,
	four,five,six,
	seven,eight,nine,
}Button_t;

typedef enum
{
	row1=1,
	row2,
	row3,
	row4
}Row_t;

typedef enum
{
	col1=1,
	col2,
	col3,
	col4
}Col_t;


//Std_ReturnType GetKeyState (u8 * ReturnedSwitch);

//u8 GetKeyState (u8 * ReturnedSwitch);

u8 GetKeyState (void);


#endif /* KEYPAD_H_ */
