/*
 * Keypad_Lcfg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: inter
 */

#include "Keypad.h"
#include "Dio.h"
#include "Platform_Types.h"
#include "Keypad_Cfg.h"
/*const Dio_LevelType RowStatusLow[4]=
{
		STD_LOW,STD_LOW,STD_LOW,STD_LOW,
};
const Dio_LevelType RowStatusHigh[4]=
{
		STD_HIGH,STD_HIGH,STD_HIGH,STD_HIGH,
};*/
/*const Dio_LevelType ColStatus[4]=
{
		STD_LOW,STD_LOW,STD_LOW,STD_LOW,
};*/
Dio_LevelType ColStatus[4];
u8 KeypadValue[4][4]=
{
		{'7','8','9','/'},
	    {'4','5','6','*'},
		{'1','2','3','-'},
        {'o','0','=','+'}
};

 u8 RowArr[NumRow]={row1,row2,row3,row4};
 u8 ColArr[NumCol]={col1,col2,col3,col4};
