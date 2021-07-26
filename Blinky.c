/*----------------------------------------------------------------------------
 * Name:    Blinky.c
 * Purpose: LED Flasher and Graphic Demo
 * Note(s): 
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2008-2011 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/
                  
#include <LPC17xx.H>                    /* NXP LPC17xx definitions            */
#include "string.h"
#include "GLCD.h"
#include "LED.h"

extern unsigned char ClockLEDOn;
extern unsigned char ClockLEDOff;
extern unsigned char ClockANI;
extern unsigned char Bg_16bpp_t[];
extern unsigned char Bg_16bpp_l[];
extern unsigned char Bg_16bpp_r[];
extern unsigned char Bg_16bpp_b[];
extern unsigned char ARM_Ani_16bpp[];


/*----------------------------------------------------------------------------
  Main Program
 *----------------------------------------------------------------------------*/
void photoviewer (void) {                       /* Main Program                       */
  int num     = -1; 
  int dir     =  1;
  int pic     =  0;

  LED_Init ();
  GLCD_Init();

  GLCD_Clear  (White);
	
  GLCD_Bitmap (  0,   0, 320,  69, Bg_16bpp_t+70);
  GLCD_Bitmap (  0,  69,   4, 102, Bg_16bpp_l+70);
  GLCD_Bitmap (316,  69,   4, 102, Bg_16bpp_r+70);
  GLCD_Bitmap (  0, 171, 320,  69, Bg_16bpp_b+70);

    }
  }
}
