/*
 * LCD_Cfg.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: inter
 */

#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#define BIT_4_MODE 0

#define BIT_8_MODE 1


#define LcdMode  BIT_4_MODE

#define RS PINB0

#define RW PINB1

#define E  PINB2

#if LcdMode==BIT_8_MODE

   #define PORTLCD PA

#elif LcdMode==BIT_4_MODE

   #define D4  PINA4

   #define D5  PINA5

   #define D6  PINA6

   #define D7  PINA7

#endif

#endif /* LCD_CFG_H_ */
