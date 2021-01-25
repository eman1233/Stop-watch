/*
 * Keypad.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: inter
 */

#include "Platform_Types.h"
#include "Keypad.h"
#include "Dio.h"
#include "Keypad_Cfg.h"

/*extern const Dio_LevelType RowStatusHigh[];
extern const Dio_LevelType RowStatusLow[];
extern u8 KeypadValue[4][4];
extern Dio_LevelType ColStatus[4];*/
/*Std_ReturnType GetKeyState (u8 * ReturnedSwitch)
{
	Row_t Row;
	Col_t Col;
	Std_ReturnType Return=E_OK;
	Dio_LevelType PinValue;
	u8 flag=0;
	if(ReturnedSwitch==NULL)
	{
		Return=E_NOT_OK;
	}
	else
	{
		* ReturnedSwitch=KeyNotPressed;
		for(Row=row1;Row<=row4;Row++)
		{
			Dio_WriteChannel(Row,RowStatusLow[Row]);
			for(Col=col1;Col<=col4;Col++)
			{
				ColStatus[Col]=Dio_ReadChannel(Col);
				if(PinValue==STD_LOW)
				{
					*ReturnedSwitch=KeypadValue[Row][Col];
					while(Dio_ReadChannel(PinValue)==STD_LOW)
					{
						PinValue=Dio_ReadChannel(ColStatus[Col]);
					}
					flag=1;
					break;
				}
			}
			Dio_WriteChannel(Row,RowStatusHigh[Row]);
			if(flag==1)
			{
				break;
			}
		}
	}
	return Return;
}*/

/*Std_ReturnType GetKeyState (u8 * ReturnedSwitch)
{
	Std_ReturnType Return =E_OK;
   Dio_LevelType PinValue;
	u8 c=0;
	u8 r=0;
	u8 flag=0;
	extern u8 RowArr[NumRow];
	extern u8 ColArr[NumCol];
	extern u8 KeypadValue[NumRow][NumCol];
	if(ReturnedSwitch!=NULL)
	{
		*ReturnedSwitch=KeyNotPressed;
		for(r =0;r<NumRow;r++)
		{

			Dio_WriteChannel(RowArr[r],STD_LOW);
			for(c=0;c<NumCol;c++)
			{
				PinValue=Dio_ReadChannel(ColArr[c]);
				if(PinValue==STD_LOW)
				{
					*ReturnedSwitch=KeypadValue[r][c];
					while(PinValue==STD_LOW);

				    {
						PinValue=Dio_ReadChannel(ColArr[c]);
					}
					flag=1;
					break;
				}
			}
				Dio_WriteChannel(RowArr[r],STD_HIGH);
				if(flag==1)
					break;
		}
	}
	else
		Return=E_NOT_OK;

	return  Return;
}*/

u8 GetKeyState (void)
{
	u8 c=0;
	u8 r=0;
	u8 Key=KeyNotPressed;

	extern u8 RowArr[NumRow];
	extern u8 ColArr[NumCol];
	extern u8 KeypadValue[NumRow][NumCol];

		for(r =0;r<NumRow;r++)
		{

			Dio_WriteChannel(RowArr[r],STD_LOW);
			for(c=0;c<NumCol;c++)
			{
				if(Dio_ReadChannel(ColArr[c])==STD_LOW)
				{
					Key=KeypadValue[r][c];
					while(Dio_ReadChannel(ColArr[c])==STD_LOW);

				}
			}
			Dio_WriteChannel(RowArr[r],STD_HIGH);

		}

		return Key;

}

/*u8 * GetPassword(void)
{
	static u8 Pass[4];
	u8 i=0;
	for(i=0;i<4;i++)
	{
		Pass[i]=GetKeyState ();
	}
	return Pass;
}*/
