#include "ADC.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include "LCD.h"
#include "LcdService.h"
#include "Dio.h"
#include "Keypad.h"
#include "Keypad_Cfg.h"
#include "LED_Cfg.h"
#include "LED.h"
#include <string.h>
#include"SevenSegment_Cfg.h"
#include"SevenSegment.h"
#include "motor.h"
#include "Motor_Cfg.h"
#include "ExternalInterrupt.h"
#include "ExternalInterrupt_MemMap.h"
#include "Switch.h"
#include "Switch_Cfg.h"
#include "Genral_Interrupt.h"
#include "Genral_InterruptMemMap.h"
#include "Gpt.h"
#include "Gpt_MemMap.h"

LED_t LED={PINC0_,STD_HIGH};

u8 secInput;
u8 minInput;
u8 hoursInput;
u8 sec;
u8 min;
u8 hours;

void Gpt_CallBackNotifation(void)
{
	sec--;
}
int main(void)
{
	Dio_Init();
	LCD_init();
	Gpt_ConfigType Gpt_Config={Timer0_,Normal,Prescaler64};
	Gpt_Init(&Gpt_Config);
	GenralInterruptEnable();
	Gpt_SetCallBackNormal(&Gpt_CallBackNotifation,Timer0_);
	u8 col=4;
	u8 KeypadInput;
	u8 KeypadInput2;
	u8 KeypadInput3;
	u8 NumInput[100];
	u8 NumInput2[100];
	u8 NumInput3[100];
	u8 i=0;
	u8 j=0;
	u8 x=0;
	u8 y=0;
	u8 a=0;
	u8 b=0;
	u8 base=1;
	u8 base2=1;
	u8 base3=1;
	LCD_WriteString("00:00:00");
	while(1)
	{
		while((KeypadInput!='+'))
		{
			KeypadInput=GetKeyState();
			if(KeypadInput!=KeyNotPressed)
			{

				NumInput[i]=KeypadInput;
				/*LCD_CursorMove(1,col);
				LCD_WriteData(KeypadInput);
				col++;*/
				i++;

			}
		}
		for(j=i-1;j>0;j--)
		{


			secInput+=(NumInput[j-1]-48)*base;
			base=base*10;
	    }
		LCD_CursorMove(1,6);
		LCD_WriteNum_2D(secInput);
		break;
	}
	//col=2;
	while(1)
	{
		while((KeypadInput2!='-'))
		{
			KeypadInput2=GetKeyState();
			if(KeypadInput2!=KeyNotPressed)
			{

				NumInput2[x]=KeypadInput2;
				/*LCD_CursorMove(1,col);
				LCD_WriteData(KeypadInput2);
				col++;*/
				x++;

			}
		}
		for(y=x-1;y>0;y--)
		{


			minInput+=(NumInput2[y-1]-48)*base2;
			base2=base2*10;
	    }
		LCD_CursorMove(1,3);
		LCD_WriteNum_2D(minInput);
		break;
	}

	while(1)
	{
		while((KeypadInput3!='*'))
		{
			KeypadInput3=GetKeyState();
			if(KeypadInput3!=KeyNotPressed)
			{

				NumInput3[a]=KeypadInput3;
				/*LCD_CursorMove(1,col);
				LCD_WriteData(KeypadInput3);
				col++;*/
				a++;

			}
		}
		for(b=a-1;b>0;b--)
		{


			hoursInput+=(NumInput3[b-1]-48)*base3;
			base3=base3*10;
	    }
		LCD_CursorMove(1,0);
		LCD_WriteNum_2D(hoursInput);
		break;
	}
	sec=secInput;
	min=minInput;
	hours=hoursInput;
	while(1)
	{
		Gpt_StartTimer(Timer0_,100000);
		Gpt_EnableNotification(Timer0_);
		LCD_CursorMove(1,6);
		LCD_WriteNum_2D(sec);
		LCD_CursorMove(1,0);
		LCD_WriteNum_2D(hours);
		LCD_WriteData(':');
		LCD_WriteNum_2D(min);
		LCD_WriteData(':');
		//LCD_WriteNum_2D(sec);
		if(sec==0)
		{
			min--;
			sec=60;
		}
		if(min==0)
		{
			hours--;
			min=60;
		}
		if((hours==0)&&(min==1)&&(sec==1))
		{
			break;
		}
	}
	hours=0;
	min=0;
	sec=0;
	LCD_CursorMove(1,6);
	LCD_WriteNum_2D(sec);
	LCD_CursorMove(1,0);
	LCD_WriteNum_2D(hours);
	LCD_WriteData(':');
	LCD_WriteNum_2D(min);
	LCD_WriteData(':');


	return 0;
}

